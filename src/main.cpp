#include <napi.h>

#include "MixerWrapper.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return MixerWrapper::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
