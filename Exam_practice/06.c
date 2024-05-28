#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};

// Function to create a stack of given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if stack is full
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push element onto stack
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to pop element from stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to reverse a string using stack
void reverseString(char *str)
{
    int len = strlen(str);
    struct Stack *stack = createStack(len);
    int i;

    // Push all characters of string onto stack
    for (i = 0; i < len; i++)
        push(stack, str[i]);

    // Pop all characters from stack and put them back into string
    for (i = 0; i < len; i++)
        str[i] = pop(stack);

    free(stack->array);
    free(stack);
}

int main()
{
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    printf("Original string: %s\n", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);

    return 0;
}
