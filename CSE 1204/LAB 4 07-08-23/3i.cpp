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
        cout << "A Constructor called"
             << "\n";
    }

    int getAx()
    {
        return ax;
    }

    ~A()
    {
        cout << "A destructor called." << endl;
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
        cout
            << "B Constructor called"
            << "\n";
    }

    int sum()
    {
        return A::getAx() + bx;
    }

    ~B()
    {
        cout << "B destructor called." << endl;
    }
};

int main()
{
    B b(10, 20);

    int result = b.sum();
    cout << "Sum of ax and bx: " << result << endl;

    return 0;
}
