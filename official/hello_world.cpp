#include <node.h>
#include <uv.h>
#include <iostream>
#include <unistd.h>

namespace demo {
  using v8::Context;
  using v8::Function;
  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::FunctionTemplate;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;
  using v8::Null;
  using v8::Persistent;

  void Add(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();

    if (args.Length() < 2) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate,
                              "Wrong number of arguments")
              .ToLocalChecked()));
      return;
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate,
                              "Wrong arguments")
              .ToLocalChecked()));
      return;
    }

    double value = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
    Local<Number> num = Number::New(isolate, value);

    args.GetReturnValue().Set(num);
  }

  void Sub(const FunctionCallbackInfo<Value> &args) {
    Isolate *isolate = args.GetIsolate();

    if (args.Length() < 2) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate,
                              "Wrong number of arguments")
              .ToLocalChecked()));
      return;
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate,
                              "Wrong arguments")
              .ToLocalChecked()));
      return;
    }

    double value = args[0].As<Number>()->Value() - args[1].As<Number>()->Value();
    Local<Number> num = Number::New(isolate, value);

    args.GetReturnValue().Set(num);
  }

  void RunCallback(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cb = Local<Function>::Cast(args[0]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = {
        String::NewFromUtf8(isolate,
                            "hello world").ToLocalChecked() };
    cb->Call(context, Null(isolate), argc, argv).ToLocalChecked();
  }

  void CreateObject(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if (args.Length() < 2) {
      isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate,
                              "Wrong number of arguments")
              .ToLocalChecked()));
      return;
    }

    Local<Context> context = isolate->GetCurrentContext();

    Local<Object> obj = Object::New(isolate);
    obj->Set(context,
            String::NewFromUtf8(isolate,
                                "key1").ToLocalChecked(),
                                args[0]->ToString(context).ToLocalChecked())
            .FromJust();
    obj->Set(context,
            String::NewFromUtf8(isolate,
                                "key2").ToLocalChecked(),
                                args[1]->ToString(context).ToLocalChecked())
            .FromJust();

    args.GetReturnValue().Set(obj);
  }

  void MyFunction(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(
        isolate, "hello world").ToLocalChecked());
  }

  void CreateFunction(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    Local<Context> context = isolate->GetCurrentContext();
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, MyFunction);
    Local<Function> fn = tpl->GetFunction(context).ToLocalChecked();

    fn->SetName(String::NewFromUtf8(
        isolate, "theFunction").ToLocalChecked());

    args.GetReturnValue().Set(fn);
  }

  void Init(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "add", Add);
    NODE_SET_METHOD(exports, "sub", Sub);
    NODE_SET_METHOD(exports, "runCallback", RunCallback);
    NODE_SET_METHOD(exports, "createObject", CreateObject);
    NODE_SET_METHOD(exports, "createFunction", CreateFunction);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

} 