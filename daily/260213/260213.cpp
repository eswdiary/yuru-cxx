#include <iostream>

// struct
struct vec {
    double* elem; 
    int sz;
};

void vec_init(vec& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

// through pointer
void f(vec* v) {
    int i = v -> sz;
}

int main() {
    vec v;
    vec_init(v, 4);
}