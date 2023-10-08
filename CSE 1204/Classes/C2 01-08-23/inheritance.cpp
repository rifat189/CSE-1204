#include <iostream>
using namespace std;
class A
{
private:
    int x = 10;

protected:
    int y = 20;

public:
    int z = 30;
    A(){
        cout<<"Inside A"<<endl;
    }
        int getx(){
        return x;
    }
};
class B : public A
{
    int x=10;
public:
    B()
    {
        // cout << "x= " << x << endl;
        cout<<"Inside B"<<endl;

    }
    int getx(){
        return x;
    }
};
class C : public B
{
public:
    C()
    {
        // cout << "x= " << x << endl;
        cout << "inside constructor C" ;
        //cout << "z= " << z << endl;
    }
};
int main()
{
    // A p;
    // cout << "result: " << p.z << endl;
    //B nc;
    // nc.y=10; //inaccessible for both public and protected inheritance(access specifier)
    // nc.z=10; //inaccessible for protected inheritance(access specifier)
    // nc.Display();
    C c;
    cout<<c.getx();
    //c.B::Display();
}