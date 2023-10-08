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
int main()
{
    deque<int> qu;
    deque<int>::iterator it;
    qu.push_back(10);
    qu.push_front(20);
    qu.push_back(12);
    qu.push_back(45);
    qu.push_back(89);
    qu.push_back(26);
    qu.push_back(75);
    qu.push_back(74);
    qu.push_back(56);
    qu.pop_back();
    cout << "At 3: " << qu.at(2) << endl
         << "Size: " << qu.size() << endl
         << "MaxSize: " << qu.max_size() << endl
         << "Is empty: " << qu.empty() << endl
         << "Front: " << qu.front() << endl
         << "Back: " << qu.back() << endl;

    qu.pop_front();

    deque<int>::const_iterator citr = qu.cbegin();
    // *citr = 23; // can't be modified as it's const
    while (citr != qu.cend())
    {
        cout << *citr << " ";
        ++citr;
    }
    cout << endl;

    // erasing certain index's value
    cout << "erasing certain index's value" << endl;
    it = qu.begin();
    qu.erase(it + 1); // can be done without using iterator
    display(qu);

    // erasing element in certain range
    cout << "erasing element in certain range" << endl;
    qu.erase(qu.begin() + 1, qu.begin() + 3); // index 1 - 2
    display(qu);

    // removing all elements
    // qu.clear();

    it = qu.begin();
    *it = 23; // can be modified

    // display method 1
    cout<<"display method 1"<<endl;
    for (auto i : qu)
    {
        cout << i << " ";
    }
    cout << endl;

    // display method 2
    cout<<"display method 2"<<endl;
    it = qu.begin();
    for (auto i = it; i != qu.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // display method 3
    cout<<"display method 3"<<endl;
    display(qu);

    // rbegin() and rend()
    cout<<"reverse displaying"<<endl;
    for (auto i = qu.rbegin(); i != qu.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // reversing the values
    // cout<<"reversing the values"<<endl;
    // reverse(qu.rbegin(), qu.rend()); //<algorithm>
    // display(qu);

    // removing all elements
    cout << "removing all elements" << endl;
    qu.clear();
    display(qu);
}