#include <iostream>
using namespace std;
int main()
{
    int d, n, r;
    cout << "Enter n and d: ";
    cin >> n >> d;
    try
    {
        if (d == 0)
            //throw("Error!!!");
            throw(12.5);
        r = n / d;
        cout << "r = " << r << endl;
    }
    catch (int x)
    {
        cout << "Division by " << x << endl;
    }
    catch (char const y[])
    {
        cout << y << endl;
    }
    catch(...){
        cout<<"Undefined Error"<<endl;
    }
    return 0;
}