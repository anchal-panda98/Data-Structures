#include <assert.h>
#include "bst.h"

void test_addition()
{
	BST b = bst_new();
	BST *bst = &b;
	bst = bst_add_node(bst, 50);
	assert (bst_count(bst) == 1);

	bst = bst_add_node(bst, 20);
	bst = bst_add_node(bst, 60);
	bst = bst_add_node(bst, 55);
	bst = bst_add_node(bst, 80);
	bst = bst_add_node(bst, 85);
	bst = bst_add_node(bst, 30);

	assert (bst_count(bst) == 7);
    bst = bst_delete(bst, 20);
    printf("In-Order Traversal:\t");
    in_order(bst);
    printf("\n");
    printf("Pre-Order Traversal:\t");
    pre_order(bst);
    printf("\n");
    printf("Post-Order Traversal:\t");
    post_order(bst);
    printf("\n");

    printf("Total number of terminal nodes in the Binary Tree: ");
    count_terminalNodes(bst);
	assert (bst_lookup(bst, 80));
	//height_of_binary_tree(bst);
	maximum_node(bst);
	minimum_node(bst);

}

int main()
{
	test_addition();
	return 0;
}
