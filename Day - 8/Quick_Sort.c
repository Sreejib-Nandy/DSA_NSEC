#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot_ele = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= pivot_ele && i <= high - 1) {
            i++;
        }
        while(arr[j] > pivot_ele && j >= low + 1) {
            j--;
        }
        if(i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j], &arr[low]);
    return j;
}

void QuickSort(int arr[], int low, int high) {
    if(low < high) {
        int par = partition(arr, low, high);
        QuickSort(arr, low, par - 1);
        QuickSort(arr, par + 1, high);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100],index;
    printf("Enter the number of index : ");
    scanf("%d", &index); // 10
    printf("Enter the elements of the array : ");
    for (int i = 0; i < index; i++)
    {
        scanf("%d", &arr[i]); // 14 57 48 6 95 33 47 87 21 3 
    }
    printf("Before Sorting : ");
    print_array(arr, index);
    QuickSort(arr, 0, index - 1);
    printf("After Sorting : ");
    print_array(arr, index);
    return 0;
}