#include "Tree.h"

tree* create(int value){
    tree* newTree=malloc(sizeof(tree));
    newTree->data=value;
    newTree->left=NULL;
    newTree->right=NULL;
    return newTree;
}

tree* insertTree(tree * root, int value){
    if(root == NULL){
        root=create(value);
        return root;
    }
    else if(value < root->data && value != root->data){
        root->left=insertTree(root->left,value);
    }else if(value > root->data && value != root->data){
        root->right=insertTree(root->right,value);
    }else{
        printf("\nEnter a valid input\n");
    }
}

void preorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}
void postorder(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->data);
    }
}

