#pragma once

#include <iostream>

namespace mixer
{

struct VideoParams
{
    int width = 1280;
    int height = 720;
    int frame_rate = 30;
};

struct AudioParams
{
    int sample_rate_hz = 48000;
    int count_channels = 2;
};

enum class RenderType
{
    kScale = 0,
    kCrop,
    kPad
};

struct RenderParams
{
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    int z_order = 0;
    RenderType render_type = RenderType::kScale;
};

std::string RenderTypeToString(const RenderType& render_type);

class Mixer
{
public:
    Mixer(const VideoParams& video_params, const AudioParams& audio_params);
    ~Mixer();
    
    void AddVideo(const std::string& stream, const std::string& sdp, const RenderParams& render_params);
    void AddAudio(const std::string& stream);
    void RemoveVideo(const std::string& stream);
    void RemoveAudio(const std::string& stream);
    
private:

};

}
