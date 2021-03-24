#include <stdio.h>

#define s 10

struct studentdetails
{
    int roll = 0;
    char name[s];
    union //anonynmous union
    {
        int subject1; //don't initialise
        int subject2;
        int subject3;
    } marks;
}student;

int main()
{
    int number = 0;
    printf("Number of students: ");
    scanf(" %d", &number);

    int i = 0;
    for (i; i < number; i++)
    {
        int total = 0;
        printf("Roll no: ");
        scanf(" %d", &student.roll);
        printf("Name: ");
        scanf(" %s", &student.name);
        printf("Marks1: ");
        scanf(" %d", &student.marks.subject1);
        total += student.marks.subject1;
        printf("Marks2: ");
        scanf(" %d", &student.marks.subject2);
        total += student.marks.subject2;
        printf("Marks3: ");
        scanf(" %d", &student.marks.subject3);
        total += student.marks.subject3;
        printf("Total: %d\n", total);
    }

    return 0;
}