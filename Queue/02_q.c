//Circular queue using array

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front=-1,rear=-1,queue[MAX];

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }else if(((rear+1)%MAX)==front){
        printf("Queue is full\n");
    }else{
        rear=(rear+1)%MAX;
        queue[rear]=x;
    }
}

void dequeue(){
    if(front ==-1 && rear==-1){
        printf("Empty Queue\n");
    }else if(front == rear){
        front=rear=-1;
    }else{
        printf("%d",queue[front]);
        front=(front+1)%MAX;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else{
        printf("The queue is:\n");
        while(i!=rear){
            printf("%d",queue[i]);
            i=(i+1)%MAX;
        }
        printf("%d\t",queue[rear]);
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        }
    else{
        printf("%d",queue[front]);
        }
}

int main(){
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
 
    return 0;
}