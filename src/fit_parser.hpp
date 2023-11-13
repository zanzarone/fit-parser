#include <napi.h>

namespace FITParser
{
    /// Decode FIT from a File
    Napi::String DecodeFileWrapped(const Napi::CallbackInfo& info);
    Napi::Value DecodeFileAsyncWrapped(const Napi::CallbackInfo& info);
    /// Decode FIT from a Buffer
    Napi::String DecodeBufferWrapped(const Napi::CallbackInfo& info);
    Napi::Value DecodeBufferAsyncWrapped(const Napi::CallbackInfo& info);
    /// Encode FIT from a File
    Napi::String EncodeFileWrapped(const Napi::CallbackInfo& info);
    Napi::Value EncodeFileAsyncWrapped(const Napi::CallbackInfo& info);
    /// Encode FIT from a Buffer
    Napi::String EncodeBufferWrapped(const Napi::CallbackInfo& info);
    Napi::Value EncodeBufferAsyncWrapped(const Napi::CallbackInfo& info);
    /// N-API Export DEFINES
    Napi::Object FitDefinesWrapped(Napi::Env env);
    /// N-API Export Version
    Napi::String FitModuleVersion(Napi::Env env);
    // 
    Napi::Number FitModuleSemicirclesToDegree(const Napi::CallbackInfo& info);
    Napi::Number FitModuleDegreeToSemicircles(const Napi::CallbackInfo& info);
    /// N-API INITIALIZE
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}
