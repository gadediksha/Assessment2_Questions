#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], c;
    int i;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    printf("Postfix expression: ");

    for(i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        if(isalnum((unsigned char)c))
            printf("%c", c);

        else if(c == '(')
            push(c);

        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                printf("%c", pop());

            if(top != -1)
                pop();
        }
        else
        {
            while(top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(c) ||
                  (precedence(stack[top]) == precedence(c) && c != '^')))
                printf("%c", pop());

            push(c);
        }
    }

    while(top != -1)
        printf("%c", pop());

    return 0;
}
