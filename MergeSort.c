#include<stdio.h>

int size = 4;
//Function for partitioning
int merge (int arr[], int start, int mid, int end) {
    int f_index, t_index, s_index, idx;
    int temp[size];
    f_index = t_index = start;
    s_index = mid + 1;
    while(f_index <= mid && s_index <= end) {
        if(arr[f_index] <= arr[s_index]){
            temp[t_index++] = arr[f_index++];
        }else {
            temp[t_index++] = arr[s_index++];
        }
    }
    if(f_index < mid) {
        for(idx = f_index; idx <= mid; ++idx)
            temp[t_index++] = arr[idx];
    }
    else {
        for(idx = s_index; idx <= end; ++idx)
            temp[t_index++] = arr[idx];
    }
    for(idx = start; idx <= end; ++idx)
        arr[idx] = temp[idx];
}

// A function to implement quick sort
void mergeSort(int arr[], int start, int end)
{
   int mid;
   mid = (start + end)/2;
   mergeSort(arr, start, mid);
   mergeSort(arr, mid+1, end);
   merge(arr, start, mid, end);
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
    mergeSort(arr, 0, 3);
    printf("Sorted array: \n");
    printArray(arr, 4);
    return 0;
}
