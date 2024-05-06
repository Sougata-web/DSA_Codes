#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to search for a value in BST
struct TreeNode* searchBST(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return searchBST(root->left, value);
    } else {
        return searchBST(root->right, value);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};

    // Inserting elements into the BST
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        root = insertNode(root, elements[i]);
    }

    int searchValue = 100;

    // Search for a value in the BST
    struct TreeNode* result = searchBST(root, searchValue);

    // Check if the value is found
    if (result != NULL) {
        printf("Element %d found in the BST.\n", searchValue);
    } else {
        insertNode(root,searchValue);
        printf("Element %d not found in the BST.\n", searchValue);
    }

    struct TreeNode * resul=searchBST(root,searchValue);
    if (resul!= NULL) {
        printf("Element %d found in the BST.\n", searchValue);
    } else {
        insertNode(root,searchValue);
        printf("Element %d not found in the BST.\n", searchValue);
    }

    return 0;
}
