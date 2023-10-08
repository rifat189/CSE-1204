#include <iostream>
using namespace std;
class complex
{
    public:
    int x;
    int y;
    complex(int a, int b){
        x=a;
        y=b;
    }
    complex operator + (complex c){
        complex t;
        t.x =x+c.x;
        t.y = x+c.y;
        return(c);

    }
};
int main(void)
{
    complex a1(2,3), a2(4,6), a3(2,-5);
    //a3 = a1 + a2;
    a3=a1+(a2);
    cout<<a3.
}