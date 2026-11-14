#include <stdio.h>
#define MAX 5

int queue[MAX], priority[MAX], n = 0;

void insert(int value, int p)
{
    int i;

    if(n == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    i = n - 1;

    while(i >= 0 && priority[i] > p)
    {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }

    queue[i + 1] = value;
    priority[i + 1] = p;
    n++;

    printf("Element inserted\n");
}

void delete()
{
    int i;

    if(n == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[0]);

    for(i = 0; i < n - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display()
{
    int i;

    if(n == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    for(i = 0; i < n; i++)
        printf("%d(Priority %d) ", queue[i], priority[i]);

    printf("\n");
}

int main()
{
    int choice, value, p;

    do
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d%d", &value, &p);
                insert(value, p);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
    } while(choice != 4);

    return 0;
}
