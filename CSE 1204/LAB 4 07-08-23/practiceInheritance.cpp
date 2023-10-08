#include <iostream>
using namespace std;
class first
{
private:
    int pass = 234;

protected:
    string name = "naam";

public:
    int roll = 56;
};
class second : private first
{
    public: //if we use protected here, we can't have access of checking()
    void checking()
    {
        //cout << pass << endl;
        cout << name << endl;
        cout << roll << endl;
    }
};
int main()
{
    second s;
    s.checking(); // we're trying to access a private property using public intheritance. So it's not working
}