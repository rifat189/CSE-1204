#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
// void Load_Data()
// {
//     ifstream inputFile("cred.txt");

//     if(inputFile.is_open())
//     { 
//         Member *TempUser;
//         while(inputFile >> TempUser->name >> TempUser->mobile >> TempUser->pin >> TempUser->balance)
//         {
//             Member.push_back(TempUser);
//         }
//         inputFile.close();
//     }
//     else
//     {
//         cerr << "Unable to open file for reading." << endl;
//     }
    
// }

// void Write_Data(Member User)
// {
//     ofstream outputFile("cred.txt", ofstream::app);

//     User->Balance = 0;

//     if(outputFile.is_open())
//     {
//         outputFile << User.UserName << " " << User.UserPhone << " " << User.Password << " " << User.Balance << endl;
//     }
//     else
//     {
//         cerr << "Unable to open file for writing." << endl;
//     }
//     outputFile.close();
// }

int verifyOTP(int r)
{
    int a;
    cout << "Give the OTP: ";
    cin >> a;
    if (a == r)
        return 1;
    else
        return 0;
}
int generateOTP()
{
    srand((unsigned)time(0));
    int r = 10000 + (rand() * rand() % 99999);
    cout << "MyCash OTP: " << r << endl;
    // verifyOTP(r);
    return r;
}

class Member
{
public:
    string mobile;
    string name;
    string pin;
    double balance;

    Member(const string &m, const string &n, const string &p)
        : mobile(m), name(n), pin(p), balance(100.0) {}

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
        if (getMemberByMobile(mobile))
        {
            cout << "Already Exists" << endl;
        }
        else
        {
            cout << "Enter name: ";
            cin >> name;

            cout << "Enter pin: ";
            cin >> pin;
            string confPin;
            cout << "Confirm Pin: ";
            cin >> confPin;
            if (pin != confPin)
            {
                cout << "Input pin doesn't match";
            }
            // otp generation
            if (verifyOTP(generateOTP()))
            {
                addMember(mobile, name, pin);
            }
            else
            {
                cout << "Invalid OTP" << endl;
            }
            // if succeeds
        }
    }

    void updateAc(string &mobile)
    {
        // cout << mobile << endl;
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string newName, newPin, confPin;
            cout << "Current Name: " << member->name << endl;
            cout << "New Name (Press 'Enter' to ignore): ";
            getchar();
            getline(cin, newName);

            cout << "Current pin: " << member->pin << endl;
            cout << "New Pin (Press 'Enter' to ignore): ";
            getchar();
            getline(cin, newPin);

            cout << "Confirm Pin: ";
            cin >> confPin;
            if (confPin != newPin)
            {
                cout << "Pin is incorrect" << endl;
            }
            else
            {
                if (!newName.empty())
                {
                    member->name = newName;
                }
                if (!newPin.empty())
                {
                    member->pin = newPin;
                }
                cout << "Updated name: " << member->name << endl
                     << endl;
                cout << "Updated Pin: " << member->pin << endl
                     << endl;
            }
        }
        accountMenu(mobile);
    }

    void removeAc(string &mobile)
    {
        // cout << mobile << endl;
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string pin;
            cout << "Enter Pin to coutinue: ";
            cin >> pin;
            if (pin != member->pin)
            {
                cout << "Password incorrect" << endl;
            }
            else
            {
                char conf;
                cout << "Do you want to remove your account? (Y/N) : ";
                cin >> conf;
                if (conf == 'Y' || conf == 'y')
                {
                    // proceed
                    member = nullptr;
                }
                else if (conf == 'N' || conf == 'n')
                {
                    // proceed
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
        }
        accountMenu(mobile);
    }

    void sendMoney(string &mobile)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string receiverMobile;
            double amount;
            cout << "Account number to send money: ";
            cin >> receiverMobile;
            Member *receiver = getMemberByMobile(receiverMobile);
            if (mobile == receiverMobile)
            {
                cout << "The sender and receiver cannot be same" << endl;
            }
            else if (getMemberByMobile(receiverMobile) == nullptr)
            {
                cout << "The destination number doesn't exist" << endl;
            }
            else
            {
                char conf;
                cout << "Amount: ";
                cin >> amount;
                if (amount > member->balance)
                {
                    cout << "Insuffient amount" << endl;
                }
                else
                {
                    cout << "Are you sure? (Y/N) :";
                    cin >> conf;
                    if (conf == 'Y' || conf == 'y')
                    {
                        receiver->balance += amount;
                        member->balance -= amount;
                        cout << "receiver: " << receiver->balance << endl;
                        cout << "member: " << member->balance << endl;
                        accountMenu(mobile);
                    }
                    else if (conf == 'N' || conf == 'n')
                    {
                        // proceed
                    }
                    else
                    {
                        cout << "Invalid input" << endl;
                    }
                }
            }
        }
    }

    void cashIn(string &mobile)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string pin;
            double cashInAmount;
            cout << "Amount to cash-in: ";
            cin >> cashInAmount;
            cout << "Enter pin to confirm: ";
            cin >> pin;
            if (pin != member->pin)
            {
                cout << "Incorrect Pin" << endl;
            }
            else
            {
                member->balance += cashInAmount;
                cout << "Cash In completed" << endl;
                accountMenu(mobile);
            }
        }
    }

    void cashOut(string &mobile)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string pin;
            double cashOutAmount;
            cout << "Amount to cash-out: ";
            cin >> cashOutAmount;
            cout << "Enter pin to confirm: ";
            cin >> pin;
            if (pin != member->pin)
            {
                cout << "Incorrect Pin" << endl;
            }
            else if (cashOutAmount > member->balance)
            {
                cout << "Insufficient Balance" << endl;
            }
            else
            {
                member->balance -= cashOutAmount;
                cout << "Cash Out completed" << endl;
                accountMenu(mobile);
            }
        }
    }
    void payBill(string &mobile, const string &desc)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            double amount;
            string pin;
            cout << "Enter your " << desc << " amount: ";
            cin >> amount;
            if (amount > member->balance)
                cout << "Insuffient balance" << endl;
            cout << "Enter pin to confirm: ";
            cin >> pin;
            if (pin != member->pin)
                cout << "Incorrect Pin";
            else
            {
                char conf;
                cout << "Are you sure? (Y/N): ";
                cin >> conf;
                if (conf == 'Y' || conf == 'y')
                {
                    member->balance -= amount;
                    cout << desc << " paid successfully" << endl;
                    payBillMenu(mobile);
                }
            }
        }
    }
    void payBillMenu(string &mobile)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            cout << "Choose one - " << endl
                 << "1. Internet Bill" << endl
                 << "2. Electricity Bill" << endl
                 << "3. Water Bill" << endl
                 << "4. Gas Bill" << endl
                 << "5. Go Back to menu" << endl
                 << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 5)
                accountMenu(mobile);
            switch (choice)
            {
            case 1:
                payBill(mobile, "Internet Bill");
                break;
            case 2:
                payBill(mobile, "Electricity Bill");
                break;
            case 3:
                payBill(mobile, "Water Bill");
                break;
            case 4:
                payBill(mobile, "Gas Bill");
                break;
            default:
                break;
            }
        }
    }
    void checkBalance(string &mobile)
    {
        Member *member = getMemberByMobile(mobile);
        if (member != nullptr)
        {
            string pin;
            cout << "Enter pin to see balance: ";
            cin >> pin;
            if (pin != member->pin)
            {
                cout << "Incorrect Pin" << endl;
            }
            else
            {
                cout << "Current Balance: " << member->balance << endl;
            }
        }
    }
    void accountMenu(string &mobile)
    {
        // cout<<mobile<<endl;

        int choice;
        cout << "***MyCash Menu***" << endl
             << "1. Update account" << endl
             << "2. Remove account" << endl
             << "3. Send Money" << endl
             << "4. Cash-in" << endl
             << "5. Cash-out" << endl
             << "6. Pay Bill" << endl
             << "7. Check Balance" << endl
             << "8. History" << endl
             << "9. Log out" << endl
             << "Enter your option: ";
        cin >> choice;
        if (choice == 9)
        {
            menu();
        }
        switch (choice)
        {
        case 1:
            updateAc(mobile);
            break;
        case 2:
            removeAc(mobile);
            break;
        case 3:
            sendMoney(mobile);
            break;
        case 4:
            cashIn(mobile);
            break;
        case 5:
            cashOut(mobile);
            break;
        case 6:
            payBillMenu(mobile);
            break;
        case 7:
            checkBalance(mobile);
            break;
        }
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
            accountMenu(mobile);
        }
        else
        {
            cout << "Login failed. Invalid mobile number or pin." << endl;
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
            cout << "3. Exit" << endl;
            cout << "Enter your option: ";
            cin >> menuOp;
            if (menuOp == 3)
            {
                cout << "Closing the app" << endl;
                exit(0);
                system("CLS");
            }
            switch (menuOp)
            {
            case 1:
                memberLogin();
                break;
            case 2:
                memberReg();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
            }
        } while (menuOp != 5);
    }
};

