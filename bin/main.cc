#include <node_api.h>
#include <torch/torch.h>

#include "tensor.cc"

namespace jsTorch {

napi_value Version(napi_env env, napi_callback_info info) {
  const char* addonVersion = "1.0.0";

  napi_value version;
  napi_create_string_utf8(env, addonVersion, NAPI_AUTO_LENGTH, &version);
  return version;
}

napi_value Initialize(napi_env env, napi_value exports) {
  napi_property_descriptor desc = {"version", nullptr, Version, nullptr, nullptr, nullptr, napi_default, nullptr};
  napi_define_properties(env, exports, 1, &desc);

  Init(env, exports);

  return exports;
}

NAPI_MODULE(jsTorch, Initialize)

}  // namespace jsTorch
