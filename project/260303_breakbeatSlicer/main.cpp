#include <iostream>
#include <sndfile.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./slicer test.wav" << std::endl;
        return 1;
    }

    SF_INFO sfinfo;
    SNDFILE* file = sf_open(argv[1], SFM_READ, &sfinfo);

    if (!file) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::cout << "Sample rate: " << sfinfo.samplerate << std::endl;
    std::cout << "Channels: " << sfinfo.channels << std::endl;
    std::cout << "Frames: " << sfinfo.frames << std::endl;

    sf_close(file);
    return 0;
}