/*
 * Main :
 * 1. Insert node at first
 * 2. Insert node at last
 * 3. Insert node at position
 * 4. Delete Node from any Position
 * 5. Search Element in the linked list
 * 6. Display List from Beginning to end
 * 7. Display List in reverse using Recursion
 * 8. Count Number of Elements in the List
 * 9. Finding the Maximum and Minimum elements in the List
 */

#include<stdio.h>
#include "slist_assignment.c"

 int main()
 {
    int ch, length, max_element, min_element;
    char ans = 'Y';

    while (ans == 'Y'||ans == 'y')
    {
        printf("\n---------------------------------\n");
        printf("\nOperations on singly linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1.Insert node at first");
        printf("\n2.Insert node at last");
        printf("\n3.Insert node at position");
        //printf("\n4.Sorted Linked List in Ascending Order");
        printf("\n4.Delete Node from any Position");
        //printf("\n5.Update Node Value");
        printf("\n5.Search Element in the linked list");
        printf("\n6.Display List from Beginning to end");
        printf("\n7.Display List from end using Recursion");
        printf("\n8.Count Number of Elements in the List");
        printf("\n9.Finding the Maximum and Minimum elements in the List");
        printf("\n10.Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n...Inserting node at first...\n");
            insert_node_first();
            break;
        case 2:
            printf("\n...Inserting node at last...\n");
            insert_node_last();
            break;
        case 3:
            printf("\n...Inserting node at position...\n");
            insert_node_pos();
            break;
        /*case 4:
            printf("\n...Sorted Linked List in Ascending Order...\n");
            sorted_ascend();
            break;*/
        case 4:
            printf("\n...Deleting Node from any Position...\n");
            delete_pos();
            break;
        /*case 5:
            printf("\n...Updating Node Value...\n");
            update_val();
            break;*/
        case 5:
            printf("\n...Searching Element in the List...\n");
            search();
            break;
        case 6:
            printf("\n...Displaying List From Beginning to End...\n");
            display();
            break;
        case 7:
            printf("\n...Displaying List From End using Recursion...\n");
            rev_display(first);
            break;
        case 8:
            printf("\n...Counting number of elements in the List...\n");
            length = list_length(first);
            printf("Number of elements in the List = %d", length);
            break;
        case 9:
            printf("\n...Maximum & Minimum number of Elements in the List ...\n");
            max_element = maximum_list(first);
            min_element = minimum_list(first);
            printf("Maximum element = %d and Minimum element = %d", max_element, min_element);
            break;
        case 10:
            printf("\n...Exiting...\n");
            return 0;
            break;
        default:
            printf("\n...Invalid Choice...\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N)");
        scanf(" %c", &ans);
    }
    return 0;
 }
