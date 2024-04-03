#include "Tree.h"

int main(){

    tree * root=NULL;
    printf("Make a Tree");

    while(1){
        int choice;
        printf("\n1. Create Tree\n 2. \n3. Pre Order Traversal\n 4. In Order Traversal\n 5. Post Order Traversal\n6. Exit\n");
        printf("Enter Your Choice:\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            int value;
            printf("Enter the value of root:\n");
            scanf("%d",&value);
            createTree(root,value);
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