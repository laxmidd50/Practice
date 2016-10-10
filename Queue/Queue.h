struct node{
	int data;
	struct node *next;
};

struct Queue{
	struct node *head;
};

struct Queue *Queue_New();
void Enqueue(struct Queue *q, int x);
int Dequeue(struct Queue *q);
int IsEmpty(struct Queue *q);
