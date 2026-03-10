#include <iostream>
#include <initializer_list>

using namespace std;

class Vec
{
public:
    // initianlize member list
    Vec(std::initializer_list<double> lst)
        : elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
    {
        for (int i = 0; i < static_cast<int>(lst.size()); i++)
        {
            elem[i] = 0;
        }
    }

private:
    double *elem;
    int sz;
};

class Vitural
{
public:
    virtual void foo() { cout << "A" << endl; }
    virtual void bar() = 0;
    void foo1() { cout << "foo1" << endl; }
};

class VituralA : public Vitural
{
public:
    void foo() override { cout << "AA" << endl; }
    void bar() override { cout << "pure vrtual function" << endl; }
};

int main()
{
    // Vitural v;
    // v.foo()
    
    VituralA vA;
    vA.foo();
    vA.bar();
    vA.foo1();
}