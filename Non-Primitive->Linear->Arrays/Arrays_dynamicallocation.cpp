#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    struct Node *join;
};
Node *element = NULL;

int main()
{
    char choice = 'y';
    while (1)
    {
        Node *temp;
        temp =new Node();
        if (!temp)
        {
            printf("Overflowed heap!!\n");
        }
        else
        {
            int e = 0;
            printf("Enter element: ");
            scanf("%d", &e);
            temp->data = e;
            temp->join = element;
            element = temp;
            delete temp;
        }

        printf("Continue? ");
        cin>>choice;
        if (choice != 'y')
            break;
    }

    Node *temp;
    temp = new Node();
    temp = element;
    printf("Elements:\n");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->join;
    }

    return 0;
}
