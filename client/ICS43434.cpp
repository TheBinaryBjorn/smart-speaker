#include <alsa/asoundlib.h>
#include <string>
#include <iostream>
#include <vector>

const std::string DEVICE_NAME = "default";
const int OPEN_MODE = 0;
const int NUMBER_OF_CHANNELS = 1;
const int SOFTWARE_RESAMPLING = 1;
const int BUFFER_LATENCY = 50000;

class ICS43434 {
private:
    int sampleRate;
    bool isInitialized;
    snd_pcm_t* pcmHandle;

public:
    // Constructor
    ICS43434(int rate) {
        sampleRate = rate;
        isInitialized = false;
        pcmHandle = NULL;
    }

    // Destructor
    ~ICS43434() {
        stop();
    }

    bool initialize() {
        int result;
        
        result = snd_pcm_open(&pcmHandle, DEVICE_NAME.c_str(), SND_PCM_STREAM_CAPTURE, OPEN_MODE);
        if(result < 0) {
            std::cout << "[Error]: Failed to open ALSA capture device.\n";
            return false;
        }

        result = snd_pcm_set_params(pcmHandle,
            SND_PCM_FORMAT_S32_LE,
            SND_PCM_ACCESS_RW_INTERLEAVED,
            NUMBER_OF_CHANNELS, sampleRate,
            SOFTWARE_RESAMPLING, BUFFER_LATENCY
        );
        if(result < 0) {
            std::cout << "[Error]: Failed to set ALSA parameters.\n";
            return false;
        }

        std::cout << "[Success]: ICS43434 Capture Initialized at " << sampleRate << " Hz\n";
        isInitialized = true;
        return true;
    }

    void recordBytes(std::vector<int32_t>& buffer) {
        if(isInitialized == false) {
            return;
        }
        if(buffer.size() == 0) {
            return;
        }

        snd_pcm_sframes_t frames;
        frames = snd_pcm_readi(pcmHandle, buffer.data(), buffer.size());

        if(frames < 0) {
            snd_pcm_prepare(pcmHandle);
        }
    }

    void stop() {
        if(isInitialized == true) {
            if(pcmHandle != NULL) {
                snd_pcm_drop(pcmHandle);
                snd_pcm_close(pcmHandle);
                pcmHandle = NULL;
                isInitialized = false;
                std::cout << "ALSA Capture Stopped\n";
            }
        }
    }
};