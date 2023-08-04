#pragma once

#include <napi.h>
#include <torch/torch.h>

class BFloat16Tensor : public Napi::ObjectWrap<BFloat16Tensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        BFloat16Tensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;
        torch::Tensor tensor_;

        Napi::Value data(const Napi::CallbackInfo &);
};