#include <stdio.h>

int main()
{
    int a[100], n, i, pos, value;

    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position and value: ");
    scanf("%d%d", &pos, &value);

    if(pos < 1 || pos > n + 1 || n >= 100)
    {
        printf("Invalid position or array size");
        return 0;
    }

    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = value;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
