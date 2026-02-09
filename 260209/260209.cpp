#include <iostream>
using namespace std;

// prototype
int sqr(int);

// inline
inline void star(void) {
    cout << "********" << endl;
}

int main() {
    star();
    cout << sqr(4) << endl;
    star();

    // local var
    auto a = 10;
    cout << "a = " << a << endl;

    return 0;
}

int sqr(int i) {
    return i * i;
}

