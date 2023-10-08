#include <bits/stdc++.h>
using namespace std;
class A
{
private:
    int ax;

public:
    A(int a)
    {
        ax=a;
        cout<<"Constructor A is called"<<endl;
    }
    int getX(){
        return ax;
    }
    ~A()
    {
        cout<<"Destructor A"<<endl;
    }
};

class B : public A
{
private:
    int bx;

public:
    B(int a, int b):A(a)
    {
        bx=b;
        cout<<"Constructor B is called"<<endl;
    }
    int getY(){
        return bx;
    }
    ~B()
    {
        cout<<"Destructor B"<<endl;
    }
};
class C : public B
{
private:
    int cx;

public:
    C(int a, int b, int c):B(a, b)
    {
        cx=c;
        cout<<"Constructor C is called"<<endl;
    }
    void sum(){
        int sum = A::getX() + B::getY() + cx;
        cout<<"Sum = "<< sum <<endl;
    }
    ~C()
    {
        cout<<"Destructor C"<<endl;
    }
};
int main()
{
    C c(1, 3, 5);
    c.sum();
    return 0;
}