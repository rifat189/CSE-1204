// class B and C te function er baire kichu likhle oita error dekhaitese..why?

#include <bits/stdc++.h>
using namespace std;
class A
{
private:
    int x = 10;

protected:
    int y = 20;

public:
    int z = 30;
    int getX()
    {
        return x;
    }
};
class B : public A
{
public:
    void accessB()
    {
        cout << "Accessing from B" << endl;
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
    }
};
class C : public A
{
public:
    void accessC()
    {
        cout << "Accessing from C" << endl;
        cout << "y = " << y << " ";
        cout << "z = " << z << endl;
    }
};
int main()
{
    B b;
    C c;
    b.accessB();
    cout << "x = " << b.getX() << endl;
    c.accessC();
    cout << "x = " << c.getX() << endl;
    
}
