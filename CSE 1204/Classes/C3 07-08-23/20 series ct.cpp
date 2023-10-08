#include <iostream>
using namespace std;
class Add
{
    int x = 5, y = 20;

public:
    void display()
    {
        cout << "value is: (Base)" << x + y << endl;
    }
    void show(){
        cout<<"Show base class"<<endl;
    }

};
class Substract: public Add{
    int y=10, z=30;
    public: 
    void display(){
        cout<<"value is: (derived)"<<y-z<<endl;
    }
    void show(){
        cout<<"show derived class"<<endl;
    }
};
int main(){
    Add *m;
    Substract s;
     m= &s;
     m->display();
     m->show();
     return 0;
}