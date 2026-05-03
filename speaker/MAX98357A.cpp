#include "MAX98357A.hpp"
#include <iostream>

MAX98357A::MAX98357A(int rate) : sampleRate(rate), isInitialized(false) {}

MAX98357A::~MAX98357A() {
    stop();
}

bool MAX98357A::initialize() {
    std::cout << "MAX98357A Initialized at " << sampleRate << "Hz\n";
    // TODO: Add ALSA snd_pcm_open() logic here
    isInitialized = true;
    return true;
}

void MAX98357A::playBytes(const std::vector<int16_t>& pcmData) {
    if (!isInitialized || pcmData.empty()) return;
    
    std::cout << "Playing " << pcmData.size() << " samples of audio.\n";
    // TODO: Add ALSA snd_pcm_writei() logic here to push buffer to hardware
}

void MAX98357A::stop() {
    if (isInitialized) {
        std::cout << "MAX98357A Stopped.\n";
        // TODO: Add ALSA snd_pcm_close() logic here
        isInitialized = false;
    }
}