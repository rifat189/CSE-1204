#include <iostream>
using namespace std;
class A {
private:
    int x;
public:
    A() {
        x = 0;
    }
    void display() {
        cout << "x = " << x << endl;
    }
    friend void Add(A &obj, int value);
    friend void IncX(A &obj, int m);
    friend void DecX(A &obj, int n);
};
void Add(A &obj, int value) {
    obj.x = value;
}
void IncX(A &obj, int m) {
    obj.x += m;
}
void DecX(A &obj, int n) {
    obj.x -= n;
}
int main() {
    A obj;
    Add(obj, 10);
    IncX(obj, 5);
    DecX(obj, 3);  
    obj.display();
    return 0;
}
