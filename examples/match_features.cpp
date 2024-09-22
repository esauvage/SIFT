#include <iostream> 
#include <string>

#include "image.hpp"
#include "sift.hpp"

#include "matrix.hpp"

Matrix<double> constructMatrixAForFundamentalEstimation(std::vector<std::pair<sift::Keypoint, sift::Keypoint>>& kps)
{
    Matrix<double> result(kps.size(),9);
    double row[9];
    int i = 0;
    for (const auto & p : kps)
    {
        row[0] = p.first.x * p.second.x;
        row[1] = p.first.x * p.second.y;
        row[2] = p.first.x;
        row[3] = p.first.y * p.second.x;
        row[4] = p.first.y * p.second.y;
        row[5] = p.first.y;
        row[6] = p.second.x;
        row[7] = p.second.y;
        row[8] = 1;
        result.setRow(row, i, 9);
        ++i;
    }
    return result;
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    if (argc != 3) {
        std::cerr << "Usage: ./match_features a.jpg b.jpg (or .png)\n";
        return 0;
    }
    Image a(argv[1]), b(argv[2]);
    a = a.channels == 1 ? a : rgb_to_grayscale(a);
    b = b.channels == 1 ? b : rgb_to_grayscale(b);

    std::vector<sift::Keypoint> kps_a = sift::find_keypoints_and_descriptors(a);
    std::vector<sift::Keypoint> kps_b = sift::find_keypoints_and_descriptors(b);
    std::vector<std::pair<int, int>> matches = sift::find_keypoint_matches(kps_a, kps_b);
    Image result = sift::draw_matches(a, b, kps_a, kps_b, matches);
    result.save("result.jpg");

    std::vector<std::pair<sift::Keypoint, sift::Keypoint>> pointsForFundamental;
    for (const auto p : matches)
    {
        pointsForFundamental.push_back(std::pair<sift::Keypoint, sift::Keypoint>(kps_a.at(p.first), kps_b.at(p.second)));
    }
    auto A = constructMatrixAForFundamentalEstimation(pointsForFundamental);

    std::cout << "Found " << matches.size() << " feature matches. Output image is saved as result.jpg\n";
    return 0;
}
