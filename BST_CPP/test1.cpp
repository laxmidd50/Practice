#include "bst.h"

int main(int argc, char * argv[])
{
	struct BST* bst = BST_New();
	BST_Insert(bst, 1);
	BST_Insert(bst, 6);
	BST_Insert(bst, 4);
	BST_Insert(bst, 10);
	BST_Insert(bst, 3);
	BST_Insert(bst, 0);
	BST_Print(bst);
	return 0;
}
