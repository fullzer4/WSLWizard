#ifndef TENSOR_CLASSES_H
#define TENSOR_CLASSES_H

#include <torch/torch.h>
#include <napi.h>

#define TENSOR_CLASS(NAME, TORCH_TYPE, NAPI_TYPE) \
class NAME : public Napi::ObjectWrap<NAME> { \
public: \
    static Napi::Object Init(Napi::Env env, Napi::Object exports); \
    NAME(const Napi::CallbackInfo& info); \
    Napi::Value data(const Napi::CallbackInfo& info); \
private: \
    static Napi::FunctionReference constructor; \
    torch::Tensor tensor_; \
};

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

#endif