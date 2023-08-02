#pragma once

#include <napi.h>

namespace Utils {
    bool isTensor(const Napi::Value& value);
}
