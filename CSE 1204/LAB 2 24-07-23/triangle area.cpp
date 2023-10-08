#include <iostream>
// #include <cmath>
#include <math.h>
using namespace std;
class triangle
{
private:
    float a;
    float b;
    float c;
    static int n;

public:
    // int n = 0;

    void setValues(float x, float y, float z)
    {
        a = x, b = y, c = z;
        n++;
    }
    float perimeter()
    {
        return a + b + c;
    }
    float area()
    {
        float s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void display()
    {
        cout << "a= " << a << endl;
        cout << "b= " << b << endl;
        cout << "c= " << c << endl;
    }
    int setN()
    {
        return n;
    }
    // void checkArea(float x, float y)
    // {
    //     if (x > y)
    //     {
    //         cout << "First triangle is larger" << endl;
    //     }
    //     else
    //     {
    //         cout << "Second triangle is larger" << endl;
    //     }
    // }
    void findArea(triangle x, triangle y)
    {
        if (x.area() > y.area())
        {
            cout << "T1 is larger" << endl;
        }
        else
        {
            cout << "T2 is larger" << endl;
        }
    }
};
int triangle::n = 0;
int main()
{
    triangle t1;
    t1.setValues(3.2, 4.4, 5.1);
    t1.display();
    triangle t2;
    t2.setValues(3.7, 5.8, 7.8);
    t2.display();
    // t1.checkArea(t1.area(), t2.area());
    t1.findArea(t1, t2);
    cout << "T1 perimeter: " << t1.perimeter() << endl;
    cout << "T1 area: " << t1.area() << endl;
    cout << "T2 perimeter: " << t2.perimeter() << endl;
    cout << "T2 area: " << t2.area() << endl;
    cout << "Total triangles: " << t1.setN() << endl;

    return 0;
}
