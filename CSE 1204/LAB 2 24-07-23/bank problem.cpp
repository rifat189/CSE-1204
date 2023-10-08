#include <iostream>
using namespace std;
class Bank
{
private:
    int id;
    float amount;
    static int n;

public:
    // empty constructor to initialize id and amount to 0
    Bank()
    {
        id = 0;
        amount = 0;
        n++;
    }
    Bank(int x, float a)
    {
        id = x;
        amount = a;
        n++;
    }
    Bank(Bank &p)
    {                      //&p is the address of b1
        id = p.id;         // now b1's id has become of b2's id
        amount = p.amount; // now b1's amount has become of b2's amount
        n++;
    }
    void setData(int x, float a)
    {
        id = x;
        amount = a;
    }
    void changeData(float a)
    {
        amount = amount + a;
    }
    int getN()
    {
        return n;
    }
    float getAmount()
    {
        return (amount);
    }
    void display() const
    {
        cout << "Id: " << id << endl;
        cout << "Amount: " << amount << endl;
        cout << "Total Clients: " << n << endl;
    }
};
int Bank::n = 0;
int main()
{
    Bank b1(1, 400);
    b1.display();
    // Bank b2(b1);
    Bank b2(2, 200);
    b2.display();
    Bank b3;
    b3.setData(3, 500);
    b3.display();
    b3.changeData(100);
    b3.display();
    Bank b4(4, 50);
    Bank b5(5, 3000);
    float sum;
    sum = b1.getAmount();
    sum += b2.getAmount();
    sum += b3.getAmount();
    sum += b4.getAmount();
    sum += b5.getAmount();
    cout << "sum = " << sum << endl;
    cout << "Total clients: " << b3.getN() << endl;
}