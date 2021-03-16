#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *counter = NULL;
struct node *first = NULL;

void insert(int inf)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = inf;
    temp->next = counter;

    counter = temp;
}

void insertstart(int inf)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = inf;
    temp->next = first;

    first = temp;

    temp->data = inf;
    temp->next = counter;

    counter = temp;
}

void delete ()
{
    struct node *temp = counter;
    counter = counter->next;
    free(temp);
}

void display()
{
    struct node *temp = counter;

    temp = counter;
    printf("[ ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}

int main()
{
    // insert(4);
    // insert(5);
    // display();

    char cont = 'y';
    char choice = 'i';
    int i = 1;
    while (cont == 'y')
    {
        printf("Enter choice(i/d): ");
        scanf(" %c", &choice);

        if (choice == 'i')
        {
            if (i)
            {
                printf("Enter data: ");
                int d;
                scanf(" %d", &d);
                printf("Inserting %d...\n", d);
                insertstart(d);
                display();
                i -= 1;
            }
            else
            {
                printf("Enter data: ");
                int d;
                scanf(" %d", &d);
                printf("Inserting %d...\n", d);
                insert(d);
                display();
            }
        }

        else if (choice == 'd')
        {
            printf("Deleting %d...\n", counter->data);
            delete ();
            display();
        }

        printf("Continue? ");
        scanf(" %c", &cont);
    }
    printf("\n");
    display();
    printf("\nFirst element is %d", first->data);

    return 0;
}

/*
i
3
y
i
9
y
i
4
y
d
n

*/