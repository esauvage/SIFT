#include <iostream> 
#include <string>

#include "image.hpp"
#include "sift.hpp"

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (argc != 2) {
        std::cerr << "Usage: ./find_keypoints input.jpg (or .png)\n";
        return 0;
    }
    Image img(argv[1]);
    img =  img.channels == 1 ? img : rgb_to_grayscale(img);
    // const unsigned int n1 = img.width;
    // const unsigned int n2 = img.height;
    // img.data
    // float **x = new float*[n1];
    // for(unsigned int i=0;i<n1;i++) {
    //     x[i] = new float[n2];
    //     for(unsigned int j=0;j<n2;j++) {
    //         x[i][j] = ((float)rand()/RAND_MAX)*2-1;
    //     }
    // }

    // FastFourierTransform *FFT = new FastFourierTransform(n1, n2);

    // complex<float> **y = FFT->fft2(x);

    std::vector<sift::Keypoint> kps = sift::find_keypoints_and_descriptors(img);
    Image result = sift::draw_keypoints(img, kps);
    result.save("result.jpg");

    std::cout << "Found " << kps.size() << " keypoints. Output image is saved as result.jpg\n";
    return 0;
}
