#include<stdio.h>

void swap(int *idx1, int *idx2)
{
    int temp = *idx1;
    *idx1 = *idx2;
    *idx2 = temp;
}

// A function to implement selection sort
void selectionSort(int arr[], int size)
{
   int pass, index, min_pos;
   for (pass = 0; pass < size-1; ++pass) {
        min_pos = pass;
       // Last i elements are already in place
       for (index = pass + 1; index < size; ++index)
           if (arr[index] < arr[min_pos])
              min_pos = index;
       swap(&arr[pass], &arr[min_pos]);
   }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int idx;
    for (idx=0; idx < size; idx++)
        printf("%d ", arr[idx]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {15, 25, 5, 12};
    selectionSort(arr, 4);
    printf("Sorted array: \n");
    printArray(arr, 4);
    return 0;
}
