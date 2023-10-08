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
    int getPrivate()
    {
        return x;
    }
};
class B : public A
{
};
class C : public B
{
public:
    // void display()
    // {
    //     cout << "x= " << getPrivate() << endl;
    //     cout << "y= " << y << endl;
    //     cout << "z= " << z << endl;
    // }
    int getY()
    {
        return y;
    }
};
int main()
{
    C c;
    cout << "y= " << c.getY() << endl;
    cout << "x= " << c.getPrivate() << endl;
    cout << "z= " << c.z << endl;
    // c.display();
    return 0;
}