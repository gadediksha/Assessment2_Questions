#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;

    while(current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

void display()
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(value);
    }

    printf("Original list: ");
    display();

    reverse();

    printf("Reversed list: ");
    display();

    while(head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
