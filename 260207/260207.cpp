#include <iostream>
#include <climits>

using namespace std;

int main(){
    int num_int = 3;
    double num_double = 1.32;

    int num_int_max = INT_MAX;

    // byte
    cout << sizeof(num_int) << endl;
    cout << sizeof(num_double) << endl;

    // overflow
    cout << num_int_max << endl;
    cout << num_int_max + 1 << endl;

    // ASCII
    char ch = 'h';
    int i = ch;

    cout << "ch = " << ch << endl;
    cout << "ASCII = " << i << endl;
    
    // cin
    int x, y;
    cin >> x;
    cout << x << endl;

    return 0;
}
