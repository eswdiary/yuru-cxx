#include <iostream>
#include <sndfile.h>
#include <fstream>
#include <cstdint>
#include <vector>

void write_wav_header (std::ofstream out, u_int32_t data_size, u_int32_t sample_rate = 44100, u_int16_t channels = 1) {
    
    u_int32_t chunk_size = 36 + data_size;

    out.write("RIFF", 4);
    out.write(reinterpret_cast<char*>(&chunk_size), 4);
    out.write("WAVE", 4);

    // wave
    // ├── fmt
    // └── data

    u_int32_t subchunk1_size = 16;
    u_int16_t audio_format = 1;

    out.write("fmt", 4);
    out.write(reinterpret_cast<char*>(&subchunk1_size), 4);
    out.write(reinterpret_cast<char*>(&audio_format), 2);
    out.write(reinterpret_cast<char*>(channels), 2);
    out.write(reinterpret_cast<char*>(sample_rate), 4);

    u_int16_t bits_per_sample = 24;
    // bit to byte
    u_int32_t byte_rate = sample_rate * channels * bits_per_sample / 8;
    u_int16_t block_align = channels * bits_per_sample / 8;
    
    out.write(reinterpret_cast<char*>(byte_rate), 4);
    out.write(reinterpret_cast<char*>(block_align), 2);
    out.write(reinterpret_cast<char*>(bits_per_sample), 2);

    // data
    out.write("data", 4);
    out.write(reinterpret_cast<char*>(data_size), 4);
}

int main(int argc, char* argv[]) {
    // Usage: ./databender <path>
    if (argc < 2) {
        std::cout << "" << std::endl;
        return 1;
    }

    // RAW
    std::ifstream in(argv[1], std::ios::binary);
    std::vector<char> bytes(
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>()
    );

    in.close();
}