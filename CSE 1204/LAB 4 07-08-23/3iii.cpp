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
        cout << "Constructor A is called." << endl;
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

class B
{
private:
    int bx;

public:
    B(int b)
    {
        bx = b;
        cout << "Constructor B is called." << endl;
    }

    int getBx()
    {
        return bx;
    }

    ~B()
    {
        cout << "Destructor B" << endl;
    }
};

class C : public A, public B
{
private:
    int cx;

public:
    C(int a, int b, int c) : A(a), B(b)
    {
        cx = c;
        cout << "Constructor C is called." << endl;
    }

    int add()
    {
        return A::getAx() + B::getBx() + cx;
    }

    ~C()
    {
        cout << "Destructor C" << endl;
    }
};

int main()
{
    C c(4, 2, 7);

    cout << "Sum : " << c.add() << endl;

    return 0;
}
