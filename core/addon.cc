#define NAPI_VERSION 3
#include <napi.h>
#include "tensor/tensor.cc"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    DoubleTensor::Init(env, exports);
    FloatTensor::Init(env, exports);
    HalfTensor::Init(env, exports);

    return exports;
}

NODE_API_MODULE(jstorchcore, InitAll)