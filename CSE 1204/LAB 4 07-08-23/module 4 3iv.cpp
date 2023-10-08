#include <iostream>
using namespace std;

class A
{
private:
    int ax;

public:
    A(int a)
    {
        ax = a;
        cout << "Constructor A is called" << endl;
    }

    int getAx()
    {
        return ax;
    }

    ~A()
    {
        cout << "Destructor A" << endl;
    }
};

class B : public A
{
private:
    int bx;

public:
    B(int a, int b) : A(a)
    {
        bx = b;
        cout << "Constructor B is called." << endl;
    }

    ~B()
    {
        cout << "Destructor B" << endl;
    }
};

class C : public A
{
private:
    int cx;

public:
    C(int a, int c) : A(a)
    {
        cx = c;
        cout << "Constructor C is called." << endl;
    }

    void add()
    {
        int sum = A::getAx() + cx;
        cout << "Sum: " << sum << endl;
    }

    ~C()
    {
        cout << "Destructor C" << endl;
    }
};

int main()
{
    B b(56, 34);
    C c(23, 45);

    c.add();

    return 0;
}
