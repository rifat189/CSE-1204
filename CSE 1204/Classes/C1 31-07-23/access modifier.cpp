#include <iostream>
using namespace std;
class A
{
private:
    int x = 10;

protected:
    int y = 20;

public:
    int z = 30;
};
class B : protected A
{
public:
    void Display()
    {
        // cout << "x= " << x << endl;
        cout<<"Inside B"<<endl;
        cout << "y= " << y << endl;
        cout << "z= " << z << endl;
    }
};
class C : public B
{
public:
    void Display()
    {
        // cout << "x= " << x << endl;
        cout << "y= " << y << endl;
        cout << "z= " << z << endl;
    }
};
int main()
{
    A p;
    cout << "result: " << p.z << endl;
    B nc;
    // nc.y=10; //inaccessible for both public and protected inheritance(access specifier)
    // nc.z=10; //inaccessible for protected inheritance(access specifier)
    // nc.Display();
    C c;
    c.B::Display();
}