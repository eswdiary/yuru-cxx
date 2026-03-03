#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>
#include <vector>

struct AudioData {
    std::vector<float> bufL;
    std::vector<float> bufR;
    size_t playhead = 0;
};

void callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    AudioData* data = (AudioData*)pDevice->pUserData;
    float* out = (float*)pOutput;

    for (ma_uint32 i = 0; i < frameCount; i++) {
        if (data->playhead >= data->bufL.size()) data->playhead = 0;

        out[i * 2]     = data->bufL[data->playhead];
        out[i * 2 + 1] = data->bufR[data->playhead];
        data->playhead++;
    }
}

int main() {
    // LOAD
    drwav wav;

    if (!drwav_init_file(&wav, "test.wav", nullptr)) {
        std::cerr << "  Failed to load file." << "\n";
        return 1;
    }
    
    std::vector<float> samples(wav.totalPCMFrameCount * wav.channels);
    drwav_read_pcm_frames_f32(&wav, wav.totalPCMFrameCount, samples.data());
    drwav_uninit(&wav);

    AudioData data;
   
    // SPLIT L / R
    //    std::vector<float> bufL, bufR;
   for (size_t i = 0; i < wav.totalPCMFrameCount; i++) {
        data.bufL.push_back(samples[i * 2]);
        data.bufR.push_back(samples[i * 2 + 1]);
   }

   ma_device_config config = ma_device_config_init(ma_device_type_playback);
   config.playback.format  = ma_format_f32;
   config.playback.channels = 2;
   config.sampleRate = wav.sampleRate;
   config.dataCallback = callback;
   config.pUserData = &data;

   ma_device device;
   ma_device_init(nullptr, &config, &device);
   ma_device_start(&device);

   std::cout << "Playing......press enter to stop.";
   std::cin.get();

   ma_device_uninit(&device);
   return 0;
}