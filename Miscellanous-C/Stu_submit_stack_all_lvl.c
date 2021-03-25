#include <stdio.h>
#include <string.h>

int L = -1;
#define s 11 //number of records
#define l 11 //length of string
char rollno[s][l], element[l];
int top = -1;
char popped[l];

int push(char stack[s][l], int *t, char x[l])
{
    if (*t == s - 1)
    {
        return -1;
    }
    else
    {
        *t = *t + 1;
        // L = *t;
        strcpy(stack[*t], x);
        return 1;
    }
}
int pop(char stack[s][l], int *t)
{
    if (*t == -1)
    {
        return -1;
    }

    else
    {
        *t = *t - 1;
        // L = *t;
        return 1;
    }
}

void processing()
{
    char cont = 'y';
    char choice = 'a';
    int return_ = 0;
    int j = 0;
    while (cont == 'y' && choice != 'c')
    {
        // top = L;
        printf("a.Add\nb.Remove\nc.Stop\n");
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
            }

            break;

        case 'b':

            strcpy(popped, rollno[top]);
            return_ = pop(rollno, &top);

            if (return_ == -1)
                printf("\nStack is Empty\n");
            else
                printf("Popping %s...\n", popped);
            printf("\n");

            break;

        case 'c':
            printf("Stopping...\n");
            break;

        default:
            printf("\nError!!\n");
        }
        printf("Continue? ");
        scanf("%s", &cont);
    }
    // top = L;
    printf("\n");
    for (int i = 0; i < top; i++)
    {
        printf("%s->", rollno[i]);
    }
    printf("%s\n", rollno[top]);
}

int main()
{
    printf("\nFirst adding/removing from stack\nThen choose levels\n\n");
    processing();
    int c = 1;
    printf("1. Low level\n2. Mid level\n3. High level\nEnter choice: ");
    scanf(" %d", &c);
    if (c == 1)
    {
        printf("Last student: %s", rollno[top]);
    }
    else if (c == 2)
    {
        int i = 0;
        printf("First 10 students: ");
        for (i; i < 10 - 1; i++)
        {
            printf("%s->", rollno[i]);
        }
        printf("%s\n", rollno[9]);
    }
    else if (c == 3)
    {
        char find[10];
        printf("Enter roll number to be searched: ");
        scanf(" %s", &find);

        int i = top;
        int flag = 0;
        for (i; i >= 0; i--)
        {
            if (strcmp(rollno[i], find) == 0)
            {
                printf("Found '%s' at serial #%d\n", find, i + 1);
                flag=1;
            }
        }
        if (flag != 1)
        {
            printf("Not submitted\n");
        }
    }

    return 0;
}

/*
a
20BIT0155
y
a
20BIT0156
y
a
20BIT0157
y
a
20BIT0158
y
a
20BIT0159
y
a
20BIT0160
y
a
20BIT0161
y
a
20BIT0162
y
a
20BIT0163
y
a
20BIT0164
y
a
20BIT0165
y
a
20BIT0166
*/
