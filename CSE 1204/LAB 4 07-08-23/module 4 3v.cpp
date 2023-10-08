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
        cout << "Destructor A is called" << endl;
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

class B : virtual public A
{
private:
    int bx;

public:
    B(int a, int b) : A(a)
    {
        bx = b;
        cout << "Constructor B is called" << endl;
    }

    int getBx()
    {
        return bx;
    }

    ~B()
    {
        cout << "Destructor B " << endl;
    }
};

class C : virtual public A
{
private:
    int cx;

public:
    C(int a, int b) : A(a)
    {
        cx = b;
        cout << "Constructor C is called" << endl;
    }

    int getCx()
    {
        return cx;
    }

    ~C()
    {
        cout << "Destructor C " << endl;
    }
};

class D : public B, public C
{
private:
    int dx;

public:
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c)
    {
        dx = d;
        cout << "Constructor D" << endl;
    }
    void add()
    {
        int sum = A::getAx() + B::getBx() + C::getCx() + dx;
        cout << "Sum: " << sum << endl;
    }
    ~D()
    {
        cout << "Destructor D" << endl;
    }
};

int main()
{
    D d(23, 15, 90, 9);

    d.add();

    return 0;
}
