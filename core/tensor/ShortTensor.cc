#include "ShortTensor.h"

Napi::FunctionReference ShortTensor::constructor;

Napi::Object ShortTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "ShortTensor", {
        InstanceMethod("data", &ShortTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("ShortTensor", func);

    return exports;
}

ShortTensor::ShortTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ShortTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value ShortTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
