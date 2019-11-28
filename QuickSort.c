#include<stdio.h>

void swap(int *idx1, int *idx2)
{
    int temp = *idx1;
    *idx1 = *idx2;
    *idx2 = temp;
}

//Function for partitioning
int partition (int arr[], int start, int end) {
    int pivot, up, down;
    pivot = arr[start];
    up = start;
    down = end;
    do {
        while(pivot >= arr[up] && up <= down)
            ++up;
        while(pivot < arr[down] && up <= down)
            --down;
        if(up <= down)
            swap(&arr[up], &arr[down]);
    }while(up <= down);
    swap(&arr[start], &arr[down]);
    return down;
}

// A function to implement quick sort
void quickSort(int arr[], int start, int end)
{
   int mid;
   mid = partition(arr, start, end);
   quickSort(arr, start, mid-1);
   quickSort(arr, mid+1, end);
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
    quickSort(arr, 0, 3);
    printf("Sorted array: \n");
    printArray(arr, 4);
    return 0;
}
