#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define s 30

char inexp[s];
char converted[s];
char stack[s];
int top = -1;
int value = 0;
float evalstack[s];
int evaltop = -1;

void postpush(char x)
{
    stack[++top] = x;
}

char postpop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int postpr(char x)
{
    if (x == '(')
        return 0;
    if (x == '-')
        return 1;
    if (x == '+')
        return 2;
    if (x == '*')
        return 3;
    if (x == '/')
        return 4;
    if (x == '^')
        return 5;
}

void postfix()
{
    int i = 0;
    int a = 0;
    for (i = 0; inexp[i] != '\0'; i++)
    {
        if (isalnum(inexp[i]))
        {
            converted[a++] = inexp[i];
            //printf("%c", inexp[i]);
        }
        else if (inexp[i] == '(')
            postpush(inexp[i]);
        else if (inexp[i] == ')')
        {
            char x;
            while ((x = postpop()) != '(')
            {
                converted[a++] = x;
                //printf("%c", x);
            }
        }
        else
        {
            while (postpr(stack[top]) >= postpr(inexp[i]))
            {
                char x = postpop();
                //printf("%c", x);
                converted[a++] = x;
            }
            postpush(inexp[i]);
        }
    }
    while (top != -1)
    {
        char x = postpop();
        //printf("%c", x);
        converted[a++] = x;
    }
}

void prefix()
{
    strrev(inexp);
    printf("Reversed: %s\n", inexp);
    int i = 0;
    for (i = 0; inexp[i] != '\0'; i++)
    {
        if (inexp[i] == '(')
            inexp[i] = ')';
        else if (inexp[i] == ')')
            inexp[i] = '(';
    }
    printf("Refined: %s\n", inexp);
    postfix();
}

void posteval()
{
    int i = 0;
    while (converted[i] != '\0')
    {
        if (isalpha(converted[i]))
        {
            printf("Enter value of %c: ", converted[i]);
            scanf(" %d", &value);
            evalstack[++evaltop] = value;
        }
        else if (converted[i] == '+' || converted[i] == '-' || converted[i] == '*' || converted[i] == '/')
        {
            if (converted[i] == '+')
            {
                evalstack[evaltop - 1] = evalstack[evaltop - 1] + evalstack[evaltop];
                evaltop--;
            }
            else if (converted[i] == '-')
            {
                evalstack[evaltop - 1] = evalstack[evaltop - 1] - evalstack[evaltop];
                evaltop--;
            }
            else if (converted[i] == '*')
            {
                evalstack[evaltop - 1] = evalstack[evaltop - 1] * evalstack[evaltop];
                evaltop--;
            }
            else if (converted[i] == '/')
            {
                evalstack[evaltop - 1] = evalstack[evaltop - 1] / evalstack[evaltop];
                evaltop--;
            }
        }
        i++;
    }
    printf("Final value is: %.2f (upto two decimal places)", evalstack[evaltop]);
}

void preeval()
{
    strrev(converted);
    int i = 0;
    while (converted[i] != '\0')
    {
        if (isalpha(converted[i]))
        {
            printf("Enter value of %c: ", converted[i]);
            scanf(" %d", &value);
            evalstack[++evaltop] = value;
        }
        else if (converted[i] == '+' || converted[i] == '-' || converted[i] == '*' || converted[i] == '/')
        {
            if (converted[i] == '+')
            {
                evalstack[evaltop - 1] = evalstack[evaltop] + evalstack[evaltop - 1];
                evaltop--;
            }
            else if (converted[i] == '-')
            {
                evalstack[evaltop - 1] = evalstack[evaltop] - evalstack[evaltop - 1];
                evaltop--;
            }
            else if (converted[i] == '*')
            {
                evalstack[evaltop - 1] = evalstack[evaltop] * evalstack[evaltop - 1];
                evaltop--;
            }
            else if (converted[i] == '/')
            {
                evalstack[evaltop - 1] = evalstack[evaltop] / evalstack[evaltop - 1];
                evaltop--;
            }
        }
        i++;
    }
    printf("Final value is: %.2f (upto two decimal places)", evalstack[evaltop]);
}

void main_code()
{
    printf("Expression? ");
    scanf(" %s", &inexp);

    char choice1 = 'a';
    char choice2 = 1;

    printf("a. Postfix\nb. Prefix\nEnter choice: ");
    scanf(" %c", &choice1);

    if (choice1 == 'a')
    {
        printf("1. Convert to postfix\n2. Evaluate by postfix\nEnter choice: ");
        scanf(" %d", &choice2);
        if (choice2 == 1)
        {
            printf("Converting to postfix...\n");
            postfix();
            printf("Converted: %s\n", converted);
        }
        if (choice2 == 2)
        {
            printf("Converting to postfix...\n");
            postfix();
            printf("Converted: %s\n", converted);
            printf("Evaluating postfix...\n");
            posteval();
        }
    }
    else if (choice1 == 'b')
    {
        printf("1. Convert to postfix\n2. Evaluate by postfix\nEnter choice: ");
        scanf(" %d", &choice2);
        if (choice2 == 1)
        {
            printf("Converting to prefix...\n");
            prefix();
            printf("Converted: %s\n", converted);
            printf("Converted (reverse refined): %s\n", strrev(converted));
        }
        if (choice2 == 2)
        {
            printf("Converting to prefix...\n");
            prefix();
            printf("Converted: %s\n", converted);
            printf("Converted (reverse refined): %s\n", strrev(converted));
            preeval();
        }
    }
}

int main()
{
    int c = 1;
    printf("1. Low level\n2. Mid level\n3. High level\nEnter choice: ");
    scanf(" %d", &c);

    switch (c)
    {
    case 1:
        printf("Low level part of mid level\nSkipping to mid level...\n");
        //break;

    case 2:
        printf("Mid level part of high level\nSkipping to high level...\n");

    case 3:
        printf("High level\n");
        main_code();
        break;

    default:
        printf("Error!!\n");
    }

    return 0;
}
