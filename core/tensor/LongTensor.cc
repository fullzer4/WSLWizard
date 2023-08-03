#include "LongTensor.h"

Napi::FunctionReference LongTensor::constructor;

Napi::Object LongTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "LongTensor", {
        InstanceMethod("data", &LongTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("LongTensor", func);

    return exports;
}

LongTensor::LongTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<LongTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value LongTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
