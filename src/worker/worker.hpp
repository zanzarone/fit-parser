#pragma once
#ifndef CODER_H
#define CODER_H
#include <napi.h>
#include <fstream>
#include <strstream>
#include "../configuration/defines.hpp"
#include "../nlohmann/json.hpp"

using namespace Napi;
using JSON = nlohmann::json;

struct MyError {
  StatusCode code;
  std::string message;
} ;

class Worker : public AsyncWorker
{
public:
    enum Source {
        FILE    = 0,
        MEMEORY,
    };
    //
    struct Options {
        std::vector<int> includedTypes = {};
        std::vector<int> excludedTypes = {};
        bool force = false;
        bool skipHeaders = false;
        bool rawValues = false;
    } ;
    // 
    struct FileStream {
        std::fstream * file;
        std::string filePath;
    } ;
    struct BytesStream {
        std::istrstream * bytes;
        ObjectReference dataRef;
        uint8_t *dataPtr;
        size_t dataLength;
    } ;
public:
    Worker(Napi::Env &env, Function &callback, Napi::Object*options = nullptr);
    Worker(Napi::Env &env, Napi::Object*options = nullptr);
    ~Worker() override;
public:
    void SetCustomError(StatusCode code, const std::string& error);
    void SetCustomWarnings(int status, std::string message);
    MyError GetError();
    JSON GetWarnings();
    bool SkipMessage(int mesgNum);
protected:
    void OnOK() override;
    void OnError(const Error& e) override;
    void Destroy() override;
private:
    void AddOptions(Napi::Object*options);
public:
    Napi::Promise GetPromise();
    bool sync;
    Napi::Promise::Deferred deferred;
private:
    MyError error;
    JSON warnings;
    // Napi::Env env;
public:
    Source source;
    FileStream * fileStream;
    BytesStream * bytesStream;
    Options options;
};
#endif // CODER_H
