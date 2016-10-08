struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct BST {
	struct node* head;
};

struct BST* BST_New();
void BST_Insert(struct BST* bst, int x);
void BST_Print(struct BST* bst);
