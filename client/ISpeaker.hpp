#pragma once
#include <vector>
#include <cstdint>

class ISpeaker {
public:
    virtual ~ISpeaker() = default;
    virtual bool initialize() = 0;
    virtual void playBytes(const std::vector<int16_t>& pcmData) = 0;
    virtual void stop() = 0;
};