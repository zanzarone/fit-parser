#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "fit/fit_profile.hpp"
#include "fit_module.hpp"
#include "decode/decoder.hpp" 
#include "encode/encoder.hpp"
#include "configuration/defines.hpp"
#include "configuration/utility.hpp"

Napi::String FITModule::DecodeFileWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    
    if ( info.Length() < 2 || info.Length() > 3 )
        Napi::TypeError::New(env, "Usage: decodeFile <file_path> <options> <callback_func>").ThrowAsJavaScriptException();
    ///
    if( !info[0].IsString() )
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    Napi::String filePath = info[0].As<Napi::String>();
    ///
    if( !info[1].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    Function callback = info[1].As<Function>();
    ///
    if( info.Length() == 3 ){
        if( !info[2].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[2].As<Napi::Object>();
    }
    Decoder* asyncWorker = new Decoder(env, filePath, options, callback);
    /// decodo il file
    asyncWorker->Queue();
    std::string msg = "Decoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITModule::DecodeFileAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 1 )
        Napi::TypeError::New(env, "Usage: decodeFileAsync <buffer> <options>").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if(!info[1].IsNull()){  
        if(!info[1].IsObject())
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Decoder* asyncWorker = new Decoder(env, filePath, options);
    /// decodo il file
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::String FITModule::DecodeBufferWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 2 || info.Length() > 3 )
        Napi::TypeError::New(env, "Usage: decodeBuffer <buffer> <callback_func>").ThrowAsJavaScriptException();
    if(!info[0].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    Napi::String filePath = info[0].As<Napi::String>();
    ///
    if( !info[1].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    Function callback = info[1].As<Function>();
    ///
    if( info.Length() == 3 ){
        if( !info[2].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[2].As<Napi::Object>();
    }
    Buffer<uint8_t> data = info[0].As<Buffer<uint8_t>>();
    Decoder* asyncWorker = new Decoder(env, data, options , callback);
    // /// decodo il file
    asyncWorker->Queue();
    std::string msg = "Decoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITModule::DecodeBufferAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 1 )
        Napi::TypeError::New(env, "Usage: decodeBufferAsync <buffer> <options>").ThrowAsJavaScriptException();
    if(!info[0].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    if(!info[1].IsNull()){  
        if(!info[1].IsObject())
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Buffer<uint8_t> data = info[0].As<Buffer<uint8_t>>();
    // std::cout << "------->" << options.Get("include").IsArray() << std::endl;
    Decoder* asyncWorker = new Decoder(env, data, options);
    /// decodo il file
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::String FITModule::EncodeFileWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 3 || info.Length() > 4 )
        Napi::TypeError::New(env, "Usage: encodeFile <file_path> <JSON_object_string> <callback_func>").ThrowAsJavaScriptException();
    /// 
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    Napi::String filePath = info[0].As<Napi::String>();
    ///
    if(!info[1].IsString())
        Napi::TypeError::New(env, "Missing json string represent the fit file").ThrowAsJavaScriptException();
    Napi::String jsonString = info[1].As<Napi::String>();
    ///
    if( !info[2].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    Function callback = info[2].As<Function>();
    ///
    if( info.Length() == 4 ){
        if( !info[3].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[3].As<Napi::Object>();
    }
    Encoder* asyncWorker = new Encoder(env, filePath, jsonString, options, callback);
    asyncWorker->Queue();
    std::string msg = "Encoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITModule::EncodeFileAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 2 )
        Napi::TypeError::New(env, "Usage: encodeJSONToFileAsync <file_path> <JSON_object_string>").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if(!info[1].IsString())
        Napi::TypeError::New(env, "Missing json string of fit file").ThrowAsJavaScriptException();
    if(!info[2].IsNull()){  
        if(!info[2].IsObject())
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[2].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Napi::String jsonString = info[1].As<Napi::String>();
    Encoder* asyncWorker = new Encoder(env, filePath, jsonString, options);
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::String FITModule::EncodeBufferWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 3 || info.Length() > 4 )
        Napi::TypeError::New(env, "Usage: encodeBufferToFile <file_path> <buffer> <callback_func>").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    Napi::String filePath = info[0].As<Napi::String>();
    if(!info[1].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    Buffer<uint8_t> data = info[1].As<Buffer<uint8_t>>();
    ///
    if( !info[2].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    Function callback = info[2].As<Function>();
    ///
    if( info.Length() == 4 ){
        if( !info[3].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[3].As<Napi::Object>();
    }
    Encoder* asyncWorker = new Encoder(env, filePath, data, options, callback);
    asyncWorker->Queue();
    std::string msg = "Encoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITModule::EncodeBufferAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 2 )
        Napi::TypeError::New(env, "Usage: encodeBufferToFileAsync <file_path> <buffer>").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    Napi::String filePath = info[0].As<Napi::String>();
    if(!info[1].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    Buffer<uint8_t> data = info[1].As<Buffer<uint8_t>>();
    if(!info[2].IsNull()){  
        if(!info[2].IsObject())
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Encoder* asyncWorker = new Encoder(env, filePath, data, options);
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::Object FITModule::FitDefinesWrapped(Napi::Env env)
{
    ///
    Object msgsNum = Object::New(env);
    auto mesgs = fit::Profile::mesgs;
    int length = fit::Profile::MESG_INDEX::MESGS ;
    for (int i = 0; i < length; i++) {
        std::string data = mesgs[i].name;
        std::for_each(data.begin(), data.end(), [](char & c){
            c = ::toupper(c);
        });
        msgsNum.Set(data, mesgs[i].num);
    }
    /// 
    Object defines = Object::New(env);
    defines.Set("FIT_MESG_NUM", msgsNum);
    defines.Set("SYSTEM_TIME_OFFSET_SEC", Napi::Number::New(env, SYSTEM_TIME_OFFSET_SEC));
    return defines;
}

Napi::String FITModule::FitModuleVersion(Napi::Env env)
{
    return Napi::String::New(env, VERSION);
}

Napi::Object FITModule::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("version",FITModule::FitModuleVersion(env));
    exports.Set("defines",FITModule::FitDefinesWrapped(env));
    exports.Set("decodeFile", Napi::Function::New(env, FITModule::DecodeFileWrapped) );
    exports.Set("decodeFileAsync", Napi::Function::New(env, FITModule::DecodeFileAsyncWrapped) );
    exports.Set("decodeBuffer", Napi::Function::New(env, FITModule::DecodeBufferWrapped) );
    exports.Set("decodeBufferAsync", Napi::Function::New(env, FITModule::DecodeBufferAsyncWrapped) );
    exports.Set("encodeBufferToFile", Napi::Function::New(env, FITModule::EncodeBufferWrapped) );
    exports.Set("encodeBufferToFileAsync", Napi::Function::New(env, FITModule::EncodeBufferAsyncWrapped) );
    exports.Set("encodeJSONToFile", Napi::Function::New(env, FITModule::EncodeFileWrapped) );
    exports.Set("encodeJSONToFileAsync", Napi::Function::New(env, FITModule::EncodeFileAsyncWrapped) );
    return exports;
}