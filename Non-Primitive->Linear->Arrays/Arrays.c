#include <stdio.h>

#define s 10
int main()
{
    //declaring and initializing
    int array[] = {2, 5, 1, 8, 10, 7, 9, 3, 4};

    //traversal
    printf("Traversing");
    printf("array[%d]=%d array[%d]=%d\n", 4, array[4], 8, array[8]);
    int i = 0;
    for (i = 3; i < 7; i++)
    {
        printf("array[%d]=%d ", i, array[i]);
    }
    printf("\n");

    //insertion
    int x = 0, e = 0;
    printf("Insert at index: ");
    scanf("%d", &x);
    printf("Element to be inserted: ");
    scanf("%d", &e);
    for (i = s - 1; i >= x; i--)
    {
        array[i + 1] = array[i];
    }
    array[x] = e;
    for (i = 0; i < s; i++)
    {
        printf("array[%d]=%d ", i, array[i]);
    }
    printf("\n");

    //deletion
    int y = 0;
    printf("Delete from index: ");
    scanf("%d", &y);
    for (i = y; i < s; i++)
    {
        array[i] = array[i + 1];
    }
    for (i = 0; i < s - 1; i++)
    {
        printf("array[%d]=%d ", i, array[i]);
    }
    printf("\n");

    return 0;
}