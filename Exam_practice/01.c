#include <stdio.h>

#define MAX_SIZE 10 // Maximum size of the circular queue

int front = -1, rear = -1; // Pointers to front and rear of the circular queue
int queue[MAX_SIZE];       // Array to store the elements of the circular queue

// Function to check if the circular queue is full
int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)))
    {
        return 1; // Queue is full
    }
    else
    {
        return 0; // Queue is not full
    }
}

// Function to display the elements of the circular queue
void displayQueue()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in circular queue are: ");
    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i < MAX_SIZE; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    // Sample usage
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
    displayQueue();
    return 0;
}
