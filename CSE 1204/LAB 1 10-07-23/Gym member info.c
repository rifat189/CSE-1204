#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define totMem 999999

void addMem();
void updateMember();
void removeMember();
void max();
void min();
void avg();
void bmi();

struct memInfo
{
    int id;
    float height;
    float weight;
} member[999999];

void reset()
{

    char ch;
    printf("Continue? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

int main()
{
    int n;
    printf("***** Main Menu *****\n1. Add Member\n2. Update Member\n3. Remove Member\n4. Max Height & Weight\n5. Min Height & Weight\n6. Average Height & Weight\n7. BMI classification\n8. Exit\n");
    printf("Enter your option(1-8): ");
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        addMem();
        break;
    case 2:
        updateMember();
        break;
    case 3:
        removeMember();
        break;
    case 4:
        max();
        break;
    case 5:
        min();
        break;
    case 6:
        avg();
        break;
    case 7:
        bmi();
        break;
    case 8:
        exit(0);
        break;
    default:
        exit(0);
    }
    return 0;
}

void addMem()
{
    FILE *fptr;
    fptr = fopen("infoset.txt", "a");
    int tempNum;
    printf("Enter Member Id(5 digits): ");
    scanf("%d", &tempNum);
    member[tempNum].id = tempNum;
    fprintf(fptr, "%d;", member[tempNum].id);
    printf("Enter height(m): ");
    scanf("%f", &member[tempNum].height);
    fprintf(fptr, "%.2f;", member[tempNum].height);
    printf("Enter weight(kg): ");
    scanf("%f", &member[tempNum].weight);
    fprintf(fptr, "%.2f\n", member[tempNum].weight);

    printf("Successfully Added...\n");
    fclose(fptr);
    reset();
}

void updateMember()
{
    FILE *fptr, *fptrw;
   // fptrw = fopen("infoset.txt", "w");
    fptr = fopen("infoset.txt", "w+");

    int tempNum;
    printf("Enter Member Id(5 digits): ");
    scanf("%d", &tempNum);
    for (int i = 0; i < 10000; i++)
    {
        if (fscanf(fptr, "%d;%f;%f;", &member[i].id, &member[i].height, &member[i].weight) == 3)
        {
            if (member[i].id == tempNum)
            {
                // printf("%d", i);
                //  printf("%d\t%f\t%f\n", member[i].id, member[i].height, member[i].weight);
                fprintf(fptr, "%d", member[i].id);
                printf("Current Height: %.2f", member[i].height);
                printf("Enter new height: ");
                scanf("%f", &member[i].height);
                // printf("%f\n\n", member[1].height);
                fprintf(fptr, "%.2f", member[i].height);
                fprintf(fptr, "wiii");
                printf("Current Weight: %.2f", member[i].weight);
                printf("Enter new weight: ");
                scanf("%f", &member[i].weight);
                fprintf(fptr, "%.2f", member[i].weight);
            }
        }
    }

    /*
        for (int i = 0; i <= tempNum; i++)
        {
            // printf("%d", i);

            if ((fscanf(fptr, "%d;%f;%f;", &member[i].id, &member[i].height, &member[i].weight) == 3))
            {
                if (member[tempNum].id == i)
                    printf("wii=%d", member[tempNum].id);
                printf("%d", member[tempNum].id);
                printf("\nPresent Height: %.2f\n", member[tempNum].height);
                printf("Enter New height: ");
                scanf("%f", &member[tempNum].height);
                fprintf(fptr, "%.2f", member[tempNum].height);

                printf("\nPresent Weight: %.2f\n", member[tempNum].weight);
                printf("Enter New weight: ");
                scanf("%f", &member[tempNum].weight);
                fprintf(fptr, "%.2f", member[tempNum].weight);

                printf("Successfully updated...\n");
            }
            else
            {
                printf("pailam na");
            }
        }
    */
    fclose(fptr);
   // fclose(fptrw);
    reset();
}

void removeMember()
{
    int tempNum;
    char conf;
    printf("Enter Member Id(5 digits): ");
    scanf("%d", &tempNum);

    printf("Are you sure?(y/n): ");

    scanf(" %c", &conf);
    if (conf == 'y')
    {
        member[tempNum].id = 0;
        member[tempNum].height = 0;
        member[tempNum].weight = 0;
        printf("Account removed successful...\n");
    }
    else
    {
        printf("Process Stopped...\n");
    }

    reset();
}

void max()
{
    float maxHeight = member[0].height;
    int idHeight;
    for (int i = 1; i < totMem; i++)
    {
        if (member[i].height > maxHeight)
        {
            maxHeight = member[i].height;
            idHeight = i;
        }
    }
    float maxWeight = member[0].weight;
    int idWeight;
    for (int i = 1; i < totMem; i++)
    {
        if (member[i].weight > maxWeight)
        {
            maxWeight = member[i].weight;
            idWeight = i;
        }
    }
    printf("Maximum Height: %.2f(Member Id: %d)\nMaximum Weight: %.2f(Member Id: %d)\n\n", maxHeight, idHeight, maxWeight, idWeight);
    reset();
}

void min()
{
    float minHeight = member[0].height;
    int idHeight;
    for (int i = 1; i < totMem; i++)
    {
        if (member[i].height < minHeight)
        {
            minHeight = member[i].height;
            idHeight = i;
        }
    }
    float minWeight = member[0].weight;
    int idWeight;
    for (int i = 1; i < totMem; i++)
    {
        if (member[i].weight < minWeight)
        {
            minWeight = member[i].weight;
            idWeight = i;
        }
    }
    printf("Minimum Height: %.2f(Member Id: %d)\nMinimum Weight: %.2f(Member Id: %d)\n\n", minHeight, idHeight, minWeight, idWeight);
    reset();
}

void avg()
{

    int totalHeight = 0;
    int numOfMem = 0;
    for (int i = 0; i < totMem; i++)
    {
        if (member[i].height != 0)
        {
            totalHeight += member[i].height;
            numOfMem++;
        }
    }
    float avgHeight = (float)totalHeight / numOfMem;

    int totalWeight = 0;
    for (int i = 0; i < totMem; i++)
    {
        if (member[i].weight != 0)
        {
            totalWeight += member[i].weight;
        }
    }
    float avgWeight = (float)totalWeight / numOfMem;
    printf("Average Height: %.2f\nAverage Weight: %.2f\n\n", avgHeight, avgWeight);
    reset();
}

void bmi()
{
    int tempNum;
    printf("Enter Member Id(5 digits): ");
    scanf("%d", &tempNum);
    float w = member[tempNum].weight;
    // printf("%f", w);
    float h = member[tempNum].height;
    // printf("%f", h);

    float bmi = w / (h * h);
    printf("BMI: %.2f\n", bmi);
    printf("BMI Classification: ");
    if (bmi < 16)
        printf("Severe Thinness");
    if (bmi >= 16 && bmi <= 17)
        printf("Moderate Thinness");
    if (bmi >= 17 && bmi <= 18.5)
        printf("Mild Thinness");
    if (bmi >= 18.5 && bmi <= 25)
        printf("Normal");
    if (bmi >= 25 && bmi <= 30)
        printf("Overweight");
    if (bmi >= 30 && bmi <= 35)
        printf("Obese Class I");
    if (bmi >= 35 && bmi <= 40)
        printf("Obese Class II");
    if (bmi > 40)
        printf("Obese Class III");
    printf("\n");
    reset();
}
