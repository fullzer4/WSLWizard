#pragma once

#include <napi.h>
#include <torch/torch.h>

class CharTensor : public Napi::ObjectWrap<CharTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        CharTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;
        torch::Tensor tensor_;

        Napi::Value data(const Napi::CallbackInfo &);
};