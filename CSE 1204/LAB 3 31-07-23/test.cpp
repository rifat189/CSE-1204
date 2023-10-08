#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Member
{
public:
    string mobile;
    string name;
    string pin;
    double balance;

    Member(const string &m, const string &n, const string &p)
        : mobile(m), name(n), pin(p), balance(0.0) {}

    void displayInfo() const
    {
        cout << "Mobile: " << mobile << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

class Wallet
{
private:
    vector<Member> members;

public:
    void addMember(const string &mobile, const string &name, const string &pin)
    {
        Member newMember(mobile, name, pin);
        members.push_back(newMember);
        cout << "Member registered successfully!" << endl;
    }

    Member *getMemberByMobile(const string &mobile)
    {
        for (auto &member : members)
        {
            if (member.mobile == mobile)
            {
                return &member;
            }
        }
        return nullptr;
    }

    void memberReg()
    {
        string mobile, name, pin;

        cout << "Enter mobile number: ";
        cin >> mobile;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter pin: ";
        cin >> pin;

        addMember(mobile, name, pin);
    }

    void memberLogin()
    {
        string mobile, pin;

        cout << "Enter mobile number: ";
        cin >> mobile;

        cout << "Enter pin: ";
        cin >> pin;

        Member *member = getMemberByMobile(mobile);
        if (member != nullptr && member->pin == pin)
        {
            cout << "Login successful!" << endl;
            member->displayInfo();
        }
        else
        {
            cout << "Login failed. Invalid mobile number or pin." << endl;
        }
    }

    void saveDataToFile(const string &filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &member : members)
            {
                file << member.mobile << "," << member.name << "," << member.pin << endl;
            }
            file.close();
            cout << "Data saved to file successfully!" << endl;
        }
        else
        {
            cout << "Error opening file for saving data!" << endl;
        }
    }

    void loadDataFromFile(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            members.clear();
            string line;
            while (getline(file, line))
            {
                string mobile, name, pin;
                istringstream iss(line);
                getline(iss, mobile, ',');
                getline(iss, name, ',');
                getline(iss, pin, ',');
                addMember(mobile, name, pin);
            }
            file.close();
            cout << "Data loaded from file successfully!" << endl;
        }
        else
        {
            cout << "Error opening file for loading data!" << endl;
        }
    }

    void menu()
    {
        int menuOp;
        do
        {
            cout << "**Wallet Menu**" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            // cout << "3. Save Data to File" << endl;
            // cout << "4. Load Data from File" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your option: ";
            cin >> menuOp;

            switch (menuOp)
            {
            case 1:
                memberLogin();
                break;
            case 2:
                memberReg();
                break;
            case 3:
            {
                string filename;
                cout << "Enter filename to save data: ";
                cin >> filename;
                saveDataToFile(filename);
                break;
            }
            case 4:
            {
                string filename;
                cout << "Enter filename to load data: ";
                cin >> filename;
                loadDataFromFile(filename);
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
            }
        } while (menuOp != 5);
    }
};

int main()
{
    Wallet wallet;
    wallet.menu();

    return 0;
}
