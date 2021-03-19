#include <stdio.h>

struct student
{
    char name[20];
    char regno[10];
    float avg;
};

int main()
{
    int n = 0;
    scanf(" %d", &n);

    struct student list[n];

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf(" %s", &list[i].name);
        scanf(" %s", &list[i].regno);
        scanf(" %f", &list[i].avg);
        if (list[i].avg >= 90)
        {
            printf("S");
        }
        else if (list[i].avg >= 80)
        {
            printf("A");
        }
        else if (list[i].avg >= 70)
        {
            printf("B");
        }
        else if (list[i].avg >= 60)
        {
            printf("C");
        }
        else if (list[i].avg >= 40)
        {
            printf("D");
        }
        else if (list[i].avg >= 50)
        {
            printf("E");
        }
        else if (list[i].avg <= 39)
        {
            printf("F");
        }
        printf("\n");
    }
    return 0;
}