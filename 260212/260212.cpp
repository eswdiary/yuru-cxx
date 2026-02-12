#include <iostream>
#include <vector>
using namespace std;

void input_vec(vector<int>& v) {
    // if (v.size()) {
    //     cout << "v!=0" << endl;
    // }

    if (auto n = v.size()) {
        cout << "v!=0" << endl;
        cout << "v.size() = " << n << endl;
    }
}

int main() {
    int arr[6] = {0, 1, 2, 3, 4, 5};

    // pointer
    int* ptr = &arr[3];
    int& ptr_ref = arr[3];

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "ptr_ref = " << ptr_ref << endl;
    
    // for loop
    for (auto i = 0; i < 5; i++) {
        cout << "for loop " << arr[i] << endl;
    }

    // range-for
    // copy / ref
    for (auto& i : arr) {
        cout << "range-for " << i << endl;
    }

    // nullptr
    double* np = nullptr;
    cout << "nullptr = " << np << endl;

    // ++ptr
    cout << "++ptr = " << *++ptr << endl;

    // if-statement
    vector<int> v = {1, 2, 3, 4};
    input_vec(v);    
}