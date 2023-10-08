#include <iostream>
#include <conio.h>
using namespace std;
struct Member
{
    int id;
    float height;
    float weight;
    bool exist;
};
int total = 0;
struct Member mx[10000];
int menu()
{
    int op;
    cout << "******Main Menu*****" << endl;
    cout << "1. Add Member" << endl;
    cout << "2. Update Member" << endl;
    cout << "3. Remove Member" << endl;
    cout << "4. Max Height and Weight" << endl;
    cout << "5. Min Height and Weight" << endl;
    cout << "6. Average Height and Weight" << endl;
    cout << "7. BMI Classification" << endl;
    cout << "8. Display all" << endl;
    cout << "9. Exit" << endl;
    cout << "   Enter Your Option(1-8): ";
    cin >> op;
    return (op);
}
int serial(int y)
{
    int index = -1;
    for (int i = 0; i < total; i++)
    {
        if (y == mx[i].id)
        {
            index = i;
        }
    }
    return index;
}
int searchMember(int y)
{
    int i;
    int flag = -1;
    for (i = 0; i < total; i++)
    {
        if (mx[i].id == y)
        {
            //cout << "found" << endl;
            flag = 1;
        }
    }
    return flag;
}
int searchMember2(int y)
{
    int i;
    int flag = -1;
    for (i = 0; i <= total; i++)
    {
        if (mx[i].id == y)
        {
            //cout << "found" << endl;
            flag = 1;
        }
    }
    return flag;
}
void addMember()
{
    total++;
    cout << "Enter ID: ";
    cin >> mx[total].id;
    int check = searchMember(mx[total].id);
    if (check != 1)
    {
        cout << "Enter Height: ";
        cin >> mx[total].height;
        cout << "Enter Weight: ";
        cin >> mx[total].weight;
        mx[total].exist = true;
    }
    else
    {
        total--;
        cout << "Already exist" << endl;
    }
    getch();
}
void updateMember()
{
    int x, idx;
    cout << "Enter Member ID: " << endl;
    cin >> x;
    total++;
    idx = searchMember(x);
    int serialno = serial(x);
    if (idx != 1)
    {
        cout << "Sorry Member NOT found..." << endl;
    }
    else
    {
        cout << "Enter new height: " << endl;
        cin >> mx[serialno].height;
        cout << "Enter new weight: " << endl;
        cin >> mx[serialno].weight;
        total--;
    }
    getch();
}

void removeMember()
{
    int x, idx;
    cout << "Enter Member ID: " << endl;
    cin >> x;
    total++;
    idx = searchMember(x);
    total--;
    int serialno = serial(x);
    if (idx != 1)
    {
        cout << "Sorry Member NOT found..." << endl;
    }
    else
    {
        for (int i = serialno; i <= total; i++)
        {
            mx[serialno].id = mx[serialno + 1].id;
            mx[serialno].height = mx[serialno + 1].height;
            mx[serialno].weight = mx[serialno + 1].weight;
        }
        total--;
    }
    getch();
}
void maxHeightWeight()
{
    float maxHeight = mx[1].height;
    float maxWeight = mx[1].weight;
    int maxHeightId = mx[1].id, maxWeightId = mx[1].id;
    for (int i = 2; i <= total; i++)
    {
        if (mx[i].height > maxHeight)
        {
            maxHeight = mx[i].height;
            maxHeightId = mx[i].id;
        }
        if (mx[i].weight > maxWeight)
        {
            maxWeight = mx[i].weight;
            maxWeightId = mx[i].id;
        }
    }
    cout << "Maximum Height: " << maxHeight << " is of member id: " << maxHeightId << endl;
    cout << "Maximum Weight: " << maxWeight << " is of member id: " << maxWeightId << endl;

    getch();
}
void minHeightWeight()
{
    float minHeight = mx[1].height;
    float minWeight = mx[1].weight;
    int minHeightId = mx[1].id, minWeightId = mx[1].id;
    for (int i = 2; i <= total; i++)
    {
        if (mx[i].height < minHeight)
        {
            minHeight = mx[i].height;
            minHeightId = mx[i].id;
        }
        if (mx[i].weight < minWeight)
        {
            minWeight = mx[i].weight;
            minWeightId = mx[i].id;
        }
    }
    cout << "Minimum height: " << minHeight << " is of member index " << minHeightId << endl;
    cout << "Minimum weight: " << minWeight << " is of member index " << minWeightId << endl;

    getch();
}
void avgHeightWeight()
{
    float totalHeight = 0, totalWeight = 0;
    for (int i = 1; i <= total; i++)
    {
        totalHeight += mx[i].height;
        totalWeight += mx[i].weight;
    }
    float avgHeight = totalHeight / (float)total;
    float avgWeight = totalWeight / (float)total;
    cout << "Avg Height: " << avgHeight << endl;
    cout << "Avg Weight: " << avgWeight << endl;
    getch();
}
void bmi()
{
    int x, idx;
    cout << "Enter Member ID: " << endl;
    cin >> x;
    total++;
    idx = searchMember(x);
    int serialno = serial(x);
    total--;
    if (idx != 1)
    {
        cout << "Sorry Member NOT found..." << endl;
    }
    else
    {
        float target_height = mx[serialno].height;
        float target_weight = mx[serialno].weight;
        cout << (mx[serialno].height) << endl;
        float bmi = (target_weight) / (target_height * target_height);
        cout << "BMI: " << bmi << endl;
        cout << "BMI Classification: ";
        if (bmi < 16)
            cout << "Severe Thinness" << endl;
        if (bmi >= 16 && bmi <= 17)
            cout << "Moderate Thinness" << endl;
        if (bmi >= 17 && bmi <= 18.5)
            cout << "Mild Thinness" << endl;
        if (bmi >= 18.5 && bmi <= 25)
            cout << "Normal" << endl;
        if (bmi >= 25 && bmi <= 30)
            cout << "Overweight" << endl;
        if (bmi >= 30 && bmi <= 35)
            cout << "Obese Class I" << endl;
        if (bmi >= 35 && bmi <= 40)
            cout << "Obese Class II" << endl;
        if (bmi > 40)
            cout << "Obese Class III" << endl;
    }
    getch();
}
void displayAll()
{
    cout << "SL.\tID\tHEI.\tWEI." << endl;
    for (int i = 0; i <= total; i++)
    {
        if (mx[i].exist == true)
        {
            cout << i << "\t" << mx[i].id << "\t" << mx[i].height << "\t" << mx[i].weight << endl;
        }
    }
    getch();
}
int main()
{
    int option;

    while (true)
    {
        option = menu();
        switch (option)
        {
        case 1:
            addMember();
            break;
        case 2:
            updateMember();
            break;
        case 3:
            removeMember();
            break;
        case 4:
            maxHeightWeight();
            break;
        case 5:
            minHeightWeight();
            break;
        case 6:
            avgHeightWeight();
            break;
        case 7:
            bmi();
            break;
        case 8:
            displayAll();
            break;
        case 9:
            cout << "End of program Run....";
            exit(0);
            break;
            getch();
        default:
            cout << "Not available";
            exit(0);
            break;
        }
    }
}
