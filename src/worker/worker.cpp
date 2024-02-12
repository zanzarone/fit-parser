#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "worker.hpp"
#include "../configuration/utility.hpp"

Worker::Worker(Napi::Env &env, Function &callback, Napi::Object*options) : AsyncWorker(callback), sync(false), deferred(Napi::Promise::Deferred::New(env))
{
    this->warnings = JSON::array();
    this->AddOptions(options);
}

Worker::Worker(Napi::Env &env, Napi::Object*options) : AsyncWorker(env),  sync(true), deferred(Napi::Promise::Deferred::New(env))
{
    this->warnings = JSON::array();
    this->AddOptions(options);
}

void Worker::AddOptions(Napi::Object*options) 
{
    if(!options || options->IsNull() || options->IsEmpty()){
        return;
    }
    if(options->HasOwnProperty("skipHeaders") && options->Get("skipHeaders").IsBoolean()){ //std::cout << "SKIP ()" << std::endl;
        this->options.skipHeaders = options->Get("skipHeaders").ToBoolean();
    }
    if(options->HasOwnProperty("force") && options->Get("force").IsBoolean()){ //std::cout << "FORCE ()" << std::endl;
        this->options.force = options->Get("force").ToBoolean();
    }
    if(options->HasOwnProperty("rawValues") && options->Get("rawValues").IsBoolean()){ //std::cout << "FORCE ()" << std::endl;
        this->options.rawValues = options->Get("rawValues").ToBoolean();
    }
    if(options->HasOwnProperty("include") && options->Get("include").IsArray()){ //std::cout << "INCLUDE ()" << std::endl;
        Array types = options->Get("include").As<Array>();
        int length = (int)types.Length();
        for (int i = 0; i < length; i++){
            Napi::Value value = static_cast<Napi::Value>(types[i]);
            if(!value.IsNull() && value.IsNumber()) {
                this->options.includedTypes.push_back(value.ToNumber());
            }
        }
    }
    if(options->HasOwnProperty("exclude") && options->Get("exclude").IsArray()){ //std::cout << "EXCLUDE ()" << std::endl;
        Array types = options->Get("exclude").As<Array>();
        int length = (int)types.Length();
        for (int i = 0; i < length; i++){
            Napi::Value value = static_cast<Napi::Value>(types[i]);
            if(!value.IsNull() && value.IsNumber()){
                this->options.excludedTypes.push_back(value.ToNumber());
            }
        }
    }
    if(options->HasOwnProperty("version") && options->Get("version").IsNumber()){ //std::cout << "FORCE ()" << std::endl;
        uint32_t v = options->Get("version").ToNumber().Uint32Value();
        fit::ProtocolVersion ver = (fit::ProtocolVersion)v;
        switch (ver)
        {
            case fit::ProtocolVersion::V10:
            case fit::ProtocolVersion::V20:
                this->options.protoVersion = ver;
                break;
            default:
                this->options.protoVersion = fit::ProtocolVersion::V20;
                break;
        }
    }
}

Worker::~Worker() {
    // std::cout << "~Worker()" << std::endl;
}

void Worker::OnOK(){
    // std::cout << "Worker OnOK()" << std::endl;
}

void Worker::OnError(const Error& e){
    // std::cout << "Worker OnError()" << std::endl;
}

void Worker::Destroy(){
    // std::cout << "Worker Destroy()" << std::endl;
    AsyncWorker::Destroy();
}

Napi::Promise Worker::GetPromise() { 
    return deferred.Promise(); 
}


void Worker::SetCustomError(StatusCode code, const std::string& error)
{
    this->error.code = code;
    this->error.message = error;
}

void Worker::SetCustomWarnings(int status, std::string message)
{
    JSON warning = {{"code", status}, {"message", message}};
    this->warnings.push_back(warning);
}

MyError Worker::GetError()
{
    return this->error;
}

JSON Worker::GetWarnings()
{
    return this->warnings;
}

bool Worker::SkipMessage(int mesgNum)
{
    if(!this->options.includedTypes.empty())
    {
        auto found = std::find(this->options.includedTypes.begin(), this->options.includedTypes.end(), mesgNum);
        if(found == this->options.includedTypes.end())
            return true;
        
    }
    if(!this->options.excludedTypes.empty())
    {
        auto found = std::find(this->options.excludedTypes.begin(), this->options.excludedTypes.end(), mesgNum);
        if(found != this->options.excludedTypes.end())
            return true;
    }
    return false;
}
