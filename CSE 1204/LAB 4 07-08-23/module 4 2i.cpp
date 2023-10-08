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
public:
    void display()
    {
        cout << "x= " << getPrivate() << endl;
        cout << "y= " << y << endl;
        cout << "z= " << z << endl;
    }
};
int main()
{
    B b;
    b.display();
    return 0;
}