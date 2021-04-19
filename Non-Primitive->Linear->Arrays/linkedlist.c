#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *joint;
};

struct node *head = NULL;

int isEmpty()
{
    /*
    if (head == NULL)
        return 1;
    else
        return 0;
    */
    return head == NULL;
}

void insertbegin(int x)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Heap overflow");
        exit(1);
    }
    temp->data = x;
    temp->joint = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->joint = head;
        head = temp;
    }
}

void insertend(int x)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));

    if (!temp)
    {
        printf("Heap overflow");
        exit(1);
    }
    temp->data = x;
    temp->joint = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temp2 = NULL;
        temp2 = head;
        while (temp2->joint != NULL)
        {
            temp2 = temp2->joint;
        }
        temp2->joint = temp;
    }
}

void display()
{
    if (isEmpty())
        printf("Stack empty");
    else
    {
        struct node *temp = NULL;
        temp = head;
        while (temp->joint != NULL)
        {
            printf("%d\nv\n", temp->data);
            temp = temp->joint;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    insertbegin(2);
    insertbegin(3);
    insertbegin(9);

    insertend(5);
    insertend(1);

    display();

    int y = 0;
    struct node *temp;
    temp = head;
    // while (!temp)
    // {
    //     y = temp->data;
    // }
    // printf("%d", y);
    return 0;
}
