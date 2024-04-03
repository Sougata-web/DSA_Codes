#include "Tree.h"

tree *createTree(tree * root,int value)
{
    tree *newTree = malloc(sizeof(tree));
    if (root == NULL)
    {
        root = createTree(root,value);
        return root;
    }
    else if (value < root->data && value != root->data)
    {
        root->left = createTree(root->left, value);
    }
    else if (value > root->data && value != root->data)
    {
        root->right = createTree(root->right, value);
    }
    else
    {
        printf("\nEnter a valid input\n");
    }
    newTree->data = value;
    return newTree;
}

// tree *insertTree(tree *root, int value)
// {
    
//     return root;
// }

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
