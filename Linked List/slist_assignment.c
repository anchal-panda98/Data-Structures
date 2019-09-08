/*
 * Utility Functions
 */
#include <stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include "slist_assignment.h"

snode *newnode, *ptr, *prev, *temp;
snode *first = NULL, *last = NULL;

/*
 * Creating Node
 */
snode* create_node(int val)
{
    newnode = (snode *)malloc(sizeof(snode));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

/*
 * Inserting Node at First
 */
void insert_node_first()
{
    int val;

    printf("\nEnter the value for the node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && first == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
    printf("\n----INSERTED----");
}

/*
 * Inserting Node at Last
 */
void insert_node_last()
{
    int val;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 printf("\n----INSERTED----");
}

/*
 * Inserting Node at position
 */
void insert_node_pos()
{
    int pos, val, cnt = 0, i;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
     printf("\nEnter the position: ");
    scanf("%d", &pos);
    ptr = first;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
        printf("\nInserted");
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = first;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\n----INSERTED----");
    }
    else
    {
        printf("Position is out of range");
    }
}

/*
 * Delete Node from specified position in a non-empty list
 */
void delete_pos()
{
    int pos, cnt = 0, i;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}

/*
 * searching an element in a non-empty list
 */
void search()
{
    int flag = 0, key, pos = 0;

    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search");
        scanf("%d", &key);
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}

/*
 * Displays non-empty List from Beginning to End
 */
void display()
{
    if (first == NULL)
    {
        ISEMPTY;
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}

/*
 * Display non-empty list in Reverse Order
 */
void rev_display(snode *ptr)
{
    int val;

    if (ptr == NULL)
    {
        ISEMPTY;
        printf(":No nodes to display\n");
    }
    else
    {
        if (ptr != NULL)
        {
            val = ptr->value;
            rev_display(ptr->next);
            printf("%d\t", val);
        }

    }
}

/*
 * Count number of elements in the list
 */
int list_length(snode *ptr)
{
    int count = 0;  // Initialize count
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

/*
 * Maximum and Minimum elements in the list
 */
int maximum_list(snode *ptr)
{
    if(ptr!=NULL){
        int max_value=ptr->value;
        while(ptr!=NULL){
            if(max_value < ptr->value){
                max_value = ptr->value;
            }
            ptr = ptr->next;
        }
        return max_value;
    }
    else{
        printf("\n Empty linked list \n");
    }
}

int minimum_list(snode *ptr)
{
    if(ptr!=NULL){
        int min_value = ptr->value;
        while(ptr!=NULL){
            if(min_value > ptr->value){
                min_value = ptr->value;
            }
            ptr = ptr->next;
        }
        return min_value;
    }
    else{
        printf("\n Empty linked list \n");
    }
}
