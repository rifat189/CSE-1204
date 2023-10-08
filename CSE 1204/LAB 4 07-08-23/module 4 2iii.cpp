#include <iostream>
using namespace std;
class A
{
private:
    int x = 3;

protected:
    int y = 4;

public:
    int z = 5;
    int getPrivateX()
    {
        return x;
    }
};
class B
{
private:
    int p=300;

protected:
    int q=700;

public:
    int r=90;
    int getPrivateP()
    {
        return p;
    }
};
class C : public A, public B
{
public:
    int getProtQ() { return q; }
    int getProtY() { return y; }
};
int main()
{
    C c;
    cout << "z = " << c.z << endl;
    cout << "r = " << c.r << endl;
    cout << "q = " << c.getProtQ()<< endl;
    cout << "y = " << c.getProtY()<< endl;
    cout << "p = " << c.getPrivateP() << endl;
    cout << "x = " << c.getPrivateX() << endl;
    return 0;
}