#pragma once
#include "ISpeaker.hpp"

class MAX98357A : public ISpeaker {
private:
    int sampleRate;
    bool isInitialized;

public:
    MAX98357A(int rate);
    ~MAX98357A() override;

    bool initialize() override;
    void playBytes(const std::vector<int16_t>& pcmData) override;
    void stop() override;
};