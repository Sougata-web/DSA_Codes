
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

void printCurrentLevel(struct node *root, int level);
int height(struct node *node);
struct node *newNode(int data);

void printLevelOrder(struct node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

void printCurrentLevel(struct node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

int height(struct node *node)
{
	if (node == NULL)
		return 0;
	else
	{

		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

void breadthFirstTraversal(struct node *root)
{
	if (root == NULL)
		return;
	struct node *queue[100];
	int front = 0, rear = 0;
	queue[rear++] = root;
	while (front < rear)
	{
		struct node *current = queue[front++];
		printf("%d ", current->data);
		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}
}

// void bfs(struct node *root){
// 	if(root ==NULL){
// 		return;
// 	}
// 	struct node *queue[100];
// 	int front =0,rear=0;
// 	queue[rear++]=root;
// 	while(front<rear){
// 		struct node * current=queue[front++];
// 		printf("%d ",current->data);
// 		if(current->left!=NULL){
// 			queue[rear++]=current->left;
// 		}
// 		if(current->right!=NULL){
// 			queue[rear++]=current->right;
// 		}
// 	}
// }

struct node *newNode(int data)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node *root = newNode(1);
	root->left = newNode(7);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(3);

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);
	printf("\n\n");
	bfs(root);

	return 0;
}
