#include <iostream>
using namespace std;
class B;
class A
{
private:
    int n;

public:
// int n;
    A(int x)
    {
        n = x;
    }
    friend void add(A, B);
};
class B
{
private:
    int n;

public:
// int n;
    B(int x)
    {
        n = x;
    }
    friend void add(A, B);
};
void add(A a, B b)
{
    cout << "Sum = " << a.n + b.n;
}
int main()
{
    A oa(10);
    B ob(20);  
    add(oa, ob);
    return 0;
}