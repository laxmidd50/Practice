struct node {
	int val;
	struct node *next;
};

struct ll {
	struct node *head;
};

struct ll* new_ll();
struct node* newnode(int val);
void ll_push_back(struct ll* list, int val);
void ll_pop_back(struct ll* list);
void ll_print(struct ll* list);
void ll_insert(struct ll* list, int val, int index);
void ll_delete(struct ll* list, int index);
