#pragma once 

#include <napi.h>

#include "Mixer.h"

class MixerWrapper : public Napi::ObjectWrap<MixerWrapper> 
{
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    MixerWrapper(const Napi::CallbackInfo& info);
    
private:
    Napi::Value AddVideo(const Napi::CallbackInfo& info);
    Napi::Value AddAudio(const Napi::CallbackInfo& info);
    Napi::Value RemoveVideo(const Napi::CallbackInfo& info);
    Napi::Value RemoveAudio(const Napi::CallbackInfo& info);
    
    mixer::Mixer* mixer_;
    static Napi::FunctionReference constructor;
};

/*
Mixer.create(width=1280,height=720,frameRate=30,audioSampleRate=48000,audioChannels=2)
mixer.addVideo(stream:string,sdp:string,options:{x:number
    y:number
    width:number
    height:number
    z:number
    renderType?:MIXER_RENDER_TYPE
});
mixer.addAudio(stream:string,sdp:string);
mixer.removeVideo(stream:string);
mixer.removeAudio(stream:string);
export enum MIXER_RENDER_TYPE {SCALE='scale', CROP='crop', PAD='pad'}
*/



