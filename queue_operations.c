#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;

        queue[++rear] = value;
        printf("Element inserted\n");
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front++]);

        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}
