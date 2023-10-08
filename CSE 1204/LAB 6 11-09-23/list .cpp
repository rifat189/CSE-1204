#include <iostream>
#include <list>
#include <algorithm> //find()
#include <iterator>
using namespace std;
void display(list<int> p)
{
    cout << "Display: ";
    for (auto i : p)
    {
        cout << i << " ";
    }
    cout << endl;
}
bool isEven(int x)
{
    return (x % 2 == 0);
}
void menu(list<int> li)
{
    system("CLS");
    cout << "Menu: " << endl
         << "1. Push Back" << endl
         << "2. Push Front" << endl
         << "3. Pop Back" << endl
         << "4. Pop Front" << endl
         << "5. Display Front" << endl
         << "6. Display Back" << endl
         << "7. Find an element" << endl
         << "8. Insert before" << endl
         << "9. Insert after" << endl
         << "10. Count" << endl
         << "11. Count with condition (even numbers)" << endl
         << "12. Erase an element" << endl
         << "13. Erase first 4 elements" << endl
         << "14. Delete using remove()" << endl
         << "15. Delete using particular condition (even numbers)" << endl
         << "16. Assign from list" << endl
         << "17. Assign from array" << endl
         << "18. Sort" << endl
         << "19. Delete consecutive similar elements" << endl
         << "20. Display" << endl
         << "21. Display using begin() and end()" << endl
         << "22. Reverse display" << endl
         << "23. Reverse display using rbegin() and rend()" << endl
         << "24. Exit" << endl
         << "Enter Option: ";
    int opt;
    cin >> opt;
    if (opt == 24)
    {
        exit(0);
        system("CLS");
    }

    int value;
    list<int>::iterator itr, ptr;
    switch (opt)
    {
    case 1: // push back
        cout << "Enter value: ";
        cin >> value;
        li.push_back(value);
        break;
    case 2: // push front
        cout << "Enter value: ";
        cin >> value;
        li.push_front(value);
        break;
    case 3: // pop back
        li.pop_back();
        break;
    case 4: // pop front
        li.pop_front();
        break;
    case 5: // display front
        cout << "Front: " << li.front() << endl;
        break;
    case 6: // display back
        cout << "Back: " << li.back() << endl;
        break;
    case 7: // find an element
        cout << "Enter value: ";
        cin >> value;
        itr = find(li.begin(), li.end(), value);
        cout << "Found value: " << *itr << endl;
        break;
    case 8: // insert before
        cout << "Enter before which value you want to insert: ";
        cin >> value;

        itr = find(li.begin(), li.end(), value);
        if (itr == li.end())
            cout << "not found" << endl;
        else
        {
            cout << "Enter the value you want to insert: ";
            int insertVal;
            cin >> insertVal;
            li.insert(itr, insertVal);
            cout << "Inserted" << endl;
        }
        break;
    case 9: // insert afer
        cout << "Enter after which value you want to insert: ";
        cin >> value;

        itr = find(li.begin(), li.end(), value);
        if (itr == li.end())
            cout << "not found" << endl;
        else
        {
            cout << "Enter the value you want to insert: ";
            int insertVal;
            cin >> insertVal;
            advance(itr, 1);
            li.insert(itr, insertVal);
            cout << "Inserted" << endl;
        }
        break;
    case 10: // count
        cout << "Enter the value to count: ";
        cin >> value;
        cout << "Count: " << count(li.begin(), li.end(), value) << endl;
        break;
    case 11: // count with condition
        int x;
        x = count_if(li.begin(), li.end(), isEven);
        cout << "Ever Number Count: " << x << endl;
        break;
    case 12: // Erase an element
        cout << "Enter a value: ";
        cin >> value;
        itr = find(li.begin(), li.end(), value);
        li.erase(itr);
        cout << "Deleted" << endl;
        break;
    case 13: // Erase 4 elements
        itr = li.begin();
        ptr = li.begin();
        advance(ptr, 3);
        li.erase(itr, ptr);
        cout << "Deleted" << endl;
        break;
    case 14: // Delete using remove()
        cout << "Enter a value: ";
        cin >> value;
        li.remove(value);
        cout << "Deleted" << endl;
        break;
    case 15: // Delete using a particular condition
        li.remove_if(isEven);
        cout << "Even Numbers Deleted" << endl;
        break;
    case 16: // assign from list
    case 17: // assign from array
    case 18: // sort
        li.sort();
        cout << "Sorted" << endl;
        break;
    case 19: // delete consecutive similar elements
        li.sort();
        li.unique();
        cout << "Deletion complete" << endl;
        break;
    case 20: // display
        display(li);
        break;
    case 21: // display begin(), end()
        for (auto i = li.begin(); i != li.end(); i++)
        {
            cout << *i << " ";
        }
        break;
    case 22: // reverse display
        reverse(li.begin(), li.end());
        display(li);
        break;
    case 23: // reverse display using rbegin(), rend()
        for (auto i = li.rbegin(); i != li.rend(); i++)
        {
            cout << *i << " ";
        }
        break;
    default:
        break;
    }
    system("pause");
    menu(li);
}

int main()
{
    list<int> li;
    menu(li);
}