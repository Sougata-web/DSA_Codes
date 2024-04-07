#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
};
struct Node *top = NULL;
void push(char c)
{
    struct Node *newNode = (struct
                            Node *)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}
char pop()
{
    if (top == NULL)
    {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = top;
    char popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}
char peek()
{
    if (top == NULL)
    {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return top->data;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}
void infixToPostfix(char *infix, char *postfix)
{
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != NULL && peek() != '(')
            {
                postfix[j++] = pop();
            }
            if (top != NULL && peek() == '(')
            {
                pop();
            }
            else
            {
                printf("Error: Invalid expression\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            while (top != NULL && precedence(infix[i]) <=
                                      precedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top != NULL)
    {
        if (peek() == '(')
        {
            printf("Error: Invalid expression\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
void infixToPrefix(char *infix, char *prefix)
{
    int i, j;
    char temp[strlen(infix) + 1];
    strcpy(temp, infix);
    strrev(temp);
    for (i = 0; temp[i] != '\0'; i++)
    {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')

            temp[i] = '(';
    }
    infixToPostfix(temp, prefix);
    strrev(prefix);
}
int main()
{
    char infix[100], postfix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}