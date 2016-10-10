#include "Queue.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct Queue *q = Queue_New();
	Enqueue(q, 1);
	Enqueue(q, 4);
	Enqueue(q, 3);
	Enqueue(q, 1);
	Enqueue(q, 7);
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	printf("%d\n", Dequeue(q));
	Enqueue(q, 7);
	printf("%d\n", Dequeue(q));
}
