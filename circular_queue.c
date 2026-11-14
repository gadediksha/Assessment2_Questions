#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Element inserted\n");
    }
}

void dequeue()
{
    if(front == -1)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted: %d\n", queue[front]);

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    i = front;

    while(1)
    {
        printf("%d ", queue[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
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
        }
    } while(choice != 4);

    return 0;
}
