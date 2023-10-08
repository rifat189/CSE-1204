#include <iostream>
using namespace std;
struct member
{
    string mobile;
    string pin;
    string name;
    int amount;
} acc[1000];
void login();
void regstr();
void menu(string, string);
void displayAll();
void update(string, string);
void remove(string, string);

int total = 0;

void menu(string givenNumber, string givenPin, int index)
{
    int menuOption;
    cout << "****MENU****" << endl
         << "1. Update Me" << endl
         << "2. Remove Me" << endl
         << "3. Send Money" << endl
         << "4. Cash - in" << endl
         << "5. Cash - out" << endl
         << "6. Pay Bill" << endl
         << "7. Check Balance" << endl
         << "8. History" << endl
         << "9. Logout" << endl
         << "Enter Your Option(1 - 9) : " << endl;
    cin >> menuOption;
    index;
    switch (menuOption)
    {
    case 1:
        update(givenNumber, givenPin, index);
        break;
    case 2:
        remove(givenNumber, givenPin, index);
        break;
    default:
        break;
    }
}

void regstr()
{
    total++;
    string confPin;
    cout << "Enter Mobile No. (11 digit): " << endl;
    cin >> acc[total].mobile;
    cout << "Enter Name: " << endl;
    cin >> acc[total].name;
    cout << "Enter pin: " << endl;
    cin >> acc[total].pin;
    cout << "Reconfirm pin: " << endl;
    cin >> confPin;
    if (acc[total].pin == confPin)
    {
        cout << "wiii...Registration is successful" << endl;
        main();
    }
    else
    {
        cout << "Oops!! pin is wrong" << endl
             << "Try again" << endl;
        cin.ignore();
        regstr();
    }
}
void login()
{
    string givenNumber, givenPin;
    int serial;
    cout << "Enter Mobile No. (11 digit): " << endl;
    cin >> givenNumber;
    for (int i = 1; i <= total; i++)
    {
        if (acc[i].mobile == givenNumber)
        {
            serial = i;
        }
    }
    // cin >> acc[total].mobile;
    cout << "Enter pin: " << endl;
    cin >> givenPin;
    if (acc[serial].pin == givenPin)
    {
        cout << "wiii...Login is successful" << endl;
        menu(givenNumber, givenPin, serial);
    }
}


void update(string givenNumber, string givenPin, int index)
{
    cout << "Enter new number: " << endl;
    cin >> acc[index].mobile;
    cout << "Enter new name: " << endl;
    cin >> acc[index].name;
    cout << "Enter new pin: " << endl;
    cin >> acc[index].pin;
    cout << "We're done, Boss" << endl;
    displayAll();
    menu(givenNumber, givenPin, index);
}

void remove(string givenNumber, string givenPin, int index)
{
    char ch;
    cout << "Are you sure to remove this account(y/n): " << endl;
    cin >> ch;
    if (ch == 'y')
    {
        acc[index].mobile="0";
        acc[index].pin="0";
        acc[index].name="--";
    }
    else
    {
        displayAll();
        menu(givenNumber, givenPin, index);
    }
}
void displayAll()
{
    printf("hiii");
    for (int i = 1; i <= total; i++)
    {
        cout << acc[i].name << "\t";
        cout << acc[i].mobile << "\t";
        cout << acc[i].pin << "\t\n";
    }
}

int main()
{
    int a;
    // struct member acc[1000];
    cout << "***MyCash***\n1. Login\n2. Register\n3. Exit\n Enter Your option: ";
    cin >> a;
    switch (a)
    {
    case 1:
        login();
        break;
    case 2:
        regstr();
        break;
    case 3:
        exit(0);
        break;
    case 4:
        displayAll();
        break;
    default:
        exit(0);
        break;
    }
}
