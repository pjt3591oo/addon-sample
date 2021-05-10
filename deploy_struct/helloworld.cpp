#include <napi.h>

namespace test {
  // hi 호출시 문자열 "hello world" 반환
  Napi::String hi(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "hello world");
  }

  // require, import를 통해 가져올 수 있도록 노출
  Napi::Object init(Napi::Env env, Napi::Object exports) {
      exports.Set(Napi::String::New(env, "hi"), Napi::Function::New(env, hi));

      return exports;
  };

  NODE_API_MODULE(hello_world, init);
}