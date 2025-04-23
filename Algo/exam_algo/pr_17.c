#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;
int count = 0;

void push(int value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

void pop()
{
    if (top >= 0)
    {
        top--;
        count++;
    }
}

void multi_pop(int k)
{
    if (k > top + 1)
    {
        printf("Not enough elements to pop. Popping all available elements.\n");
        k = top + 1;
    }

    while (k-- > 0)
    {
        pop();
    }
}

int main()
{
    int n, val, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        push(val);
    }

    printf("Enter k for MultiPop: ");
    scanf("%d", &k);
    multi_pop(k);

    printf("Stack after MultiPop: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\nOperation Count: %d\n", count);

    return 0;
}
