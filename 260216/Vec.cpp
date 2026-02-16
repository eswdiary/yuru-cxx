#include "Vec.h"

Vec::Vec(int s) : elem{new double[s]}, sz{s} {}

double& Vec::operator[](int i) {
    return elem[i];
}

int Vec::size() {
    return sz;
}
