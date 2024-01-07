#pragma once

#include <node_api.h>
#include <torch/torch.h>

namespace TensorUtils {

struct TensorWrapper {
  torch::Tensor tensor;

  TensorWrapper(torch::Tensor t) : tensor(t) {}
};

napi_value CreateTensorWrapper(napi_env env, torch::Tensor tensor);

torch::Tensor GetTensorFromWrapper(napi_env env, napi_value value);

}  // namespace TensorUtils