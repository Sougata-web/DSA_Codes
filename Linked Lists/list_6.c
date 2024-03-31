#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *l;
 node *insert_end(int data,node*start){
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;

    if(start==NULL){
        start=newnode;

    }else{
        node *m;
        m=start;
        while(m->next!=NULL){
            m=m->next;
        }
        m->next=newnode;
    }
    return start;
 }


int main(){
    int i,n,x,y,z=1;
    node*link1=NULL;
    node*link2=NULL;
    node*last=NULL;
    printf("Enter the size of linked list:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the first linked lists %dno value at position %d:\n",z,i);
        scanf("%d",&x);
        link1=insert_end(x,link1);
        printf("Enter the second linked lists %dno value at position %d:\n",z,i);
        scanf("%d",&y);
        link2=insert_end(y,link2);
        last=insert_end(x+y,last);
        z++;
    }
    l=last;
    printf("Printing linked lists values:\n");
    while(l!=NULL){
        printf("%d ",l->data);
    l=l->next;
    }
    
    return 0;
}