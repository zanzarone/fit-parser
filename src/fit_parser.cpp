#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "fit/fit.hpp"
#include "fit/fit_profile.hpp"
#include "fit_parser.hpp"
#include "decode/decoder.hpp" 
#include "encode/encoder.hpp"
#include "configuration/defines.hpp"
#include "configuration/utility.hpp"

Napi::String FITParser::DecodeFileWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 2 || info.Length() > 3 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if( !info[0].IsString() )
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if( !info[1].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    if( info.Length() == 3 ){  
        if( !info[2].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[2].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Function callback = info[1].As<Function>();
    Decoder* asyncWorker = new Decoder(env, filePath, options, callback);
    asyncWorker->Queue();
    std::string msg = "Decoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITParser::DecodeFileAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if( info.Length() < 1 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if( !info[0].IsString() )
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if( info.Length() == 2 ){  
        if( !info[1].IsObject() )
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Decoder* asyncWorker = new Decoder(env, filePath, options);
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::String FITParser::DecodeBufferWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 2 || info.Length() > 3 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if( !info[0].IsBuffer() )
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    if( !info[1].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();
    if( info.Length() == 3 ){  
        if( !info[2].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[2].As<Napi::Object>();
    }
    Buffer<uint8_t> data = info[0].As<Buffer<uint8_t>>();
    Function callback = info[1].As<Function>();
    Decoder* asyncWorker = new Decoder(env, data, options, callback);
    asyncWorker->Queue();
    std::string msg = "Decoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITParser::DecodeBufferAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 1 || info.Length() > 2)
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if( !info[0].IsBuffer() )
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    if( info.Length() == 2 ){  
        if( !info[1].IsObject() )
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Buffer<uint8_t> data = info[0].As<Buffer<uint8_t>>();
    Decoder* asyncWorker = new Decoder(env, data, options);
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::String FITParser::EncodeFileWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 3 || info.Length() > 4 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();

    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();

    if(!info[1].IsString())
        Napi::TypeError::New(env, "Missing json string represent the fit file").ThrowAsJavaScriptException();

    if( !info[2].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();

    if( info.Length() == 4 ){  
        if( !info[3].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[3].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Napi::String jsonString = info[1].As<Napi::String>();
    Function callback = info[2].As<Function>();
    Encoder* asyncWorker = new Encoder(env, filePath, jsonString, options, callback);
    asyncWorker->Queue();
    std::string msg = "Encoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITParser::EncodeFileAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 2 || info.Length() > 3)
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if(!info[1].IsString())
        Napi::TypeError::New(env, "Missing json string of fit file").ThrowAsJavaScriptException();
    if(info.Length() == 3){  
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

Napi::String FITParser::EncodeBufferWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if ( info.Length() < 3 || info.Length() > 4 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    
    if(!info[1].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();

    if( !info[2].IsFunction() )
        Napi::TypeError::New(env, "Invalid/missing callback").ThrowAsJavaScriptException();

    if( info.Length() == 4 ){  
        if( !info[3].IsObject() )
            Napi::TypeError::New(env, "Invalid options parameter").ThrowAsJavaScriptException();
        options = info[3].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Buffer<uint8_t> data = info[1].As<Buffer<uint8_t>>();
    Function callback = info[2].As<Function>();
    Encoder* asyncWorker = new Encoder(env, filePath, data, options, callback);
    asyncWorker->Queue();
    std::string msg = "Encoder queued";
    return String::New(info.Env(),msg.c_str());
}

Napi::Value FITParser::EncodeBufferAsyncWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::Object options = Object::New(env);
    if (info.Length() < 2 )
        Napi::TypeError::New(env, "Wrong parameters number").ThrowAsJavaScriptException();
    if(!info[0].IsString())
        Napi::TypeError::New(env, "Missing file path").ThrowAsJavaScriptException();
    if(!info[1].IsBuffer())
        Napi::TypeError::New(env, "Missing binary fit file").ThrowAsJavaScriptException();
    if( info.Length() == 3 ){  
        if(!info[2].IsObject())
            Napi::TypeError::New(env, "2nd arg must be an object of options").ThrowAsJavaScriptException();
        options = info[1].As<Napi::Object>();
    }
    Napi::String filePath = info[0].As<Napi::String>();
    Buffer<uint8_t> data = info[1].As<Buffer<uint8_t>>();
    Encoder* asyncWorker = new Encoder(env, filePath, data, options);
    auto promise = asyncWorker->GetPromise();
    asyncWorker->Queue();
    return promise;
}

Napi::Object FITParser::FitDefinesWrapped(Napi::Env env)
{
    Object fitBaseTypes = Object::New(env);
    fitBaseTypes.Set("FIT_ENUM_INVALID", FIT_ENUM_INVALID);
    fitBaseTypes.Set("FIT_SINT8_INVALID", FIT_SINT8_INVALID);
    fitBaseTypes.Set("FIT_UINT8_INVALID", FIT_UINT8_INVALID);
    fitBaseTypes.Set("FIT_SINT16_INVALID", FIT_SINT16_INVALID);
    fitBaseTypes.Set("FIT_UINT16_INVALID", FIT_UINT16_INVALID);
    fitBaseTypes.Set("FIT_SINT32_INVALID", FIT_SINT32_INVALID);
    fitBaseTypes.Set("FIT_UINT32_INVALID", FIT_UINT32_INVALID);
    fitBaseTypes.Set("FIT_STRING_INVALID", FIT_STRING_INVALID);
    fitBaseTypes.Set("FIT_FLOAT32_INVALID", FIT_FLOAT32_INVALID);
    fitBaseTypes.Set("FIT_FLOAT64_INVALID", FIT_FLOAT64_INVALID);
    fitBaseTypes.Set("FIT_UINT8Z_INVALID", FIT_UINT8Z_INVALID);
    fitBaseTypes.Set("FIT_UINT16Z_INVALID", FIT_UINT16Z_INVALID);
    fitBaseTypes.Set("FIT_UINT32Z_INVALID", FIT_UINT32Z_INVALID);
    fitBaseTypes.Set("FIT_BYTE_INVALID", FIT_BYTE_INVALID);
    fitBaseTypes.Set("FIT_SINT64_INVALID", FIT_SINT64_INVALID);
    fitBaseTypes.Set("FIT_UINT64_INVALID", FIT_UINT64_INVALID);
    fitBaseTypes.Set("FIT_UINT64Z_INVALID", FIT_UINT64Z_INVALID);
    //
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
    Object defines = Object::New(env);
    defines.Set("FIT_BASE_TYPES", fitBaseTypes);
    defines.Set("FIT_MESG_NUM", msgsNum);
    defines.Set("SYSTEM_TIME_OFFSET_SEC", Napi::Number::New(env, SYSTEM_TIME_OFFSET_SEC));
    return defines;
}

Napi::String FITParser::FitModuleVersion(Napi::Env env)
{
    return Napi::String::New(env, VERSION);
}

Napi::Number FITParser::FitModuleDegreeToSemicircles(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    if(!info[0].IsNumber())
        Napi::TypeError::New(env, "Not a number").ThrowAsJavaScriptException();
    Napi:Number value = info[0].As<Napi::Number>();
    double result = Utility::degreesToSemicircles(value.DoubleValue());
    return Napi::Number::New(env, result);
}

Napi::Number FITParser::FitModuleSemicirclesToDegree(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    if(!info[0].IsNumber())
        Napi::TypeError::New(env, "Not a number").ThrowAsJavaScriptException();
    Napi:Number value = info[0].As<Napi::Number>();
    double result = Utility::semicirclesToDegrees(value.Int32Value());
    return Napi::Number::New(env, result);
}

Napi::Object FITParser::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("version",FITParser::FitModuleVersion(env));
    exports.Set("defines",FITParser::FitDefinesWrapped(env));
    exports.Set("degreesToSemicircles", Napi::Function::New(env, FITParser::FitModuleDegreeToSemicircles) );
    exports.Set("semicirclesToDegrees", Napi::Function::New(env, FITParser::FitModuleSemicirclesToDegree) );
    exports.Set("decodeFile", Napi::Function::New(env, FITParser::DecodeFileWrapped) );
    exports.Set("decodeFileAsync", Napi::Function::New(env, FITParser::DecodeFileAsyncWrapped) );
    exports.Set("decodeBuffer", Napi::Function::New(env, FITParser::DecodeBufferWrapped) );
    exports.Set("decodeBufferAsync", Napi::Function::New(env, FITParser::DecodeBufferAsyncWrapped) );
    exports.Set("encodeJSONToFile", Napi::Function::New(env, FITParser::EncodeFileWrapped) );
    exports.Set("encodeJSONToFileAsync", Napi::Function::New(env, FITParser::EncodeFileAsyncWrapped) );
    exports.Set("encodeBufferToFile", Napi::Function::New(env, FITParser::EncodeBufferWrapped) );
    exports.Set("encodeBufferToFileAsync", Napi::Function::New(env, FITParser::EncodeBufferAsyncWrapped) );
    return exports;
}