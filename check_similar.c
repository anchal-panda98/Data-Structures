/*
 * Program to compare if two lists are similar
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

//Function to check similarity
int similarity_check(struct Node* head1, struct Node* head2)
{
	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data != head2->data)
		{
			return 0;
		}
		else
		{
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	if(head1 != NULL || head2 != NULL)
		return 0;
	else
		return 1;
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

// Program to test above function
int main()
{
	int result;
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	
	/*create a linked lits 10->15->5->20 */
	insert (&head1, 20);
	insert (&head1, 4);
	insert (&head1, 15);
	insert (&head1, 10);

	/*create a linked lits 8->4->2->10 */
	insert (&head2, 20);
	insert (&head2, 4);
	insert (&head2, 15);
	//insert (&head2, 8);

	printf ("\n First list is \n");
	printList (head1);

	printf ("\n Second list is \n");
	printList (head2);

	/* checking similarity */
	result = similarity_check(head1, head2);

	if(result == 1)
		printf("Both the lists are same");
	else
		printf("The lists are not same");

	return 0;
}
