#include <node.h>
#include <string>
#include <iostream>

using namespace v8;

void FilterLargeArray(const FunctionCallbackInfo<Value>& args) {
  Isolate * isolate = args.GetIsolate();

  // get array
  Local<Array> array = Local<Array>::Cast(args[0]);

  // get filter key
  v8::String::Utf8Value sKey(args[1]);
  std::string key_str(*sKey);

  // get filter string
  v8::String::Utf8Value sFilter(args[2]);
  std::string search_str(*sFilter);

  // tmp vector
  std::vector<int> tmp_arr;

  // mk return array
  Local<Array> a = Array::New(isolate);

  // create Props
  Local<String> pKey = String::NewFromUtf8(isolate, key_str.c_str());

  // loop given array
  for (unsigned int i = 0; i < array->Length(); i++ ) {

    Local<Object> _o = array->Get(i)->ToObject();

    // key
    v8::String::Utf8Value _v8Key_s(_o->Get(pKey));
    std::string key_str(*_v8Key_s);

    if (key_str.find(search_str) != std::string::npos) {
      tmp_arr.push_back(i);
    }
  }

  for (unsigned int i = 0; i < tmp_arr.size(); i++ ) {
    a->Set(i, array->Get(tmp_arr[i])->ToObject());
  }

  args.GetReturnValue().Set(a);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "filter", FilterLargeArray);
}

NODE_MODULE(flarr, Init);
