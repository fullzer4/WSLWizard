#pragma once

#include <napi.h>
#include <torch/torch.h>

class FloatTensor : public Napi::ObjectWrap<FloatTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        FloatTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;
        torch::Tensor tensor_;

        Napi::Value data(const Napi::CallbackInfo &);
};