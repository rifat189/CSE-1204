#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Queue
{
    queue<int> ax;

public:
    void pushItem()
    {
        int x;
        cout << "Enter the element to be pushed : ";
        cin >> x;
        ax.push(x);
        cout << x << " has been pushed to the queue" << endl;
        display();
    }
    void popItem()
    {
        if (ax.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << ax.front() << " has been popped to the queue" << endl;
        ax.pop();
        display();
    }
    void display()
    {
        queue<int> bx = ax;
        // int i =
        // cout<<"size = "<<bx.size()<<endl;
        while (!bx.empty())
        {
            //cout<<"in"<<endl;
            cout << bx.front() << " ";
            bx.pop();
        }
        cout << endl;
    }
};
void menu(Queue &q)
{
    system("CLS");
    int op;
    cout << "***Queue Menu***" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Display" << endl
         << "4. Exit" << endl
         << "\tEnter any number: ";
    cin >> op;
    if (op == 4)
    {
        exit(0);
        system("CLS");
    }
    switch (op)
    {
    case 1:
        q.pushItem();
        break;
    case 2:
        q.popItem();
        break;
    case 3:
        q.display();
        break;
    }
    system("pause");
    menu(q);
}
int main()
{
    Queue q;
    menu(q);
    return 0;
}
