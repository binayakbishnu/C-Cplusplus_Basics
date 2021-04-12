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
void display()
{
    int a = 0;
    printf("Stack:");
    for (a; a < top; a++)
        printf("%c", stack[a]);
    printf("%c\n", stack[top]);
}
int equal(char bracket)
{
    // printf("\nbracket=%c; stack[top]=%c\n", bracket, stack[top]);
    if (bracket == ')' && stack[top] == '(')
        return 1;
    if (bracket == '}' && stack[top] == '{')
        return 1;
    if (bracket == ']' && stack[top] == '[')
        return 1;
}

int main()
{
    char statement[100];
    printf("Enter statement (press '/' to end): ");
    // scanf(" %s", &statement);
    // scanf("%[^/]s", statement);

    char input;
    int x = 0;
    while ((input = getchar()) != '/')
    {
        statement[x++] = input;
    }
    statement[x] = '\0';

    printf("\nInput String = %s\n\n", statement);

    int i = 0;
    for (i; i < strlen(statement); i++)
    {
        if (statement[i] == '(' || statement[i] == '{' || statement[i] == '[')
        {
            push(statement[i]);
            printf("\nPushed\n");
            display();
        }
        else if (statement[i] == ')' || statement[i] == '}' || statement[i] == ']')
        {
            if (!isEmpty())
            {
                if (equal(statement[i]) != 1)
                {
                    printf("\nUnbalanced by not equal\n");
                    display();
                    exit(0);
                }
            }
            int result = pop();

            if (result == 0)
            {
                printf("\nUnbalanced by extra closing\n");
                printf("Remove extra bracket\n");
                display();
                exit(0);
            }
            else if (result == 1)
                printf("\nPopped\n");
            display();
        }
    }

    if (!isEmpty())
    {
        printf("\nUnbalanced by unclosed bracket\n");
        printf("Add bracket\n");
        display();
    }
    else if (isEmpty())
    {
        printf("\nBalanced\n");
        display();
    }

    return 0;
}
