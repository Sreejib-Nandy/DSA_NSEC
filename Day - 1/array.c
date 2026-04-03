#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0; // Current size of the array

void insertAtFirst(int val) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    n++;
}

void insertAtLast(int val) {
    arr[n] = val;
    n++;
}

void insertAtPosition(int pos, int val) {
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
}

void deleteAtPosition(int pos) {
    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void search(int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i + 1);
            return;
        }
    }
    printf("Element not found!\n");
}

void deleteDuplicates() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
}

void display() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findMax() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);
}

void findMin() {
    if (n == 0) {
        printf("Array is empty!\n");
        return;
    }
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum element: %d\n", min);
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n------Menu------\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert at position\n");
        printf("4. Delete\n");
        printf("5. Search\n");
        printf("6. Delete duplicates\n");
        printf("7. Display\n");
        printf("8. Find maximum\n");
        printf("9. Find minimum\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at first: ");
                scanf("%d", &val);
                insertAtFirst(val);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &val);
                insertAtLast(val);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtPosition(pos, val);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 6:
                deleteDuplicates();
                printf("Duplicates deleted!\n");
                break;
            case 7:
                display();
                break;
            case 8:
                findMax();
                break;
            case 9:
                findMin();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
