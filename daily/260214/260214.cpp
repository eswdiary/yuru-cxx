#include <iostream>
using namespace std;

class Vec {
    public:
        // member initializer list
        Vec(int i) : elem { new double[i] }, sz { i } {}
        double& operator[](int i) { return elem[i]; }
        int size() { return sz; }
    private:
        double* elem;
        int sz;
};

Vec r_a_s(int i) {
    Vec vec(i);

    for (int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
    }

    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }

    // return sum;
    return vec;
}

enum class Color { red, blue, green };

Color& operator++(Color& c) {
    switch (c) {
        case Color::red:
            return c = Color::green;
        case Color::green:
            return c = Color::blue;
        case Color::blue:
            return c = Color::red;
    }
}

int main() {
    // Vec r = r_a_s(4);
    // cout << r[0] << endl;
    Color c1 = Color::red;
    Color c2 { Color::green };
    int x = int(c2);

    Color next = ++c2;
    int y = int(next);

    // under laying type, default is int
    cout << x << endl;
    cout << y << endl;
}