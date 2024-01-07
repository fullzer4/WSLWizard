#include "tensor_utils.h"

namespace TensorUtils {

napi_value CreateTensorWrapper(napi_env env, torch::Tensor tensor) {
  TensorWrapper* wrapper = new TensorWrapper(tensor);

  napi_value result;
  napi_create_external(env, wrapper, nullptr, nullptr, &result);

  return result;
}

torch::Tensor GetTensorFromWrapper(napi_env env, napi_value value) {
  TensorWrapper* wrapper;
  napi_get_value_external(env, value, reinterpret_cast<void**>(&wrapper));
  return wrapper->tensor;
}

}  // namespace TensorUtils