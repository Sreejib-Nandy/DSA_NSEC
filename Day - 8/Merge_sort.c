#include <stdio.h>

void Merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = low;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i < n1) {
        arr[k++] = L[i++];
    }

    while(j < n2) {
        arr[k++] = R[j++];
    }
}

void MergeSort(int arr[], int low, int high) {
    int mid;
    if(low < high) {
        mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
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
    MergeSort(arr, 0, index - 1);
    printf("After Sorting : ");
    print_array(arr, index);
    return 0;
}