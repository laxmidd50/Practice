#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct b_node* BST_NewNode(int x)
{
	struct b_node* newnode = malloc(sizeof(struct b_node));
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
	struct b_node* newnode = BST_NewNode(x);
	if (!bst)
		return;
	if (!bst->head)
	{
		bst->head = newnode;
		return;
	}
	struct b_node* curnode = bst->head;
	struct b_node* prevnode = NULL;

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

int BST_Depth(struct b_node* tempnode, int level)
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

static void BST_PrintHelper(struct b_node* n)
{

}

void BST_Print(struct BST* bst)
{
	struct b_node* tempnode = bst->head;
	int depth = BST_Depth(bst->head, 0);
	int i;

	int spaces = (1 << depth) / 2;
	for (i = 0; i < spaces; i++)
		printf(" ");
	printf("%d", tempnode->data);




}
