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
        printf("Stack is empty");
    else
        printf("Top element = %d", stack[top]);

    return 0;
}
