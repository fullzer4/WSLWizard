#pragma once

#include <napi.h>
#include <torch/torch.h>

Napi::Value LoadModel(const Napi::CallbackInfo& info);