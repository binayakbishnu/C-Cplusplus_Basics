#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf(" %d", &n);

    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        int i = 0;
        for (i = 0; i < n; i++)
        {
            scanf(" %d", &ptr[i]);
        }

        int j = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (ptr[j] > ptr[j + 1])
                {
                    int temp = ptr[j];
                    ptr[j] = ptr[j + 1];
                    ptr[j + 1] = temp;
                }
            }
        }
        for (i = 0; i < n - 1; i++)
        {
            printf("%d, ", ptr[i]);
        }
        printf("%d", ptr[n - 1]);

        printf("\n\nGreatest number: %d",ptr[n-1]);
    }

    return 0;
}
