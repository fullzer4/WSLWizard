#include "utils.h"
#include "tensor.h"

bool Utils::isTensor(const Napi::Value& value) {
    if (!value.IsObject()) {
        return false;
    }

    Napi::Object obj = value.As<Napi::Object>();
    return obj.InstanceOf(TensorBase::constructor.Value());
}