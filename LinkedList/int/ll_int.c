#include "ll_int.h"
#include <stdlib.h>
#include <stdio.h>

struct ll* new_ll()
{
	struct ll* list = malloc(sizeof(struct ll));
	list->head = NULL;
	return list;
}

struct node* newnode(int val)
{
	struct node* new_node = malloc(sizeof(struct node));
	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->val = val;
}

void ll_push_back(struct ll* list, int val)
{
	if (!list)
		return;

	struct node* temp_newnode = newnode(val);
	if (list->head == NULL)
	{
		list->head = temp_newnode;
	}
	else
	{
		struct node *curnode;
		curnode = list->head;
		while (curnode->next != NULL)
		{
			curnode = curnode->next;
		}
		curnode->next = temp_newnode;
	}
	return;
}

void ll_pop_back(struct ll* list)
{
	if (!list || !(list->head))
		return;

	if (list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
		return;
	}

	struct node *curnode = list->head;
	while (curnode->next->next != NULL)
	{
		curnode = curnode->next;
	}
	free(curnode->next);
	curnode->next = NULL;
}

void ll_print(struct ll* list)
{
	if (!list)
		return;
	int first = 1;
	printf("[");
	struct node* curnode = list->head;
	while (curnode)
	{
		if (first)
		{
			printf("%d", curnode->val);
			first = 0;
		}
		else
			printf(",%d", curnode->val);
		curnode = curnode->next;
	}
	printf("]\n");
}

void ll_insert(struct ll* list, int val, int index)
{
	if (!list || index < 0)
		return;
	struct node *temp_newnode = newnode(val);
	if (index == 0 || list->head == NULL)
	{
		temp_newnode->next = list->head;
		list->head = temp_newnode;
		return;
	}

	struct node* prvnode = list->head;
	struct node* curnode = list->head->next;
	int nodeIndex = 1;
	while (nodeIndex < index && curnode != NULL)
	{
		prvnode = curnode;
		curnode = curnode->next;
		nodeIndex++;
	}
	prvnode->next = temp_newnode;
	temp_newnode->next = curnode;
}

void ll_delete(struct ll* list, int index)
{
	if (!list || index < 0)
		return;
}
