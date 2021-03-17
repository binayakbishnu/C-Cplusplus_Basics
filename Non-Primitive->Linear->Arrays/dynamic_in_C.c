#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number: ");
    scanf(" %d", &n);

    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    //ptr=(int*)calloc(n,sizeof(int)); //assigns default value to 0
    printf("%d\n",*ptr);

    if (ptr == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        int i;
        for (i = 0; i < n; i++)
        {
            ptr[i] = i + 1;
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", ptr[i]);
        }
    }

    return 0;
}
