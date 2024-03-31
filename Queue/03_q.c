// implementation of queue using linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
    Node *front=NULL;
    Node* rear=NULL;

    void enqueue(int val){
        Node * newnode=malloc(sizeof(Node*));
        newnode->data=val;
        newnode->next=NULL;
        if(front==NULL && rear==NULL){
            front=rear=newnode;
        }else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void dequeue(){
        Node* temp;
        temp=front;
        if(front==NULL && rear==NULL){
            printf("Queue is empty...");
        }else{
            printf("The dequeued Data is: %d ", front->data);
            front=front->next;
            free(temp);
        }
    }

    void display(){
        Node * temp;
        if(front==NULL && rear==NULL){
            printf("Queue is empty...");
        }else{
            temp=front;
            while(temp!=0){
                printf("%d ",temp->data);
                temp=temp->next;
            }
        }
    }

    void peek(){
        if(front==NULL && rear== NULL){
            printf("Queue is empty...");
        }else{
            printf("%d ", front->data);
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