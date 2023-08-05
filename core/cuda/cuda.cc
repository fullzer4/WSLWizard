#include "cuda.h"

Napi::FunctionReference Cuda::constructor;

Napi::Object Cuda::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Cuda", {
        InstanceMethod("is_available", &Cuda::IsAvailable),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Cuda", func);
    return exports;
}

Cuda::Cuda(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Cuda>(info) {}

Napi::Value Cuda::IsAvailable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, torch::cuda::is_available());
}
