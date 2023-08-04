#include "cuda.h"

Napi::Boolean IsCudaAvailable(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Boolean::New(env, torch::cuda::is_available());
}