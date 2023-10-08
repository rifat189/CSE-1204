#include <bits/stdc++.h>
using namespace std;
void display(vector<int> bx)
{
    cout << "list = ";
    for (auto x : bx)
    {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> ax;
    vector<int>::iterator p;
    // cout<<"size : "<<ax.size()<<endl;
    ax.push_back(19);
    // cout<<"size : "<<ax.size()<<endl;
    ax.push_back(10);
    // cout<<"size : "<<ax.size()<<endl;
    ax.push_back(20);
    // ax[0]=50;
    display(ax);
    // cout<<"ax[0]= "<<ax[0]<<endl;

    p = ax.begin();
    ax.insert(p, 89);
    ax.insert(p + 2, 34);

    display(ax);
    p = ax.begin();

    for (int i = 0; i < ax.size(); i++)
    {
        cout << "in" << endl;
        if (ax[i] == 10)
        {
            ax.insert(p + i, 70);
            break;
        }
    }
    display(ax);

    for (int i = 0; i < ax.size(); i++)
    {
        cout << "in" << endl;
        if (ax[i] == 34)
        {
            ax.erase(p + i);
            break;
        }
    }
    display(ax);
    ax.pop_back();
    display(ax);
    sort(ax.begin(), ax.end());
    display(ax);
    sort(ax.rbegin(), ax.rend());
    display(ax);
    // cout<<"p = "<<&p<<" "<<*p<<endl;
    // p=ax.end()-1;
    // cout<<"p = "<<&p<<" "<<*p<<endl;
    return 0;
}