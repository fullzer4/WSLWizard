#define NAPI_VERSION 3
#include <napi.h>
#include "tensor.h"
#include "utils.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    TensorBase::Init(env, exports);
    DoubleTensor::Init(env, exports);
    FloatTensor::Init(env, exports);
    HalfTensor::Init(env, exports);

    exports.Set("isTensor", Napi::Function::New(env, [](const Napi::CallbackInfo& info) -> Napi::Value {
        return Napi::Boolean::New(info.Env(), Utils::isTensor(info[0]));
    }));
    
    return exports;
}

NODE_API_MODULE(jstorchcore, InitAll)