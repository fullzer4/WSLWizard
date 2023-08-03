#include "CharTensor.h"

Napi::FunctionReference CharTensor::constructor;

Napi::Object CharTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "CharTensor", {
        InstanceMethod("data", &CharTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CharTensor", func);

    return exports;
}

CharTensor::CharTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<CharTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value CharTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
