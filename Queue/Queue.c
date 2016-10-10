#include "Queue.h"
#include <stdlib.h>

struct Queue *Queue_New()
{
	struct Queue* tempQueue = malloc(sizeof(struct Queue));
	tempQueue->head = NULL;
}

void Enqueue(struct Queue *q, int x)
{
	if (!q)
		return;
	struct node *tempnode = malloc(sizeof(struct node));
	tempnode->data = x;
	tempnode->next = NULL;
	if (!q->head)
	{
		q->head = tempnode;
		return;
	}

	struct node *cur = q->head;
	while (cur->next)
		cur = cur->next;
	cur->next = tempnode;
}

int Dequeue(struct Queue *q)
{
	if (!q || !q->head)
		return -1;
	int temp = q->head->data;
	struct node *tempnode = q->head;
	q->head = q->head->next;
	free(tempnode);
	return temp;
}

int IsEmpty(struct Queue *q)
{
	if (!q || !q->head)
		return 1;
	else
		return 0;
}
