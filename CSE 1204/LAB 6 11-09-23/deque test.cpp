#include <iostream>
#include <deque>
#include <algorithm> //for reverse()
using namespace std;
void display(deque<int> p)
{
    for (auto i : p)
    {
        cout << i << " ";
    }
    cout << endl;
}
void menu(deque<int> qu)
{
    deque<int>::iterator it;
    cout << "***Menu***" << endl
         << "1. Push back" << endl
         << "2. Push Front" << endl
         << "3. Pop Back" << endl
         << "4. Pop Front" << endl
         << "5. Item value using at()" << endl
         << "6. size using size()" << endl
         << "7. Maxsize" << endl
         << "8. IsEmpty" << endl
         << "9. Front item" << endl
         << "10. Back item" << endl
         << "11. Erasing certain index's value" << endl
         << "12. Erasing elements in range" << endl
         << "13. Remove all elements" << endl
         << "14. Display using foreach" << endl
         << "15. Display using iterator" << endl
         << "16. Display using function" << endl
         << "17. Reverse Display" << endl
         << "18. Exit Menu" << endl
         << "Enter your option: " << endl;
    int opt;
    cin >> opt;
    if (opt == 18)
    {
        exit(0);
        system("CLS");
    }
    int value;
    switch (opt)
    {
    case 1:
        cout << "Enter value: ";
        cin >> value;
        qu.push_back(value);
        break;
    case 2:
        cout << "Enter value: ";
        cin >> value;
        qu.push_front(value);
        break;
    case 3:
        qu.pop_back();
        cout << "Item popped" << endl;
        break;
    case 4:
        qu.pop_front();
        cout << "Item popped" << endl;
        break;
    case 5:
        cout << "Enter position: ";
        cin >> value;
        cout << "Value = " << qu.at(value - 1) << endl;
        break;
    case 6:
        cout << "Size = " << qu.size() << endl;
        break;
    case 7:
        cout << "MaxSize = " << qu.max_size() << endl;
        break;
    case 8:
        cout << "IsEmpty = " << qu.empty() << endl;
        break;
    case 9:
        cout << "Front item = " << qu.front() << endl;
        break;
    case 10:
        cout << "Back item = " << qu.back() << endl;
        break;
    case 11:
        it = qu.begin();
        cout << "Enter position: ";
        cin >> value;
        qu.erase(it + value);
        break;
    default:
        break;
    }
}
int main()
{
    deque<int> qu;
    menu(qu);
    cout << "SAYONARA" << endl;
}