#include <bits/stdc++.h>
using namespace std;
queue<int> ax;
int Menu()
{
    int op;
    cout << "**Queue Menu**" << endl
         << "1. Enqueue" << endl
         << "2. Dequeue" << endl
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
        cout << "Queue is full" << endl;
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
        cout << "Queue is empty\n"
             << endl;
    }
}
void display(queue<int> bx){
    cout<<"Queue: "<<endl;
    while (!bx.empty()){
        cout<<bx.front()<<endl;
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