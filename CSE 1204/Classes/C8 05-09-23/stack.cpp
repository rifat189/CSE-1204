#include <bits/stdc++.h>
using namespace std;
stack<int> ax;
int Menu()
{
    int op;
    cout << "**Stack Menu**" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Display" << endl
         << "4. Exit" << endl
         << "\tEnter your option: ";
    cin >> op;
    return (op);
}
void itemPush()
{
    int x;
    if (ax.size() < 3)
    {
        cout << "Enter your item: ";
        cin >> x;
        ax.push(x);
        cout << "Push Successful\n"
             << endl;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}
void pop()
{
    if (!ax.empty())
    {
        ax.pop();
        cout << "Pop Successful\n"
             << endl;
    }
    else
    {
        cout << "Stack is empty\n"
             << endl;
    }
}
void display(stack<int> bx){
    cout<<"Stack: "<<endl;
    while (!bx.empty()){
        cout<<bx.top()<<endl;
        bx.pop();
    }
    cout<<endl;
}
int main()
{
    int op;
    for (;;)
    {
        op = Menu();
        if (op == 4)
            break;
        switch (op)
        {
        case 1:
            itemPush();
            break;
        case 2:
            pop();
            break;
        case 3:
            display(ax);
            break;
        }
    }
}