//Create tree and traversals


#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left,*right;
}tree;

tree * create(){
    int val;
    tree* newTree=malloc(sizeof(tree));
    printf("\nEnter data: ");
    scanf("%d", &val);
    if(val ==-1){
        return 0;
    }
    newTree->data=val;
    printf("\nLeft child  of %d", val);
    newTree->left=create();
    printf("\nRight child of %d", val);
    newTree->right=create();
    return newTree;
}

void preorder(tree * root){
    if(root==NULL){
        return ;

    }else{
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(tree * root){
    if(root==NULL){
        return ;

    }else{
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
void postorder(tree * root){
    if(root==NULL){
        return ;

    }else{
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}

int main(){
    tree *root;
    root=0;
    root=create();
    printf("Pre order traversal\n");
    preorder(root);
    printf("In order traversal\n");

    inorder(root);
    printf("Post order traversal\n");

    postorder(root);
    free(root);
    return 0;
}