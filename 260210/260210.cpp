#include <iostream>
using namespace std;

double square(double);

// function overloading
void print(int);
void print(double);
void print(string);

void print_square(double x) {
    cout << "Square = " << square(x) << endl; 
}

int main() {
    cout << "Hello, World\n";
    print_square(4);
    print(4);
}

double square(double x) {
    return x * x;
}

void print(double x) {
    cout << x << endl;
}

void print(string x) {
    cout << x << endl;
}

void print(int x) {
    cout << x << endl;
}