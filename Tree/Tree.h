#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left,*right;
}tree;

tree * create();
void preorder(tree * root);
void inorder(tree *root);
void postorder(tree *root);