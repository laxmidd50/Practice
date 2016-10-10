struct b_node {
	int data;
	struct b_node* left;
	struct b_node* right;
};

struct BST {
	struct b_node* head;
};

struct BST* BST_New();
void BST_Insert(struct BST* bst, int x);
void BST_Print(struct BST* bst);
