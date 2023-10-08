#include<iostream>
using namespace std;
class base{
static int x;
public:
static int getX(){
    return x;
}
};

int base::x=50;
int main(){
    base b1;
    cout<<b1.getX()<<endl;
}