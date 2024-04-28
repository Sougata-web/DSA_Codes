#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
 struct node *m;

    struct node *temp;
void insert(int value){
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

int printList(){
    m=start;
    printf("Printing linked lists values:\n");
    while(m!=NULL){
        printf("%d ",m->data);
    m=m->next;
    }
}

void del_begin(){
    temp=start;
    start=start->next;
    free(temp); 
}

void del_end(){
    temp=start;
    if(start->next==NULL){
        free(start);
        start=NULL;
    }else{
        struct node *prev;
        temp=prev=start;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
    }
}

int main(){
    int i,n,x,ch2;
    char ch;
    printf("Enter the number of values you want to store:\n");
    scanf("%d",&n);
    printf("Enter the values you want to store:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }
    printList();
    printf("\nDo you want to delete first node?");
    printf("\nIf yes enter Y and if no enter N..\n");
    scanf("%c",&ch);
    scanf("%c",&ch);
    if(ch=='Y'||ch=='y'){
        del_begin();
    }else if(ch=='N'|ch=='n'){
        printf("First node is not deleted\n");
          printf("\nDo you want to delete last node?");
        printf("\nIf yes enter 1 and if no enter 0..\n");
        scanf("%d",&ch2);
        if(ch2==1){
            del_end();
        }else if(ch2==0){
            printf("Node is not deleted");
        }else{
        printf("Wrong input");}
        }
    else{
        printf("Wrong input");
    }
    printList();

    return 0;
}