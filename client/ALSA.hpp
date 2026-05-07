#pragma once
#include "ISpeaker.hpp"

class ALSA : public ISpeaker {
private:
    int sampleRate;
    bool isInitialized;

public:
    ALSA(int rate);
    ~ALSA() override;

    bool initialize() override;
    void playBytes(const std::vector<int16_t>& pcmData) override;
    void stop() override;
};