// hello.cc using N-API
#include <node_api.h>

namespace demo {

napi_value Method(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  status = napi_create_string_utf8(env, "hello", 6, &greeting);
  if (status != napi_ok) return nullptr;
  return greeting;
}


/*
napi_value Method2(napi_env env, napi_callback_info args) {
  napi_value result;
  napi_status status;

  status = napi_create_int32(env, args[0] + args[1], &result);
  if (status != napi_ok) return nullptr;
  return greeting;
}
*/

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;


/*
  napi_value fn2;

  status = napi_create_function(env, nullptr, 0, Method2, nullptr, &fn2);
  if (status != napi_ok) return nullptr;
*/

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return nullptr;
  /*
  status = napi_set_named_property(env, exports, "add", fn2);
  if (status != napi_ok) return nullptr;
  */
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo

