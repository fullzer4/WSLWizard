#include <napi.h>

// tensors
#include "tensor/BFloat16Tensor.h"
#include "tensor/BoolTensor.h"
#include "tensor/ByteTensor.h"
#include "tensor/CharTensor.h"
#include "tensor/DoubleTensor.h"
#include "tensor/FloatTensor.h"
#include "tensor/HalfTensor.h"
#include "tensor/IntTensor.h"
#include "tensor/LongTensor.h"
#include "tensor/ShortTensor.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    // tensors
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

    return exports;
}

NODE_API_MODULE(jstorch, InitAll)