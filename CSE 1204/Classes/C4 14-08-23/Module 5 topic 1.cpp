// #include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Test{
public:
int Sum(int a){
    return a;
}
double Sum(double a, double b){
    return a+b;
}
};
int main(){
    Test t;
    cout<<t.Sum(10)<<endl;
    cout<<t.Sum(10, 20)<<endl;
    cout<<t.Sum(5.7, 20)<<endl;
    cout<<t.Sum(10, 2.6)<<endl;
    cout<<t.Sum(10.5, 20.7)<<endl;
    return 0;
}