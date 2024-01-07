#include <node_api.h>
#include "tensor_utils.h"
#include "base_tensor.h"
#include "int_tensor.h"

namespace {

napi_value Ones(napi_env env, napi_callback_info info) {
  size_t argc = 2;
  napi_value argv[2];
  napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);

  if (argc != 2) {
    napi_throw_type_error(env, nullptr, "Argumentos incorretos. Uso: ones(rows, cols)");
    return nullptr;
  }

  int32_t rows, cols;
  napi_get_value_int32(env, argv[0], &rows);
  napi_get_value_int32(env, argv[1], &cols);

  IntTensor intTensor(torch::ones({rows, cols}, torch::kInt32));

  napi_value result = TensorUtils::CreateTensorWrapper(env, intTensor.getTensor());

  return result;
}

napi_value InitOnes(napi_env env, napi_value exports) {
  napi_property_descriptor desc = {"ones", nullptr, Ones, nullptr, nullptr, nullptr, napi_default, nullptr};
  napi_define_properties(env, exports, 1, &desc);

  return exports;
}

}  // namespace
