#include "tensor.h"

Napi::Value TensorBase::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Array dataArr = Napi::Array::New(env);

    torch::Tensor tensor = _value.contiguous().cpu();
    int64_t numel = tensor.numel();
    auto data_ptr = tensor.data_ptr<float>();

    for (int64_t i = 0; i < numel; i++) {
        dataArr.Set(i, Napi::Number::New(env, data_ptr[i]));
    }

    return dataArr;
}