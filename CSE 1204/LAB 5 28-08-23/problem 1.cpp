#include <iostream>
using namespace std;
int main()
{
    int i;
    int ax[5] = {10, 20, 30, 40, 50};
    cout << "Enter index" << endl;
    cin >> i;
    try
    {
        if (i >= 0 && i < 5)
        {
            cout << "ax[" << i << "]=" << ax[i] << endl;
        }
        else
        {
            throw(i);
        }
    }
    catch (int x)
    {
        cout << "Out of range" << endl;
    }
    catch (char ch)
    {
        cout << ch << endl;
    }
    catch (...)
    {
        cout << "Default catch" << endl;
    }
    return 0;
}