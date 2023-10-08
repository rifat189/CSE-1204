// CSE 1203 24 Jul, 2023
#include <iostream>
using namespace std;
class circle
{
private:
    int radius;

public:
    // polymorphism...
    circle(int r)
    {
        cout << "Inside condtructor." << endl;
        radius = r;
    }
    circle()
    {
        cout << "Inside condtructor 2." << endl;
        radius = 0;
    }
    void setRadius(int r)
    {
        radius = r;
    }
    int getRadius()
    {
        return radius;
    }
    float getArea()
    {
        int area = 3.14159 * radius * radius;
        return area;
    }
};
int main()
{
    circle c(3), d(4), e;
    e.setRadius(5);
    // c.setRadius(3);
    cout << c.getRadius() << endl;
    cout << c.getArea() << endl;
    cout << d.getRadius() << endl;
    cout << d.getArea() << endl;
    cout << "End of the program..." << endl;
    return 0;
}