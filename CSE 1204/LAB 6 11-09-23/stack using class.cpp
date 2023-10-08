#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Stack
{
    stack<int> ax;

public:
    void pushItem()
    {
        int x;
        cout << "Enter the element to be pushed : ";
        cin >> x;
        ax.push(x);
        cout << x << " has been pushed to the stack" << endl;

        display();
    }
    void popItem()
    {
        cout << ax.top() << " has been popped to the stack" << endl;
        ax.pop();
        display();
    }
    void display()
    {
        stack<int> bx = ax;
        while (!bx.empty())
        {
            cout << bx.top() << " ";
            bx.pop();
        }
        cout << endl;
    }

};
void menu(Stack s)
{
    system("CLS");
    int op;
    cout << "***Stack Menu***" << endl
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
        s.pushItem();
        break;
    case 2:
        s.popItem();
        break;
    case 3:
        s.display();
        break;
    }
    system("pause");
    menu(s);
}
int main()
{
    Stack s;
    menu(s);
    return 0;
}
