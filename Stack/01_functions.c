#include <stdio.h>
#include <stdlib.h>
int top = -1;
int arr[];
int size;
void push(int value)
{

    if (top == size - 1)
    {
        printf("Over flow condition.");
    }
    else
    {

        size++;
        top++;
        arr[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Under flow condition");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("%d ", arr[top]);
    }
}
int main()
{

    int choice, val;
    int j;
    printf("Enter the size of the array: ");
    scanf("%d", &j);
    const int k=j;
    arr[k];
    
    do
    {
        printf("\n\n\nStack manager:::::\n\n\n");
        printf("\n1. Show the stack.");
        printf("\n2. Enter a value in the stack.");
        printf("\n3. Delete a value from the stack.");
        printf("\n4. Peek.");
        printf("\n5. exit.");

        printf("\nEnter the choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == -1)
            {
                printf("Stack is empty");
            }
            else
            {
                // size=sizeof(arr)/sizeof(arr[0]);
                for (int i = 0; i < size; i++)
                {
                    peek();
                    top--;
                }
            }
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &val);
            push(val);
            break;
        case 3:

            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);

        default:
            printf("Invalid input.");
            break;
        }
    } while (exit);
    return 0;
}