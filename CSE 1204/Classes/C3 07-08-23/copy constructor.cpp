#include <iostream>
using namespace std;
class Ball
{
private:
    int s;

public:
    // Ball() {}
    Ball(int x)
    {
        s = x;
    }
    Ball(Ball &b)
    { // we've used addrOf(b1) here
        s = b.s;
    }
    float getSpeed()
    {
        return s;
    }
};
int main()
{
    Ball b1(130), b2(b1);
    // cout<<k.getSpeed()/2;
    cout << b2.getSpeed() << endl;
    return 0;
}