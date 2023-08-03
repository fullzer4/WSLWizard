#include "CharTensor.h"

Napi::Object CharTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "CharTensor", {
        InstanceMethod("getTensor", &CharTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CharTensor", func);
    return exports;
}

CharTensor::CharTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<CharTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value CharTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implemente a lógica para retornar o tensor como um valor Napi aqui
}