#pragma once

#include <napi.h>
#include <torch/torch.h>

class LongTensor : public Napi::ObjectWrap<LongTensor> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        LongTensor(const Napi::CallbackInfo &);

    private:
        static Napi::FunctionReference constructor;

        Napi::Value data(const Napi::CallbackInfo &);
};