//Implementation of circular queue using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
    node* front=NULL;
    node* rear=NULL;
void enqueue(int value){
    node* newnode=malloc(sizeof(node*));
    newnode->data=value;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode;
        rear->next=front;
    }else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue(){
    node * temp;
    temp=front;
    if(front==NULL && rear==NULL){
        printf("The queue is empty...");
    }else if (front ==rear){
        front=rear=NULL;
        free(temp);
    }else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if(front == NULL && rear==NULL){
        printf("The queue is empty...");
    }else{
        printf("%d ", front->data);
    }
}

void display(){
    node * temp;
    temp=front;
    if(front == NULL && rear==NULL){
        printf("The queue is empty...");
    }else{
        while(temp->next!= front){
            printf("%d ", temp->data);
            temp=temp->next;
        }
            printf("%d ", temp->data);

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