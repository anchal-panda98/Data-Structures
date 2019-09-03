/*
 * C Program to Implement Singly Linked List using Dynamic Memory Allocation
 */

#ifndef SLIST_ASSIGNMENT_H_INCLUDED
#define SLIST_ASSIGNMENT_H_INCLUDED
#include <stdio.h>
#include <malloc.h>
#define ISEMPTY printf("\nEMPTY LIST:");

/*
 * Node Declaration
 */

typedef struct node snode;
struct node
{
    int value;
    struct node *next;
};

snode* create_node(int);
void insert_node_first();
void insert_node_last();
void insert_node_pos();
//void sorted_ascend();
void delete_pos();
void list_search();
//void update_val();
void display();
void rev_display(snode *);
int list_length(snode *);
int maximum_list();
int minimum_list();

#endif // SLIST_ASSIGNMENT_H_INCLUDED