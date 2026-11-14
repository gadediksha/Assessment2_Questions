#include <stdio.h>
#define MAX 5

int main()
{
    int stack[MAX], top = -1, n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 0 || n > MAX)
    {
        printf("Invalid size");
        return 0;
    }

    printf("Enter stack elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &stack[i]);
        top++;
    }

    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements (top to bottom):\n");

        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }

    return 0;
}
