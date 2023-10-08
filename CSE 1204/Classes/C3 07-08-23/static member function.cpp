#include <iostream>
using namespace std;
class Base
{
    int x;
    static int y;
    public:
    Base(int X){
        x=X;
        y++;
    }
    static int getY(){
        return y;
    }
};
int Base::y=0;
int main()
{
    Base b1(10), b2(20);
    cout<<b1.getY()<<endl;
    cout<<Base::getY();
    return 0;
}