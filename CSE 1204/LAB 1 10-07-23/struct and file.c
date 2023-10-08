#include <stdio.h>

// Define the structure
struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    FILE *file;
    struct Student students[100];
    int numStudents;

    // Taking inputs for multiple structure members
    printf("Enter the number of students (up to 100): ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter Name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Write the data to the file
    file = fopen("students_data.txt", "w"); // "w" for writing in text mode

    if (file == NULL)
    {
        perror("Error opening the file");
        return 1;
    }

    for (int i = 0; i < numStudents; i++)
    {
        fprintf(file, "%d;%s;%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }

    fclose(file);

    printf("Data has been written to the file successfully.\n");

    // Now, let's read data from the file and print desired data

    int searchRollNumber;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRollNumber);

    // Open the file in read mode
    file = fopen("students_data.txt", "r"); // "r" for reading in text mode

    if (file == NULL)
    {
        perror("Error opening the file");
        return 1;
    }

    // Read data from the file and store it in the array
    int foundIndex = -1;
    for (int i = 0; i < numStudents; i++)
    {
        if (fscanf(file, "%d;%49[^;];%f\n", &students[i].rollNumber, students[i].name, &students[i].marks) == 3)
        {
            if (students[i].rollNumber == searchRollNumber)
            {
                foundIndex = i;
                break;
            }
        }
    }

    fclose(file);

    if (foundIndex != -1)
    {
        printf("\nStudent %d:\n", foundIndex + 1);
        printf("Roll Number: %d\n", students[foundIndex].rollNumber);
        printf("Name: %s\n", students[foundIndex].name);
        printf("Marks: %.2f\n", students[foundIndex].marks);
    }
    else
    {
        printf("Student with Roll Number %d not found.\n", searchRollNumber);
    }

    return 0;
}