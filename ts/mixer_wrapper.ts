class MixerWrapper
{
    constructor()
};

const mixer_addon: MixerWrapper = require('../build/Release/mixer');
export default mixer_addon;

/*mixer.addVideo(stream:string,sdp:string,options:{x:number
    y:number
    width:number
    height:number
    z:number
    renderType?:MIXER_RENDER_TYPE
});
mixer.addAudio(stream:string,sdp:string);
mixer.removeVideo(stream:string);
mixer.removeAudio(stream:string);
export enum MIXER_RENDER_TYPE {SCALE='scale', CROP='crop', PAD='pad'}*/
