#include <iostream>
using namespace std;

class Base
{
private:
    int pvt = 1;

protected:
    int prot = 2;

public:
    int pub = 3;
    // function to access private member
    int getPVT()
    {
        return pvt;
    }
};
class ProtectedDerived : public Base
{
public:
    // function to access protected member from Base
    int getProt()
    {
        return prot;
    }
    // function to access public member from Base
    // int getPub()
    // {
    //     return pub;
    // }
};
int main()
{
    ProtectedDerived object1;
    cout << "Private cannot be accessed."<<object1.getPVT() << endl;
    cout << "Protected = " << object1.getProt() << endl;
    cout << "Public = " << object1.pub << endl;
    return 0;
}