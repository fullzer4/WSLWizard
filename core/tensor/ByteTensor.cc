#include "ByteTensor.h"

Napi::FunctionReference ByteTensor::constructor;

Napi::Object ByteTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "ByteTensor", {
        InstanceMethod("data", &ByteTensor::data),
    });

    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("ByteTensor", func);

    return exports;
}

ByteTensor::ByteTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ByteTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value ByteTensor::data(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::Number::New(env, 42); // Teste
}
