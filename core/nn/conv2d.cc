#include "conv2d.h"

Napi::Object Conv2d::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Conv2d", {

    });

    exports.Set("Conv2d", func);
    return exports;
}

Conv2d::Conv2d(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Conv2d>(info) {
    Napi::Env env = info.Env();

    if (info.Length() < 3 || !info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsNumber()) {
        Napi::TypeError::New(env, "Expected 3 numeric arguments").ThrowAsJavaScriptException();
        return;
    }

    int in_channels = info[0].As<Napi::Number>().Int32Value();
    int out_channels = info[1].As<Napi::Number>().Int32Value();
    int kernel_size = info[2].As<Napi::Number>().Int32Value();

    conv2d = torch::nn::Conv2d(torch::nn::Conv2dOptions(in_channels, out_channels, kernel_size));
}