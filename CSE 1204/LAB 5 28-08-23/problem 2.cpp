#include <iostream>
using namespace std;
template <typename t, typename r>
class A
{
private:
    t x;
    r y;

public:
    void setData(t x, r y)
    {
        this->x = x;
        this->y = y;
    }
    r Sum()
    {
        r s;
        s = x + y;
        return s;
    }
};
int main()
{
    A<int, int> a1;
    a1.setData(10, 20);
    cout<<"int(10)+int(20) = " <<a1.Sum()<<endl;

    A<int, double> a2;
    a2.setData(10, 20.3);
    cout<<"int(10)+int(20.3) = " <<a2.Sum()<<endl;

    A<double, double> a3;
    a3.setData(10.7, 20.3);
    cout<<"int(10.7)+int(20.3) = " <<a3.Sum()<<endl;

}