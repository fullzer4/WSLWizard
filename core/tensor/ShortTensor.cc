#include "ShortTensor.h"

Napi::Object ShortTensor::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "ShortTensor", {
        InstanceMethod("getTensor", &ShortTensor::GetTensor)
    });
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("ShortTensor", func);
    return exports;
}

ShortTensor::DoubleTensor(const Napi::CallbackInfo& info) : Napi::ObjectWrap<ShortTensor>(info) {
    // Construir o tensor aqui com base nos argumentos passados para o construtor (se houver)
}

Napi::Value ShortTensor::GetTensor(const Napi::CallbackInfo& info) {
    // Implementar a lógica para retornar o tensor como um valor Napi aqui
}