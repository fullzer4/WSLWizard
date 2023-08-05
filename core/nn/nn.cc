#include "nn.h"

Napi::Object NN::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "NN", {
        
    });

    exports.Set("NN", func);
    return exports;
}

NN::NN(const Napi::CallbackInfo& info) : Napi::ObjectWrap<NN>(info) {
    
}

torch::Tensor NN::forward(torch::Tensor x) {
    
    return x;
}