class TransactionDetails
{
public:
    string UserPhoneNumber;
    int Trans_ID;
    string Description;
    int Amount = 0;
};

vector<Member> allMembers;
vector<TransactionDetails> allTransactions;

Member* member = nullptr;

void Write_History(string &mobile, int Tran_ID, const string &Desc, int Amount)
{
    //Member *member = Wallet::getMemberByMobile(mobile);
    TransactionDetails NewTransaction;

    NewTransaction.UserPhoneNumber = member->mobile; // userphone-->mobile
    NewTransaction.Trans_ID = Tran_ID;
    NewTransaction.Description = Desc;
    NewTransaction.Amount = Amount;

    allTransactions.push_back(NewTransaction);

    ofstream outputFile("tran.txt", ofstream::app);

    if (outputFile.is_open())
    {
        outputFile << member->mobile << " " << Tran_ID << " " << Desc << " " << Amount << endl;
        outputFile.close();
    }
    else
    {
        cerr << "Unable to open file for writing." << endl;
    }
}

void Load_History()
{

    ifstream inputFile("tran.txt");

    if (inputFile.is_open())
    {
        TransactionDetails TempTrans;

        while (inputFile >> TempTrans.UserPhoneNumber >> TempTrans.Trans_ID >> TempTrans.Description >> TempTrans.Amount)
        {
            allTransactions.push_back(TempTrans);
        }
        inputFile.close();
    }
    else
    {
        cerr << "Unable to open file for reading." << endl;
    }
}

int main()
{

    Wallet wallet;
    wallet.menu();

    return 0;
}
