#include <stdio.h>
#include <string.h>

int main()
{
    char exp[100], stack[100];
    int top = -1, i, valid = 1;

    printf("Enter expression: ");
    scanf("%99s", exp);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stack[++top] = exp[i];

        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                valid = 0;
                break;
            }

            if((exp[i] == ')' && stack[top] == '(') ||
               (exp[i] == '}' && stack[top] == '{') ||
               (exp[i] == ']' && stack[top] == '['))
                top--;
            else
            {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;

    if(valid)
        printf("Parentheses are balanced");
    else
        printf("Parentheses are not balanced");

    return 0;
}
