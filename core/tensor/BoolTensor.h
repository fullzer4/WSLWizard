#pragma once

#include <napi.h>
#include <torch/torch.h>

class BoolTensor : public Napi::ObjectWrap<BoolTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        BoolTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;

        Napi::Value data(const Napi::CallbackInfo &);
};