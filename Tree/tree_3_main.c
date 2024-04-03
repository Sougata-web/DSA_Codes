#include "Tree.h"

int main(){

    tree * root=NULL;
    printf("Make a Tree");
    while(1){
        int choice;

        switch (choice)
        {
        case 1:
            int value;
            printf("Enter the value of root:\n");
            scanf("%d",&value);
            createTree(value);
            break;
        case 2:
           
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(1);
        
        default:
        printf("\nEnter valid choice\n");
            break;
        }

    }

    return 0;
}