#include <stdio.h>

#define s 5
int main()
{
    int array[s];

    int i = 0;
    for (i = 0; i < s; i++)
    {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }

    int *p = array; //assigning pointer p to first element of array

    for (i = 0; i < s; i++)
    {
        *p += 2; //altering element pointed to
        p++;     //shifting to next element in array
    }

    for (i = 0; i < s - 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d", array[s - 1]);

    return 0;
}