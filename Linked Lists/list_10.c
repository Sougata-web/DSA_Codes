#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;

}*head,*tail;
void insert_begin(struct node*head, int data){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        head=tail=newnode;
        newnode->prev=tail;
        newnode->next=head;
    }else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}

void insert_end(struct node*head, int data){
    struct node * newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(tail==NULL){
        printf("There is no data");
    }else{
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}

int getLength(struct node * head){
    struct node * temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
}
void insert_at_any(struct node*head, int data,int position){
    struct node * newnode,*temp;
    int pos,i=1,len;
    temp=head;
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);
    len=getLength(head);

    if(pos<1 || pos>len){
        printf("Invalid position.");
    }else if(pos==1){
        insert_begin(head,data);
    }else if(pos ==len){
        insert_end(head,data);

    }else{
        newnode->data=data;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
    }
}

void display(){
    struct node * temp=head;

    if(head==NULL){
        printf("Ulalalal");
    }else{
        while(temp!=tail){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void delete_begin(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("Invalid");
    }else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void delete_end(){
    struct node * temp;
    temp=tail;
    if(head==NULL){
        printf("Empty");
    }else if(head->next==head){
        head=tail==NULL;
        free(temp);
    }else{
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}

void insert_from_any(){
    struct node *temp;
    int pos,i=1,len;
    temp=head;
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);
    len=getLength(head);

    if(pos<1 || pos>len){
        printf("Invalid position.");
    }else if(pos==1){
        delete_begin();
    }else if(pos ==len){
        delete_end();
    }else{
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==head){
            tail=temp->prev;
            free(temp);
        }else{
            free(temp);
        }
    }
}

int main(){
    head=NULL;
    insert_begin(head,10);
    insert_end(head,30);

    insert_begin(head,20);

    display();
    
    return 0;
}