#include <iostream>
using namespace std;

int main() {
    // type conversion
    int a = 45;
    float b = 3.0f;
    double c = 7.25;
    int d = 7;

    cout << "a / b = " << (float)a / b << endl;
    cout << "a / c = " << a / c << endl;
    cout << "a / d = " << a / d << endl;
    cout << "a / d = " << (double)a / d << endl;
    cout << "sizeof b = " << sizeof(b) << endl;
    cout << "sizeof c = " << sizeof(c) << endl;
    
    // conditional operator
    int min;
    min = (a < b) ? a : b;
    cout << "min = " << min << endl;
    

    return 0;
}