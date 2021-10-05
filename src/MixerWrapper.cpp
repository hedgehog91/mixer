#include "MixerWrapper.h"

using namespace mixer;

Napi::FunctionReference MixerWrapper::constructor;

Napi::Object MixerWrapper::Init(Napi::Env env, Napi::Object exports) 
{
    Napi::HandleScope scope(env);

    Napi::Function func = DefineClass(env, "MixerWrapper", 
    {
        InstanceMethod("AddVideo", &MixerWrapper::AddVideo),
        InstanceMethod("AddAudio", &MixerWrapper::AddAudio),
        InstanceMethod("RemoveVideo", &MixerWrapper::RemoveVideo),
        InstanceMethod("RemoveAudio", &MixerWrapper::RemoveAudio),
    });

    constructor = Napi::Persistent(func);
    exports.Set("MixerWrapper", func);
    
    return exports;
}

MixerWrapper::MixerWrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<MixerWrapper>(info)  
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    VideoParams video_params;
    AudioParams audio_params;

    this->mixer_ = new Mixer(video_params, audio_params);
}

Napi::Value MixerWrapper::AddVideo(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    RenderParams render_params;
    this->mixer_->AddVideo("abc", "abc", render_params);
    
    return Napi::Number::New(env, 0);
}

Napi::Value MixerWrapper::AddAudio(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);   
    this->mixer_->AddAudio("abc");
    
    return Napi::Number::New(env, 0);
}

Napi::Value MixerWrapper::RemoveVideo(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    this->mixer_->RemoveVideo("abc");
    
    return Napi::Number::New(env, 0);
}

Napi::Value MixerWrapper::RemoveAudio(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    this->mixer_->RemoveAudio("abc");
    
    return Napi::Number::New(env, 0);
}

