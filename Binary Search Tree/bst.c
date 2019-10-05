#include<stddef.h>
#include<stdint.h>
#include<assert.h>
#include<stdlib.h>
#include "bst.h"

BST bst_new()
{
	BST tree = {NULL,0};
	return tree;
}

static TreeNode* _make_new_node(int32_t element)
{
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = element;
	node->left = NULL;
	node->right = NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!= NULL);
	return tree->mass;
}

BST* bst_add_node(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	TreeNode *cur, *parent;
	cur = parent = tree->root;
	while(cur!= NULL && cur->data!=element)
	{
		parent = cur;
		if(element<cur->data){
			cur = cur->left;
		}
		else if(element>cur->data){
			cur = cur->right;
		}
	}
	if(cur==NULL){
		TreeNode *tnode = _make_new_node(element);
		if(parent==NULL){
			tree->root = tnode;
		}
		else if(element<parent->data){
			parent->left = tnode;
		}
		else if(element>parent->data){
			parent->right = tnode;
		}
		++tree->mass;
		}
		return tree;
	}

uint32_t bst_lookup(BST *tree, int32_t key)
{
	assert(tree!=NULL);
	TreeNode *cur = tree->root;
	while(cur!=NULL && cur->data!=key){
		if(key<cur->data){
			cur = cur->left;
		}
		else if(key>cur->data){
			cur = cur->right;
		}
	}
	return(cur!=NULL);
}

static TreeNode* _findmin_(TreeNode *node)
{
	if(node->left==NULL)
	{
		return node;
	}
	else
		return(_findmin_(node->left));
}

static TreeNode* _delete_(BST *tree, TreeNode *node, int32_t key)
{
	TreeNode *temp;
	if(node==NULL){
		return node;
	}
	else if(key<node->data){
		node->left=_delete_(tree,node->left,key);
	}
	else if(key>node->data){
		node->left=_delete_(tree,node->right,key);
    }
    else if(node->left && node->right){
       temp = _findmin_(node->right);
       node->data = temp->data;
       node->right = _delete_(tree, node->right,node->data);
    }
    else
    {
    	temp=node;
    	if(node->right==NULL){
    		node = node->left;
    	}
    	else{
    		node = node->right;
    	}
    	free(temp);
    	--tree->mass;
    }
    return node;
}

BST* bst_delete(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	tree->root = _delete_(tree, tree->root, element);
	return tree;
}

static void _inorder_(TreeNode *node) {
        if(node) {
            _inorder_(node->left);
            printf("%d\t", node->data);
            _inorder_(node->right);
        }
}

BST* in_order(BST *tree) {
    assert(tree->root != NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode *node) {
        if(node) {
            printf("%d\t", node->data);
            _preorder_(node->left);
            _preorder_(node->right);
        }
}

BST* pre_order(BST *tree) {
    assert(tree->root != NULL);
    _preorder_(tree->root);
}

static void _postorder_(TreeNode *node) {
        if(node) {
            _postorder_(node->left);
            _postorder_(node->right);
            printf("%d\t", node->data);

        }
}

BST* post_order(BST *tree) {
    assert(tree->root != NULL);
    _postorder_(tree->root);
}

static int height_tree(TreeNode *node) {
    int left_side;
    int right_side;
    left_side = height_tree(node->left);
    right_side = height_tree(node->right);
    if(left_side >= right_side)
    {
        printf("Height of Binary Tree = %d\n", (left_side+1));

    }else {
        printf("Height of Binary Tree = %d\n", (right_side+1));
    }
    return 0;
}

void height_of_binary_tree(BST *tree)
{
    assert(tree->root != NULL);
    height_tree(tree->root);
    //printf("Height of Binary Tree = %d\n", ht);
}

static int getLeafCount(TreeNode *node) {
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right==NULL)
        return 1;
    else
        return (getLeafCount(node->left)+ getLeafCount(node->right));
}

void count_terminalNodes(BST *tree) {
    assert(tree->root != NULL);
    int tnodes = getLeafCount(tree->root);
    printf("%d\t", tnodes);
}

static TreeNode* _findmax_(TreeNode *node)
{
    if(node->right==NULL)
	{
		return node;
	}
	else
		return(_findmax_(node->right));
}

int maximum_node(BST* tree) {
    assert(tree->root != NULL);
    TreeNode *temp;
    temp = _findmax_(tree->root);
    return 0;
}

int minimum_node(BST* tree) {
    assert(tree->root != NULL);
    TreeNode *temp;
    temp = _findmin_(tree->root);
    return 0;
}

