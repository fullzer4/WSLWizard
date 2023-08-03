#include "FloatTensor.h"

Napi::Object FloatTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "FloatTensor", {
        InstanceMethod("getTensor", &FloatTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("FloatTensor", func);
    return exports;
}

FloatTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<FloatTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value FloatTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implementar a lógica para retornar o tensor como um valor Napi aqui
}