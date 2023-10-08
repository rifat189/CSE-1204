#include <iostream>
using namespace std;
template <class T, class D>
class A
{
    T x;
    D y;

public:
    void setData(T a, D b)
    {
        x = a;
        y = b;
    }

    D getSum()
    {
        D s;
        s = x + y;
        return s;
    }
};
int main()
{
    A<int, double> a1;
    a1.setData(2, 3);
    cout << "Sum= " << a1.getSum() << endl;
    return 0;
}