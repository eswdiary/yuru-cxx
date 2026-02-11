#include <iostream>
#include <vector>
using namespace std;

constexpr double square(double x) { return x * x; }
consteval double square2(double x) { return x * x; }

int main()
{
    int i = 5;
    char c = 'c';

    // initialize
    double d1{2.3};

    // auto keyword
    auto d2{3.5};

    // const / constexp

    double sum(const vector<double> &);
    vector<double> vec{1.2, 1.3, 1.4};
    double s1 = sum(vec);

    // contexpr

    double var = 3.14;
    constexpr double max = 1.4 * square(17);
    const double max2 = 1.4 * square(var);

    // consteval
    constexpr double max3 = 1.4 * square2(17);
    // const double max4 = 1.4 * square2(var);

    // sizeof
    cout << sizeof(i) << endl;
    cout << sizeof(c) << endl;

    cout << d1 << endl;
    cout << d2 << endl;

    cout << "s1 = " << s1 << endl;

    cout << "max = " << max << endl;
    cout << "max2 = " << max2 << endl;
    cout << "max3 = " << max3 << endl;
}

double sum(const vector<double> &vec)
{
    double result = 0.0;
    for (double num : vec)
    {
        result += num;
    }
    return result;
}
