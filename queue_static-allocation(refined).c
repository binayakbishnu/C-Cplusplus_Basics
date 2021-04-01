#include <stdio.h>
#include <stdbool.h>

#define size 20

int queue[size];
int front = -1, rear = -1;

bool isEmpty()
{
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}

bool isFull()
{
    if (rear == size - 1)
        return true;
    else
        return false;
}

int peak() //to see front element
{
    if (!isEmpty())
        return queue[front];
    else
        printf("\nQueue is empty\n");
}

void enqueue(int e)
{
    if (isFull())
        printf("\nQueue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("\nInserting %d into index %d\n", e, rear + 1);
        queue[++rear] = e;
    }
}

void dequeue()
{
    if (isEmpty())
        printf("\nQueue is empty\n");
    else
    {
        printf("\nDeleting %d from index %d\n", queue[front], front);
        front += 1;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    int i = 0;
    for (i = front; i < rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[rear]);
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