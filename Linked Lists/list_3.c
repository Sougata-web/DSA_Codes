#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *start=NULL,*temp=NULL;
struct node *l1,*l2;

void insertL1(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=value;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        struct node *l1;
        l1=start;
        while(l1->next != NULL)
            l1=l1->next;
        l1->next=temp;
    }
}
void insertL2(int value){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=value;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        struct node *l2;
        l2=start;
        while(l2->next != NULL)
            l2=l2->next;
        l2->next=temp;
    }
}

int mergerList(struct node *l1, struct node *l2){
    if(l1==NULL || l2==NULL){
        return l1?l1:l2;
    }
    if(l1->val<l2->val){
        start=temp=l1;
        l1=l1->next;
    }
    else{
        start=temp=l2;
        l2=l2->next;
    }
    while (l1&&l2)
    {
        if(l1->val<=l2->val){
            temp->next=l1;
            l1=l1->next;
        }
        else{
            temp->next=l2;
            l2=l2->next;
        }
    temp=temp->next;
    }
    temp->next=(l1==NULL)?l2:l1;
    return start;
    
}

int printList(){
    
    printf("Printing linked lists values:\n");
    while(start!=NULL){
        printf("%d ",start->val);
    start=start->next;
    }
}
int main(){
    int i,n,x,y;
    printf("Enter the number of values you want to store:\n");
    scanf("%d",&n);
    printf("Enter the values you want to store:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insertL1(x);
    }
    for(i=0;i<n;i++){
        scanf("%d",&y);
        insertL2(y);
    }

    mergerList(l1,l2);
    printList();
    
    return 0;
}