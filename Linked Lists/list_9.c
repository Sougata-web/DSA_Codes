#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * prev;

};
struct node * head;
struct node * tail;
    void insert_last(int data){
        struct node * newnode=(struct node*)malloc(sizeof(struct node));
        struct node * temp;
        newnode->next=NULL;
        newnode->next=NULL;
        newnode->data=data;

        if(head==NULL){
            head=temp=newnode;
        }else{

            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;

        }
    }

    void insert_begin(int data){
        struct node * newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }

    void insert_any(int position,int data){
        struct node * newnode=(struct node*)malloc(sizeof(struct node));
        struct node * temp;
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        int index=0,size;
        if(position<index && position>size){
            printf("Invalid Position\n");
        }else if(position==1){
            insert_begin(data);
        }else if(position==size){
            insert_last(data);
        }else{
            for (int i=0;i<position-1;i++){

            if(i==position){
                newnode->prev=temp;
                newnode->next=temp->next;
                temp->next=newnode;
                temp->next->prev=newnode;
                
            }else{
                temp=temp->next;
            
            }
            }
        }
    }


    int display(){
        struct node * temp=head;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }

    }


int main(){
    insert_last(10);
    insert_last(20);
    insert_begin(30);
    insert_any(2,100);
    insert_begin(50);
    display();
    
    return 0;
}