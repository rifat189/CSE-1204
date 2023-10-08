#include <iostream>
using namespace std;
class Ball
{
private:
    int s;

public:
    Ball() {}
    Ball(int x)
    {
        s = x;
    }
    float getSpeed()
    {
        return s;
    }
    Ball AvgSpeed(Ball *b)
    {
        Ball t;
        t.s = s + b->s;
        return t;
        // cout << (s + b->s) / 2 << endl;
    }
};
int main()
{
    Ball b1(130), b2(150);
    Ball k;
    k = b1.AvgSpeed(&b2);
    // cout<<k.getSpeed()/2;
    cout << k.getSpeed() << endl;
    return 0;
}