#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int value)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        stack[++top] = value;
        printf("Element pushed\n");
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element: %d\n", stack[top--]);
}

void display()
{
    int i;

    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);

        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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
