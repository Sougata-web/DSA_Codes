//Implementation of queue using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int front=-1;
int rear=-1;
int queue[MAX];


void enqueue(int x){
    if(rear==MAX-1){
        printf("Overflow\n");
    }else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }else{
        rear++;
        queue[rear]=x;
        }
}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("Empty queue\n");
    }else if(front==rear){
        front=rear=-1;
    }else{
        printf("%d",queue[front]);
        front++;
    }
}

void display(){
    int i=front;
    if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }else{
        for(i=front;i<rear+1;i++){
            printf("%d\t",queue[i]);
        }
    }
}

void peek(){
    if(front==-1 && rear==-1){
        printf("Empty Queue");
    }else{
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