#include "ISpeaker.hpp"
#include "MAX98357A.hpp"
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<ISpeaker> speaker = std::make_unique<MAX98357A>(22050); 

    if (speaker->initialize()) {
        std::vector<int16_t> dummyAudio(1024, 0); 
        
        speaker->playBytes(dummyAudio);
    }

    speaker->stop();
    return 0;
}