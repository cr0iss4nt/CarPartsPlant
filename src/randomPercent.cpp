#include "randomPercent.hpp"

double randomPercent() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}