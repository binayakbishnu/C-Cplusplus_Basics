#include <stdio.h>
#include <string.h>

int L = -1;
#define s 7

int push(char stack[s][10], int *t, char x[10])
{
    if (*t == s - 1)
    {
        //printf("%d:function\n", *t);
        return -1;
    }
    else
    {
        *t = *t + 1;
        L = *t;
        strcpy(stack[*t], x);
        //printf("%d:function\n", *t);
        return 1;
    }
}
int pop(char stack[s][10], int *t)
{
    if (*t == -1)
    {
        //printf("%d:function\n", *t);
        return -1;
    }

    else
    {
        *t = *t - 1;
        L = *t;
        //printf("%d:function\n", *t);
        return 1;
    }
}
int main()
{
    char rollno[s][10], element[10];
    int top = -1;
    char cont = 'y';
    char choice = 'a';
    int return_ = 0;
    int j = 0;
    while (cont == 'y')
    {
        top = L;
        printf("%d:whilebegin\n", top);
        printf("a.Add\nb.Remove\nc.Print last 5\nd.Remove last 5\n");
        printf("Enter choice:");
        scanf("%s", &choice);
        switch (choice)
        {
        case 'a':
            printf("\nEnter string : ");
            scanf("%s", &element);

            return_ = push(rollno, &top, element);

            if (return_ == -1)
                printf("\nOverflow!!\n");
            else
            {
                printf("Pushing %s...\n", element);
                printf("%d:main\n", top);
            }

            break;

        case 'b':

            char popped[10];
            printf("%d:main\n", top);
            strcpy(popped, rollno[top]);
            return_ = pop(rollno, &top);

            if (return_ == -1)
                printf("\nStack is Empty\n");
            else
                printf("Popping %s...\n", popped);
            printf("\n");

            break;

        case 'c':

            for (j = top; j > top - 5 + 1; j--)
            {
                printf("%s->", rollno[j]);
            }
            printf("%s\n", rollno[top - 5 + 1]);
            break;

        case 'd':

            for (j = 0; j < 5; j++)
            {
                char popped[10];
                //printf("%d:main\n", top);
                strcpy(popped, rollno[top]);
                return_ = pop(rollno, &top);

                if (return_ == -1)
                    printf("\nStack is Empty\n");
                else
                    printf("Popping %s...\n", popped);
                printf("\n");
            }
            break;

        default:
            printf("\nError!!\n");
        }
        printf("Continue? ");
        scanf("%s", &cont);
    }
    top = L;
    printf("\n");
    for (int i = 0; i < top; i++)
    {
        printf("%s->", rollno[i]);
    }
    printf("%s\n", rollno[top]);
    return 0;
}

