#include <iostream>
using namespace std;
class Father
{
private:
    int money = 1000;

protected:
    int gold = 500;

public:
    int land = 300;
};
class Son : private Father
{
public:
    void getAccessSon()
    {
        cout << gold << endl;
        cout << money << endl; //inaccessible
        cout << land << endl;
    }
};
class Grandson : private Son
{
public:
    void getAccessGS()
    {
        cout << gold << endl;
        cout << money << endl; //inaccessible
        cout << land << endl;
    }
};
int main()
{
    Son s1;
    s1.getAccessSon();
    Grandson gs1;
    gs1.getAccessGS();
    return 0;
}