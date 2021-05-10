#include <napi.h>

/*
  * Add: 2개의 인자를 받아 덧셈 결과를 반환하는 함수 - 완료
  * Sub: 2개의 인자를 받아 뺄셈 결과를 반환하는 함수 - 완료
  * RunCallback: 하나의 함수를 전달받아 실행하는 함수 - 완료
  * CreateObject: 객체를 반환하는 함수 - 완료
  * CreateFunction: 함수를 반환하는 함수 - 작업중
*/
namespace official_napi{
  Napi::Number Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() != 2 ) {
      Napi::TypeError::New(env, "Invalid Number length 2").ThrowAsJavaScriptException();
    } else if (!info[0].IsNumber() || !info[1].IsNumber()) {
      Napi::TypeError::New(env, "Invalid Number Type Number").ThrowAsJavaScriptException();
    }

    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    double arg1 = info[1].As<Napi::Number>().DoubleValue();

    return Napi::Number::New(env, arg0 + arg1);
  }
  
  Napi::Number Sub(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 2 ) {
      Napi::TypeError::New(env, "Invalid Number length 2").ThrowAsJavaScriptException();
    } else if (!info[0].IsNumber() || !info[1].IsNumber()) {
      Napi::TypeError::New(env, "Invalid Number Type Number").ThrowAsJavaScriptException();
    }

    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    double arg1 = info[1].As<Napi::Number>().DoubleValue();

    return Napi::Number::New(env, arg0 - arg1);
  }

  void RunCallback(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() != 1 ) {
       Napi::TypeError::New(env, "Invalid Number length 2").ThrowAsJavaScriptException();
    } else if (!info[0].IsFunction()) {
      Napi::TypeError::New(env, "Invalid Number Type Number").ThrowAsJavaScriptException();
    }

    Napi::Function cb = info[0].As<Napi::Function>();
   
    // cb.Call의 두 번째 인자로 콜백 호출시 전달할 파라미터 지정
    cb.Call(
      env.Global(), {
        Napi::String::New(env, "helloworld1"),
         Napi::String::New(env, "helloworld2")
      }
    );
  }

  Napi::Object CreateObject(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);

    obj.Set(Napi::String::New(env, "key1"), "val1");
    obj.Set(Napi::String::New(env, "key2"), "val2");

    return obj;
  }

  Napi::Boolean MyFunction(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() != 2 ) {
      Napi::TypeError::New(env, "Invalid Number length 2").ThrowAsJavaScriptException();
    } else if (!info[0].IsNumber() || !info[1].IsNumber()) {
      Napi::TypeError::New(env, "Invalid Number Type Number").ThrowAsJavaScriptException();
    }

    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    double arg1 = info[1].As<Napi::Number>().DoubleValue();

    return Napi::Number::New(env, arg0 + arg1);
  }

  // Napi::Function CreateFunction(const Napi::CallbackInfo& info) {
  //   Napi::Env env = info.Env();
  //   Napi::Function myFunction = Napi::Function::New(env, MyFunction, {
  //       Napi::Number::New(env, 1),
  //        Napi::Number::New(env, 2)
  //     });

  //   return Napi::FunctionReference::FunctionReference(env, &MyFunction);
  // }

  Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "Add"), Napi::Function::New(env, Add));
    exports.Set(Napi::String::New(env, "Sub"), Napi::Function::New(env, Sub));
    exports.Set(Napi::String::New(env, "RunCallback"), Napi::Function::New(env, RunCallback));
    exports.Set(Napi::String::New(env, "CreateObject"), Napi::Function::New(env, CreateObject));
    // exports.Set(Napi::String::New(env, "CreateFunction"), Napi::Function::New(env, CreateFunction));

    return exports;
  };

  NODE_API_MODULE(official_napi, init);
}
