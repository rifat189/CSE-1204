#include <bits/stdc++.h>
using namespace std;
class B;
class A
{
private:
    int ax;

public:
    // A()
    // {
    //     cout << "Inside A" << endl;
    // }
    A(int a)
    {
        ax = a;
        cout << "Constructor A is called" << endl;
        // cout<<ax<<endl;
    }
    int getX()
    {
        // cout<<"getx:"<<ax<<endl;
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
    // B()
    // {
    //     cout << "inside B" << endl;
    // }
    B(int a, int b) : A(a)
    {
        bx = b;
        cout << "Constuctor B is called" << endl;
    }
    int add()
    {
        int y = A::getX();
        //cout << "Sum = " << y + bx << endl;
        return y+bx;
    }
    ~B()
    {
        cout << "Destructor B" << endl;
    }
};

int main()
{
    B obj2(1, 4);
    cout << "Result= " << obj2.add() << endl;
    return 0;
}