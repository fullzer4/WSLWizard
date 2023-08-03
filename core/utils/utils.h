#pragma once

#include <napi.h>
#include <torch/script.h>

Napi::Value TensorToNapiArray(Napi::Env env, torch::Tensor tensor);
torch::Tensor NapiArrayToTensor(Napi::Value value);