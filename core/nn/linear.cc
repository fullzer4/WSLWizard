#include "linear.h"

Napi::Object Linear::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Linear", {

    });

    exports.Set("Linear", func);
    return exports;
}

Linear::Linear(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Linear>(info) {
    int64_t in_features = info[0].As<Napi::Number>().Int64Value();
    int64_t out_features = info[1].As<Napi::Number>().Int64Value();
    
    layer = torch::nn::Linear(in_features, out_features);
}

torch::Tensor Linear::forward(torch::Tensor x) {
    return layer->forward(x);
}