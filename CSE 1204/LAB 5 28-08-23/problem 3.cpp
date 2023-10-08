#include <bits/stdc++.h>
#include <array>
using namespace std;
int main()
{
    array<int, 5> ax = {10, 60, 30, 70, 20};
    cout << ax.at(3) << endl
         << ax.front() << endl
         << ax.back() << endl
         << ax.size() << endl
         << ax.max_size() << endl
         << ax.begin() << endl
         << ax.end() << endl;
    ax.fill(100);
    if (ax.empty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
}