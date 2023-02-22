#include <napi.h>
#include "fit_module.hpp"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return FITModule::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
