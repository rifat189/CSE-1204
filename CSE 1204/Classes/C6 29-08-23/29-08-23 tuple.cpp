#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x; string y; float z;
   tuple<int, string, float> a;
    a=make_tuple(1, "John", 500.3);
    tie(x, y, z)=a;
    cout<<x<<" "<<y<<" "<<z<<endl;
    tie(x, y, ignore)=a;
    cout<<x<<" "<<y<<" "<<z<<endl;
    // get<2>(a)=600;
    // cout<<get<2>(a)<<endl;
    return 0;
}