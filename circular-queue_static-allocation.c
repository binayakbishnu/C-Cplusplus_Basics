#include <stdio.h>
#include <stdbool.h>

#define size 5

int cqueue[size];
int front = -1, rear = -1;

bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

bool isFull()
{
    if ((front == 0 && rear == size - 1) || front == rear + 1)
        return true;
    else
        return false;
}

int peak()
{
    if (isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        printf("%d\n", cqueue[front]);
    }
}

void enqueue(int e)
{
    if (isFull())
        printf("\nQueue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        printf("\nInserting %d into index %d\n", e, rear);
        cqueue[rear] = e;
    }
}

void dequeue()
{
    if (isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        if (front == rear)
        {
            printf("\nDeleting %d from index %d\n", cqueue[front], front);
            front = -1;
            rear = -1; //resetting values
        }
        else
        {
            printf("\nDeleting %d from index %d\n", cqueue[front], front);
            front = (front + 1) % size;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        int i = 0;
        for (i = front; i != rear; i = (i + 1) % size)
            printf("%d ", cqueue[i]);
        printf("%d", cqueue[i]);
    }
}

int main()
{
    int choice = 1;
    char cont = 'y';
    while (cont == 'y')
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peak\n4. Display\n");
        scanf(" %d", &choice);
        if (choice == 1)
        {
            int element;
            printf("Enter element: ");
            scanf(" %d", &element);
            enqueue(element);
            display();
        }
        else if (choice == 2)
        {
            dequeue();
            display();
        }
        else if (choice == 3)
        {
            peak();
        }
        else if (choice == 4)
            display();

        printf("\nContinue? ");
        scanf(" %c", &cont);
    }
    return 0;
}