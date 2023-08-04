#include "tensors.h"

#define TENSOR_CLASS(NAME, TORCH_TYPE, NAPI_TYPE) \
Napi::FunctionReference NAME::constructor; \
\
Napi::Object NAME::Init(Napi::Env env, Napi::Object exports) { \
    Napi::Function func = DefineClass(env, #NAME, { InstanceMethod("data", &NAME::data), }); \
    constructor = Napi::Persistent(func); \
    constructor.SuppressDestruct(); \
    exports.Set(#NAME, func); \
    return exports; \
} \
\
NAME::NAME(const Napi::CallbackInfo& info) : Napi::ObjectWrap<NAME>(info) { \
    Napi::Env env = info.Env(); \
    if (info.Length() == 0 || !info[0].IsArray()) { \
        Napi::TypeError::New(env, "Um array é esperado como argumento").ThrowAsJavaScriptException(); \
        return; \
    } \
    Napi::Array dataArray = info[0].As<Napi::Array>(); \
    size_t size = dataArray.Length(); \
    torch::TensorOptions options = torch::TensorOptions().dtype(TORCH_TYPE); \
    tensor_ = torch::empty({static_cast<long>(size)}, options); \
    for (size_t i = 0; i < size; i++) { \
        tensor_[i] = static_cast<NAPI_TYPE>(dataArray.Get(i).ToNumber().FloatValue()); \
    } \
} \
\
Napi::Value NAME::data(const Napi::CallbackInfo& info) { \
    Napi::Env env = info.Env(); \
    torch::Tensor tensor = this->tensor_; \
    size_t size = tensor.numel(); \
    Napi::Array dataArray = Napi::Array::New(env, size); \
    for (size_t i = 0; i < size; i++) { \
        dataArray.Set(i, Napi::Number::New(env, static_cast<double>(tensor[i].item<NAPI_TYPE>()))); \
    } \
    return dataArray; \
}

TENSOR_CLASS(BFloat16Tensor, torch::kBFloat16, float)
TENSOR_CLASS(BoolTensor, torch::kBool, bool)
TENSOR_CLASS(FloatTensor, torch::kFloat32, float)
TENSOR_CLASS(DoubleTensor, torch::kFloat64, double)
TENSOR_CLASS(HalfTensor, torch::kFloat16, float)
TENSOR_CLASS(CharTensor, torch::kInt8, int8_t)
TENSOR_CLASS(IntTensor, torch::kInt32, int32_t)
TENSOR_CLASS(ByteTensor, torch::kUInt8, uint8_t)
TENSOR_CLASS(LongTensor, torch::kInt64, int64_t)
TENSOR_CLASS(ShortTensor, torch::kInt16, int16_t)