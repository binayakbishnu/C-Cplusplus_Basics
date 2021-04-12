#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[20];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(char bracket)
{
    top += 1;
    stack[top] = bracket;
}

int pop()
{
    if (isEmpty())
        return 0;
    else if (!isEmpty())
    {
        top -= 1;
        return 1;
    }
}

int main()
{
    char statement[20];
    printf("Enter statement: ");
    scanf(" %s", &statement);

    int i = 0;
    for (i; i < strlen(statement); i++)
    {
        if (statement[i] == '(')
        {
            push('(');
        }
        else if (statement[i] == ')')
        {
            int result = pop();
            if (result == 0)
            {
                printf("\nUnbalanced\n");
                printf("Remove extra )\n");
                exit(0);
            }
            else if (result == 1)
                printf("\nPopped\n");
        }
    }

    if (!isEmpty())
    {
        printf("\nUnbalanced\n");
        printf("Add )");
    }
    else if (isEmpty())
    {
        printf("\nBalanced\n");
    }

    return 0;
}

