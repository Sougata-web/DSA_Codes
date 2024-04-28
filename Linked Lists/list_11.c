#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *m;

void insert(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        struct node *m;
        m=start;
        while(m->next != NULL)
            m=m->next;
        m->next=temp;
    }
}

void reverseList(){
    struct node *prevNode,*currentNode,*nextNode;
    prevNode=NULL;
    currentNode=nextNode=start;
    while(nextNode!=NULL){
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    start=prevNode;
}

int printList(){
    m=start;
    printf("Printing linked lists values:\n");
    while(m!=NULL){
        printf("%d ",m->data);
    m=m->next;
    }
}


int main(){
    int i,n,x;
    printf("Enter the number of values you want to store:\n");
    scanf("%d",&n);
    printf("Enter the values you want to store:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }
    printList();

    reverseList();
    printList();
    return 0;
}