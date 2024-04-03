#include "Tree.h"

int main()
{
    tree *root=NULL;
    
    root = create(1);
    printf("Pre order traversal\n");
    preorder(root);
    printf("In order traversal\n");

    inorder(root);
    printf("Post order traversal\n");

    postorder(root);
    free(root);
    return 0;
}