#include <bits/stdc++.h>
#include <utility>
using namespace std;
int main()
{
    pair<int, string> px;
    px = make_pair(10, "Rajshahi");
    cout << px.first << endl
         << px.second << endl;
    get<0>(px) = 20;
    pair<int, string> bx;
    bx = make_pair(50, "Gazipur");
    px.swap(bx);
    cout << px.first << " "
         << px.second << endl;
}