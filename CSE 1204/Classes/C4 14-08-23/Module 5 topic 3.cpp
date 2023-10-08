// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
class A
{
public:
    void Print()
    {
        cout << "Inside Print() of class A" << endl;
    }
};
class B : public A
{
public:
    void Print()
    {
        cout << "Inside Print() of class B" << endl;
    }
};

int main()
{
    B a;
    A *p;
    p=&a;
    p->Print();
    return 0;
}