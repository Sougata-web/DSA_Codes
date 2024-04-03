#include "Tree.h"

int main()
{
    tree *root;
    root = 0;
    root = create();
    printf("Pre order traversal\n");
    preorder(root);
    printf("In order traversal\n");

    inorder(root);
    printf("Post order traversal\n");

    postorder(root);
    free(root);
    return 0;
}