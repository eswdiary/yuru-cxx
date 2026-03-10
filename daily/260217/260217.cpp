#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// subfix type
auto plus_plus(int i) -> int { i++; return i; }

int main() {
    vector<int> v = {1, 2, 3};

    try {
        cout << v[0] << endl;
        cout << v[1] << endl;   // out of range
        cout << v[2] << endl;   // out of range
        cout << v[3] << endl;   // out of range
        cout << v.at(0) << endl;
        cout << v.at(3) << endl;    // out of range
    } catch (std::exception& err) {
        cout << "exception: " << err.what() << endl;
    }

    cout << plus_plus(1) << endl;

    return 0;
}