#include <napi.h>

#include "tensor/tensors.h"
#include "cuda/cuda.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {

    BFloat16Tensor::Init(env, exports);
    BoolTensor::Init(env, exports);
    ByteTensor::Init(env, exports);
    DoubleTensor::Init(env, exports);
    CharTensor::Init(env, exports);
    FloatTensor::Init(env, exports);
    HalfTensor::Init(env, exports);
    IntTensor::Init(env, exports);
    LongTensor::Init(env, exports);
    DoubleTensor::Init(env, exports);
    ShortTensor::Init(env, exports);

    Cuda::Init(env, exports);

    return exports;
}

NODE_API_MODULE(jstorch, InitAll)