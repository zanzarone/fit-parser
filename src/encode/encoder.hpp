
#pragma once
#ifndef ENCODER_H
#define ENCODER_H

#include <napi.h>
#include "../configuration/defines.hpp"
#include "../worker/worker.hpp"
#include "../fit/fit_encode.hpp"

using namespace Napi;

class Encoder : public Worker
{
public:
    Encoder(Napi::Env &env,std::string filePath, std::string jsonFileString, Object&options, Function& callback);
    Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options, Function& callback);
    Encoder(Napi::Env &env,std::string filePath, std::string jsonFileString, Object&options);
    Encoder(Napi::Env &env,std::string filePath, Buffer<uint8_t> &data, Object&options);
    ~Encoder();
    // void OnWorkComplete(Napi::Env env, napi_status status) override;
    
protected:
    void OnOK();
    void OnError(const Error& e);
    void Destroy();    

private:
    void EnumerateFields(fit::Mesg * fitMesg, JSON fields);

public:
    void Execute();
private:
    std::string jsonFileString;
    std::string filePath;
};


#endif // ENCODER_H
