#include <bits/stdc++.h>
using namespace std;
vector<int> ax;
void mainMenu();
void display(vector<int> bx)
{
    cout << "list = ";
    for (auto x : bx)
    {
        cout << x << " ";
    }
    cout << endl;
}
void insertMenu()
{
    system("CLS");

    vector<int>::iterator p;
    int op1;
    cout << "***Insert Menu***" << endl
         << "1. Insert At the beginning" << endl
         << "2. Insert at the ending" << endl
         << "3. Insert after " << endl
         << "4. Insert before " << endl
         << "5. Back to main menu" << endl
         << "\tEnter any number: ";
    cin >> op1;
    if (op1 == 5)
        mainMenu();
    int a;
    cout << "Enter value: ";
    cin >> a;
    int pos;
    switch (op1)
    {
    case 1:
        p = ax.begin();
        ax.insert(p, a);
        display(ax);
        break;
    case 2:
        p = ax.end();
        ax.insert(p, a);
        display(ax);
        break;
    case 3:
        cout << "After which position: ";
        cin >> pos;
        p = ax.begin();
        ax.insert(p + pos, a);
        display(ax);
        break;
    case 4:
        cout << "Before which position: ";
        cin >> pos;
        p = ax.begin();
        ax.insert(p + pos - 1, a);
        display(ax);
        break;
    }
    system("pause");
    insertMenu();
}
void deleteItem()
{
    system("CLS");

    vector<int>::iterator p;
    int op1;
    cout << "***Delete Menu***" << endl
         << "1. Delete At Position" << endl
         << "2. Back to main menu" << endl
         << "\tEnter any number: ";
    cin >> op1;
    if (op1 == 2)
        mainMenu();
    switch (op1)
    {
    case 1:
        p = ax.begin();
        int pos;
        cout << "Enter position that to be deleted: " << endl;
        cin >> pos;
        // cout << *p << endl;
        ax.erase(p + pos - 1);
        display(ax);
        break;
    }
    system("pause");
    deleteItem();
}
void searchItem()
{
    system("CLS");

    vector<int>::iterator p;
    int op1;
    cout << "***Search Menu***" << endl
         << "1. Search by value" << endl
         << "2. Search by position" << endl
         << "3. Back to main menu" << endl
         << "\tEnter any number: ";
    cin >> op1;
    if (op1 == 3)
        mainMenu();
    switch (op1)
    {
    case 1:
        p = ax.begin();
        int value;
        cout << "Enter value: " << endl;
        cin >> value;
        // cout << *p << endl;
        for (int i = 0; i < ax.size(); i++)
        {
            // cout << "in" << endl;
            if (ax[i] == value)
            {
                cout << "The position is: " << i + 1 << endl;
                break;
            }
        }
        
        // display(ax);
        break;
    case 2:
        p = ax.begin();
        int pos;
        cout << "Enter position: " << endl;
        cin >> pos;
        if(pos>ax.size()){
               cout<<"Invalid Position"<<endl;
        }
        else
            cout<<"The value is "<<ax[pos-1]<<endl;
        break;
    }
    system("pause");
    searchItem();
}
void mainMenu()
{
    system("CLS");
    int op;
    cout << "***Main Menu***" << endl
         << "1. Insert" << endl
         << "2. Delete" << endl
         << "3. Search" << endl
         << "4. Display" << endl
         << "5. Exit" << endl
         << "\tEnter any number: ";
    cin >> op;
    switch (op)
    {
    case 1:
        insertMenu();
        break;
    case 2:
        deleteItem();
        break;
    case 3:
        searchItem();
        break;
    case 4:
        display(ax);
        break;
    }
    system("pause");
}
int main()
{
    mainMenu();
    return 0;
}