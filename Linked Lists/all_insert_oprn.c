#include <stdio.h>
#include <stdlib.h>
int i = 1, k, j, l;
// char chr;
struct node
{
    int val;
    struct node *next;
};
struct node *temp, *m, *newnode, *start;

void insert_begining(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->val = value;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}
void insert_end(int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->val = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *m;
        m = start;
        while (m->next != NULL)
            m = m->next;
        m->next = temp;
    }
}
void insert_any_pos(int value, int pos)
{
    if (pos > j)
    {
        printf("Invalid position>>>!");
    }
    else
    {
        {
            temp = (struct node *)malloc(sizeof(struct node));
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->val = value;
            newnode->next = NULL;
            temp = start;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}
int printList()
{
    m = start;
    printf("Printing linked lists values:\n");
    while (m != NULL)
    {
        printf("%d ", m->val);
        m = m->next;
    }
}

int main()
{
    int n, pos, choice, x;
    printf("First make an linked lists ....!!!\n\n");
    printf("Enter the number of values you want to store:\n");
    scanf("%d", &j);
    printf("Enter the values you want to store:\n");
    for (k = 0; k < j; k++)
    {
        scanf("%d", &l);
        insert_end(l);
    }
    printList();
    printf("\n Enter the method you want to do:\n\n");
    printf("\t1. Insert at begining\n\t2. Insert at end\n\t3. Insert at a given position\n\n");
    printf("Enter the choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the value you want to insert:\n");
        scanf("%d", &x);
        insert_begining(x);
        printList();
        break;
    case 2:
        printf("Enter the value you want to insert:\n");
        scanf("%d", &x);
        insert_end(x);
        printList();

        break;
    case 3:
        printf("Enter the value you want to insert:\n");
        scanf("%d", &x);
        printf("Enter the position(after that) you want to insert:\n");
        scanf("%d", &pos);

        insert_any_pos(x, pos);
        printList();
        break;
    default:
        printf("Invalid input.");
        break;
    }
    // printf("\nDo you want to continue?\n");
    // printf("Enter y for continue and n for turn off:\n");
    // scanf("%d", &choice);

    return 0;
}