#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct node* BST_NewNode(int x)
{
	struct node* newnode = malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;
	return newnode;
}

struct BST* BST_New()
{
	return (struct BST*)malloc(sizeof(struct BST));
}

void BST_Insert(struct BST* bst, int x)
{
	struct node* newnode = BST_NewNode(x);
	if (!bst)
		return;
	if (!bst->head)
	{
		bst->head = newnode;
		return;
	}
	struct node* curnode = bst->head;
	struct node* prevnode = NULL;

	while (curnode)
	{
		if (x > curnode->data)
		{
			prevnode = curnode;
			curnode = curnode->right;
		}
		else
		{
			prevnode = curnode;
			curnode = curnode->left;
		}
	}

	if (x > prevnode->data)
		prevnode->right = newnode;
	else
		prevnode->left = newnode;
}

int BST_Depth(struct node* tempnode, int level)
{
	if (!tempnode)
		return level;
	int left_depth = BST_Depth(tempnode->left, level+1);
	int right_depth = BST_Depth(tempnode->right, level+1);
	if (left_depth > right_depth)
		return left_depth;
	else
		return right_depth;
}

static void BST_PrintHelper(struct node* )
{

}

void BST_Print(struct BST* bst)
{
	struct node* tempnode = bst->head;
	int depth = BST_Depth(bst->head, 0);
	int i;

	int spaces = (1 << depth) / 2;
	for (i = 0; i < spaces; i++)
		printf(" ");
	printf("%d", tempnode->data);
}
