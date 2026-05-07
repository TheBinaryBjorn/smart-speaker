#include "ALSA.hpp"
#include <iostream>

ALSA::ALSA(int rate) : sampleRate(rate), isInitialized(false) {}

ALSA::~ALSA() {
    stop();
}

bool ALSA::initialize() {
    std::cout << "ALSA Initialized at " << sampleRate << "Hz\n";
    // TODO: Add ALSA snd_pcm_open() logic here
    isInitialized = true;
    return true;
}

void ALSA::playBytes(const std::vector<int16_t>& pcmData) {
    if (!isInitialized || pcmData.empty()) return;
    
    std::cout << "Playing " << pcmData.size() << " samples of audio.\n";
    // TODO: Add ALSA snd_pcm_writei() logic here to push buffer to hardware
}

void ALSA::stop() {
    if (isInitialized) {
        std::cout << "MAX98357A Stopped.\n";
        // TODO: Add ALSA snd_pcm_close() logic here
        isInitialized = false;
    }
}