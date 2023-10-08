#include <bits/stdc++.h>
using namespace std;
void display(array<int, 5> bx)
{
    for (int x : bx)
    {
        cout << x << " ";
        cout << endl;
    }
}
int main()
{
    // array<int, 5> ax;
    // ax.fill(7);
    // display(ax);
    // pair<int , int> a;
    // a.first=10;
    // a.second=20;
    // pair<int , string> a[10]; //array of pairs
    pair<int, pair<int, int>> a; // pair of pair
    a.first=1;
    a.second.first=2;
    a.second.second=3;
    cout<<a.second.second;
    // a[0].first = 10;
    // a[0].second = "Johan";
    // cout << "a(" << a[0].first << "," << a[0].second << ")" << endl;
    return 0;
}