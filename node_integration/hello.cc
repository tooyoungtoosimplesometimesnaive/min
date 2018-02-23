// hello.cc using N-API
#include <node_api.h>
#include <string>

// #include "../min_lexer.h"
// #include "../min_parser.h"
// #include "../min_execution_context.h"
// #include "../min.h"
#include "test_class.h"

namespace demo {

napi_value Method(napi_env env, napi_callback_info args) {
  napi_value greeting;
  napi_status status;

  status = napi_create_string_utf8(env, "hello", 6, &greeting);
  if (status != napi_ok) return nullptr;
  return greeting;
}

napi_value Method2(napi_env env, napi_callback_info args) {
  napi_value result;
  napi_status status;

  napi_value argv[2];
  napi_value thisArg;
  size_t argc = 2;
 
  status = napi_get_cb_info(env, args, &argc, argv, &thisArg, nullptr);
  if (status != napi_ok)
	  return nullptr;
  int num1 = 0, num2 = 0;
  status = napi_get_value_int32(env, argv[0], &num1);
  if (status != napi_ok) {
        napi_throw_error(env, NULL, "Invalid number was passed as argument");
    }
  status = napi_get_value_int32(env, argv[1], &num2);
  if (status != napi_ok) {
        napi_throw_error(env, NULL, "Invalid number was passed as argument");
    }
  int sum = num1 + num2;
  status = napi_create_int32(env, sum, &result);
  if (status != napi_ok) return nullptr;
  return result;
}

napi_value Execute(napi_env env, napi_callback_info info)
{
	napi_value result;
	napi_status status;
	// napi_value argv[1];
	// size_t argc = 1;
	// status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
	// if (status != napi_ok)
	// 	return nullptr;
	// char s[100];
	// status = napi_get_value_string_utf8(env, argv[0], s, 100, nullptr);
	// if (status != napi_ok)
	// 	return nullptr;
	// min::parser p(s);
	// status = napi_create_string_utf8(env, p.func().result.c_str(), p.func().result.size(), &result);
	test t;
	std::string hw = t.hw();
	status = napi_create_string_utf8(env, hw.c_str(), 12, &result);
	return status != napi_ok ? result : nullptr;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok) return nullptr;


  napi_value fn2;

  status = napi_create_function(env, nullptr, 0, Method2, nullptr, &fn2);
  if (status != napi_ok) return nullptr;

  napi_value ef;
  status = napi_create_function(env, nullptr, 0, Execute, nullptr, &ef);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return nullptr;
  status = napi_set_named_property(env, exports, "add", fn2);
  if (status != napi_ok) return nullptr;
  status = napi_set_named_property(env, exports, "execute", ef);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo

