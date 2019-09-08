/* 
 * C program to find union and intersection of two unsorted linked lists
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node* next;
};

void insert(struct Node** head_ref, int new_data);

bool isPresent(struct Node *head, int data);

// Function to get union of two linked lists
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
	struct Node *result = NULL;
	struct Node *t1 = head1, *t2 = head2;

	while (t1 != NULL)
	{
		insert (&result, t1->data);
		t1 = t1->next;
	}

	while (t2 != NULL)
	{
		if (!isPresent(result, t2->data))
			insert (&result, t2->data);
		t2 = t2->next;
	}

	return result;
}

// Function to get intersection of two linked lists
struct Node *getIntersection(struct Node *head1, struct Node *head2)
{
	struct Node *result = NULL;
	struct Node *t1 = head1;

	while (t1 != NULL)
	{
		if (isPresent(head2, t1->data))
			insert (&result, t1->data);
		t1 = t1->next;
	}

	return result;
}

// Function to insert a node at the begining of a linked list
void insert (struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

// Function to print a linked list
void printList (struct Node *node)
{
	while (node != NULL)
	{
		printf ("%d ", node->data);
		node = node->next;
	}
}

// Function that returns true if data is present in linked list else return false
bool isPresent (struct Node *head, int data)
{
	struct Node *t = head;
	while (t != NULL)
	{
		if (t->data == data)
			return 1;
		t = t->next;
	}
	return 0;
}

// Program to test above function
int main()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* intersectn = NULL;
	struct Node* unin = NULL;

	/*create a linked lits 10->15->5->20 */
	insert (&head1, 20);
	insert (&head1, 4);
	insert (&head1, 15);
	insert (&head1, 10);

	/*create a linked lits 8->4->2->10 */
	insert (&head2, 10);
	insert (&head2, 2);
	insert (&head2, 4);
	insert (&head2, 8);

	intersectn = getIntersection (head1, head2);
	unin = getUnion (head1, head2);

	printf ("\n First list is \n");
	printList (head1);

	printf ("\n Second list is \n");
	printList (head2);

	printf ("\n Intersection list is \n");
	printList (intersectn);

	printf ("\n Union list is \n");
	printList (unin);

	return 0;
}
