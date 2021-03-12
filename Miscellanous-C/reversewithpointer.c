#include <stdio.h>

int main()
{
    int size;
    printf("Enter number: ");
    scanf("%d", &size);

    int array[size];

    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &array[i]);
    }

    int *p1 = array;
    int *p2 = &array[size - 1];

    for (i = 0; i < size / 2; i++)
    {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }

    for (i = 0; i < size-1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d",array[size-1]);

    return 0;
}