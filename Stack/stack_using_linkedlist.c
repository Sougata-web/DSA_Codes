#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
}*top;

    void push(int data){
        struct node * temp=(struct node *)malloc(sizeof(struct node));

        while(!temp){
            printf("\n Stack is over flowed.\n");
        }

        temp->data=data;
        temp->link=top;
        top=temp;

    }

    int isEmpty(){
        if(top==NULL){
            return 1;
        }else{
            return 0;
        }
    }

    int peek(){
        if(top==NULL){
            printf("The stack is empty..\n");
        }else{
            printf("%d\n",top->data);
        }
    }

    void pop(){
        struct node * temp=(struct node *)malloc(sizeof(struct node));

        if(top == NULL){
            printf("Under flow condition..\n");
        }else{
            temp=top;
            top=top->link;
            free(temp);
        }


    }

    void display()
	{
        struct node * temp=(struct node *)malloc(sizeof(struct node));

		if (top == NULL) {
			printf("\nStack Underflow");
			
		}
		else {
			temp = top;
			while (temp != NULL) {

			    printf("%d", temp->data);

				temp = temp->link;
				if (temp != NULL)
					printf(" -> ");
			}
		}
	}

    

int main(){

    

    peek();

    pop();
    display();
    
    return 0;
}