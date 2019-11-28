#include<stdio.h>

void swap(int *idx1, int *idx2)
{
    int temp = *idx1;
    *idx1 = *idx2;
    *idx2 = temp;
}

// A function to implement insertion sort
void insertionSort(int arr[], int size)
{
   int pass, index, key;
   for (pass = 1; pass < size; ++pass) {
        key = arr[pass];
        index = pass - 1;
       // Last i elements are already in place
       while(index >= 0 && arr[index] > key) {
           arr[index+1] = arr[index];
           --index;
       }
       arr[index+1] = key;
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
    insertionSort(arr, 4);
    printf("Sorted array: \n");
    printArray(arr, 4);
    return 0;
}
