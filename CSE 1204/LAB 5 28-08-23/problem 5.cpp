#include <bits/stdc++.h>
#include <tuple>
using namespace std;
int main()
{
    tuple<int, string, double> tx;
    tx = make_tuple(100, "Kamal", 3.5);
    cout << get<0>(tx) << " "
         << get<1>(tx) << " "
         << get<2>(tx) << endl;
    get<2>(tx) = 3.7;
    cout << get<2>(tx) << endl;
    tuple<int, string, double> bx;
    bx = make_tuple(303, "Gayle", 3.97);
    tx.swap(bx);
    cout << get<0>(tx) << " "
         << get<1>(tx) << " "
         << get<2>(tx) << endl;
}