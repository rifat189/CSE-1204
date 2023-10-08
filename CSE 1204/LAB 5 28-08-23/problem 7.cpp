#include <bits/stdc++.h>
using namespace std;
void display(queue<int> bx)
{
    cout << "Queue: " << endl;
    while (!bx.empty())
    {
        cout << bx.front() << endl;
        bx.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> qu;
    qu.push(6);
    qu.push(7);
    qu.push(9);
    qu.push(20);
    qu.pop();
    cout << qu.size() << endl;
    display(qu);
    cout << qu.front() << endl;
    cout << qu.back() << endl;
    if (qu.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }
}