#include <iostream>
using namespace std;
class Base
{
    mutable int x;
    // int x;

public:
    void setX(int a) { x = a; }
    int getX() const
    {
        x++;
        return x;
    }
};
int main()
{
    Base b1;
    b1.setX(40);
    cout << b1.getX() << endl;
    return 0;
}