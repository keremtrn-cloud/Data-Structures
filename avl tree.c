#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *ltree;
	struct Node *rtree;
	int height;
};


int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return 1+max(height(N->ltree), height(N->rtree));
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->ltree= NULL;
	node->rtree = NULL;
	node->height = 0; // new node is initially added at leaf
	return(node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->ltree;
	struct Node *T2 = x->rtree;
	
	x->rtree = y;
	y->ltree = T2;

	y->height = height(y);
	x->height = height(x);

	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->rtree;
	struct Node *T2 = y->ltree;

	y->ltree = x;
	x->rtree = T2;

	x->height = height(x);
	y->height = height(y);

	return y;
}
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->ltree) - height(N->rtree);
}

struct Node* insert(struct Node* node, int key)
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->ltree = insert(node->ltree, key);
	else if (key > node->key)
		node->rtree = insert(node->rtree, key);
	else 
		return node;

	node->height = height(node);

	int balance = getBalance(node);


	if (balance > 1 && key < node->ltree->key)
		return rightRotate(node);

	if (balance < -1 && key > node->rtree->key)
		return leftRotate(node);

	if (balance > 1 && key > node->ltree->key)
	{
		node->ltree = leftRotate(node->ltree);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->rtree->key)
	{
		node->rtree = rightRotate(node->rtree);
		return leftRotate(node);
	}

	return node;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->ltree);
		preOrder(root->rtree);
	}
}

int main()
{
struct Node *root = NULL;


root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);


printf(" Avl tree is %d");
preOrder(root);

return 0;
}
