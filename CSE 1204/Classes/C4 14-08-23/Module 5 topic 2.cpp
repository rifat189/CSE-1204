// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
class circuit
{
public:
    float real, img;

public:
    circuit(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    circuit operator+(circuit const &obj)
    {
        circuit res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }
    circuit operator*(circuit const &obj)
    {
        circuit res;
        res.real = (real * obj.real) - (img * obj.img);
        res.img = (real * obj.img) + (img * obj.real);
        return res;
    }
    circuit operator/(circuit const &obj)
    {
        circuit res;
        res.real = ((real * obj.real) + (img * obj.img)) / (obj.real * obj.real + obj.img * obj.img);
        res.img = ((img * obj.real) - (real * obj.img)) / (obj.real * obj.real + obj.img * obj.img);
        return res;
    }
};
int main()
{
    circuit z1(3, 4), z2(4, -2), z3(0, 6), v(100, 50);
    circuit eqvz = (z1 * z2 * z3) / ((z1 * z2) + (z2 * z3) + (z3 * z1));
    circuit current = v / eqvz;
    cout << current.real << endl
         << current.img << endl;
    return 0;
}