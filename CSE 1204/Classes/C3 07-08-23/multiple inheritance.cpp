#include<iostream>
using namespace std;
class Mammal { 
 public: 
 Mammal() { 
 cout << "Mammals can give direct birth." << endl; 
 } 
};
class WingedAnimal { 
 public: 
 WingedAnimal() { 
 cout << "Winged animal can flap." << endl; 
 } 
};
class Bat: public WingedAnimal, public Mammal {
    public:
    Bat(){
        cout<<"class batman"<<endl;
    }
};
int main() { 
 Bat b1; 
 return 0; 
} 