#include <iostream>
#include <vector>
#include <sndfile.h>
#include <random>

int main(int argc, char *argv[])
{
    // ./slicer <path> <slice> <repeat>
    if (argc < 3)
    {
        std::cout << "Usage: ./slicer <path> <slice>" << std::endl;
        return 1;
    }

    // INIT
    SF_INFO sfinfo;
    SNDFILE* file = sf_open(argv[1], SFM_READ, &sfinfo);

    // READ
    std::vector<float> buffer(sfinfo.frames * sfinfo.channels);
    sf_readf_float(file, buffer.data(), sfinfo.frames);
    sf_close(file);

    // SLICE
    int num_slice =  std::stoi(argv[2]);
    int slice_size = sfinfo.frames / num_slice;

    for (int i=0; i<num_slice; i++) {
        int start = i * slice_size;
        int end = start + slice_size;
    }

    // RANDOM
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, num_slice - 1);

    int repeat = std::stoi(argv[3]);

    // OUTPUT
    std::vector<float> output_buffer;
    for (int r=0; r<repeat; r++) {
        for (int i=0; i<num_slice; i++) {
            int idx = dist(rng);
            int start = idx * slice_size * sfinfo.channels;     // slice_start idx
            int end = start + slice_size * sfinfo.channels;     // slice_end idx
            output_buffer.insert(output_buffer.end(), buffer.begin() + start, buffer.begin() + end);
        } 
    }
    
    sf_count_t total_frame = slice_size * num_slice * repeat;

    SNDFILE* out_file = sf_open("output.wav", SFM_WRITE, &sfinfo);
    sf_writef_float(out_file, output_buffer.data(), total_frame);
    sf_close(out_file);

    std::cout << "Done" << std::endl;
    std::cout << num_slice << " slices -> output.wav" << std::endl;

    return 0;
}