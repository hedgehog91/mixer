#include "Mixer.h"

#include <iostream>
#include <exception>

using namespace std;

namespace mixer
{

std::string RenderTypeToString(const RenderType& render_type)
{
    if (render_type == RenderType::kScale)
        return "scale";
    else if (render_type == RenderType::kCrop)
        return "crop";
    else if (render_type == RenderType::kPad)
        return "pad";
        
    throw invalid_argument("Can't convert render_type " + to_string(static_cast<int>(render_type)) + " to string"); 
}
    
Mixer::Mixer(const VideoParams& video_params, const AudioParams& audio_params)
{
    cout << "Create mixer with params:" 
         << " width " << video_params.width 
         << ", height "<< video_params.height 
         << ", frame_rate " << video_params.frame_rate 
         << ", sample_rate_hz " << audio_params.sample_rate_hz
         << ", count_channels " << audio_params.count_channels << endl;    
}

void Mixer::AddVideo(const std::string& stream, const std::string& sdp, const RenderParams& render_params)
{
    cout << "Add video with params:" 
         << " stream " << stream 
         << ", sdp " << sdp 
         << ", x " << render_params.x  
         << ", y " << render_params.y 
         << ", width " << render_params.width 
         << ", height " << render_params.height
         << ", z_order " << render_params.z_order 
         << ", render_type " << RenderTypeToString(render_params.render_type) << endl;
}

void Mixer::AddAudio(const std::string& stream)
{
    cout << "Add audio with params:" 
         << " stream " << stream << endl;
}

void Mixer::RemoveVideo(const std::string& stream)
{
    cout << "Remove video with params:" 
         << " stream "<< stream << endl;
}

void Mixer::RemoveAudio(const std::string& stream)
{
    cout << "Remove audio with params:"
         << " stream "<< stream << endl;
}

Mixer::~Mixer()
{
    cout << "Destroy mixer" << endl;
}


}
