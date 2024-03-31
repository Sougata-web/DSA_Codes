// Doubly linked list
#include<stdio.h>
#include<stdlib.h>

    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };
    struct node * head;
    void insert_first(int value){
        struct node *newnode,*temp;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->prev=NULL;
        newnode->next=NULL;
        newnode->data=value;
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }

    void display(){
        struct node *temp;
        temp=head;
        printf("The numbers: \n");
        while(temp!=NULL){
            printf("%d \n",temp->data);
            temp=temp->next;
        }
    }
int main(){

    int i,x,n;
        printf("Enter the size of the list:\n");
        scanf("%d",&n);
        printf("Enter the numbers for the list:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_first(x);
    }

    display();
    
    return 0;
}