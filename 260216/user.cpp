// #include "Vec.h"
import Vec;
#include <iostream>
#include <cmath>

double sqrt_sum(Vec& vec) {
    double sum = 0;
    for (int i=0; i!=vec.size(); ++i) {
        sum += std::sqrt(vec[i]);
    }

    return sum;
}

int main() {
    Vec v(3);
    v[0] = 4;
    v[1] = 9;
    v[2] = 16;

    std::cout << sqrt_sum(v) << std::endl;  // 2+3+4 = 9
}