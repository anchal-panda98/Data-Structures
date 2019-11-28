#include<stdio.h>

void swap(int *idx1, int *idx2)
{
    int temp = *idx1;
    *idx1 = *idx2;
    *idx2 = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int size)
{
   int pass, index;
   for (pass = 0; pass < size-1; pass++)

       // Last i elements are already in place
       for (index = 0; index < size-pass-1; index++)
           if (arr[index] > arr[index+1])
              swap(&arr[index], &arr[index+1]);
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
    bubbleSort(arr, 4);
    printf("Sorted array: \n");
    printArray(arr, 4);
    return 0;
}
