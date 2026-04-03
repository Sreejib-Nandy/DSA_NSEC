#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start;

void create(int n) {
    int val;
    struct node *p;
    int i, item;
    if(n <= 0) {
        printf("Negative index or zero is not allowed!");
        return;
    }
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &val);
    p -> data = val;
    p -> next = NULL;
    start = p;
    for (i = 2; i <= n; i++)
    {
        p -> next = (struct node *)malloc(sizeof(struct node));
        p = p -> next;
        printf("Enter the value : ");
        scanf("%d", &val);
        p -> data = val;
        p -> next = NULL;
    }
}

void insert_beg() {
    int item;
    struct node* p = start, *temp;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = p;
    start = temp; 
}

void insert_end() {
    int item;
    struct node* p = start, *temp;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = NULL;
    if (start == NULL) {
        start = temp;
        return;
    }
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = temp; 
}

void insert_loc(int location) {
    if (location <= 0) {
        printf("Invalid location!\n");
        return;
    }
    if (location == 1) {
        insert_beg();
        return;
    }
    int item;
    struct node* p = start, *temp;
    for (int i = 1; i < location - 1 && p != NULL; i++)
    {
        p = p -> next;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &item);
    temp -> data = item;
    temp -> next = p -> next;
    p -> next = temp;  
}

void insert_val(int value) {
    struct node* p = start, *temp;
    int item;
    printf("Enter the new value : ");
    scanf("%d", &item);
    while (p != NULL && p -> data != value) 
    {
        p = p -> next;
    }
    if (p == NULL) {
        printf("%d not found in the linked list!\n", value);
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = p -> next;
    p -> next = temp;
}

void search_val(int value) {
    struct node* p = start;
    int count = 1, found = 0;
    while (p != NULL) {
        if (p -> data == value) {
            printf("%d found at position %d in the linked list!\n", value, count);
            found = 1; 
        }
        p = p -> next;
        count++;
    }
    if (!found) {
        printf("%d not found in the linked list!\n", value);
    }
}

void display() {
    struct node* p = start;
    printf("Elements in the linkedlist are : ");
    while (p != NULL)
    {
        printf("%d ", p -> data);
        p = p -> next;
    }  
}

void delete_beg() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* p = start;
    start = start -> next;
    free(p);  
}

void delete_end() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (start -> next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    struct node* p = start, *old;
    while (p -> next != NULL)
    {
       old = p;
       p = p -> next;
    }
    old -> next = NULL;
    free(p);
}

void count_nodes() {
    struct node* p = start;
    int count = 0;
    while(p != NULL) {
        count++;
        p = p -> next;
    }
    printf("The number of nodes are : %d", count);
}

void del_loc(int location) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (location <= 0) {
        printf("Invalid location!\n");
        return;
    }
    if (location == 1) {
        delete_beg();
        return;
    }
    struct node* p = start, *old;
    for (int i = 1; i < location && p != NULL; i++)
    {
        old = p;
        p = p -> next;
    }
    if (p == NULL) {
        printf("Location out of range!\n");
        return;
    }
    old -> next = p -> next;
    free(p);
}

void del_val(int value) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (start -> data == value) {
        delete_beg();
        return;
    }
    struct node* p = start, *old;
    while(p != NULL && p -> data != value) {
        old = p;
        p = p -> next;
    }
    if (p == NULL) {
        printf("%d not found in the linked list!\n", value);
        return;
    }
    old -> next = p -> next;
    free(p);
}

void reverse_linked_list() {
    struct node *curr = start, *prev = NULL, *next_one = NULL;
    while(curr != NULL) {
        next_one = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next_one;
    }
    start = prev;
}

void del_duplicate_values() {
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while(ptr1 != NULL && ptr1 -> next != NULL) {
        ptr2 = ptr1;
        while(ptr2 -> next != NULL) {
            if(ptr1 -> data == ptr2 -> next -> data) {
                dup = ptr2 -> next;
                ptr2 -> next = ptr2 -> next -> next;
                free(dup);
            } else {
                ptr2 = ptr2 -> next;
            }
        }
        ptr1 = ptr1 -> next;
    }
}

void sort_linked_list() {
    struct node *i, *j;
    int swapped;
    if (start == NULL) {
        return;
    }
    for(i = start; i -> next != NULL; i = i -> next) {
        swapped = 0;
        for(j = start; j -> next != NULL; j = j -> next) {
            if(j -> data > j -> next -> data) {
                int temp = j -> data;
                j -> data = j -> next -> data;
                j -> next -> data = temp;
                swapped = 1;
            }
        }
        if(swapped == 0) {
            break;
        }
    }
}

int main() {
    int choice,node_num,location,val,sv_val,del_location,del_value;
    printf("Enter the number of nodes do you want : ");
    scanf("%d", &node_num);
    create(node_num);
    while(1) {
    printf("\n-----Menu-----\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at a Given Location\n");
    printf("4. Insert after a Given value\n");
    printf("5. Search a given node value\n");
    printf("6. Display Node values\n");
    printf("7. Delete Beginning node\n");
    printf("8. Delete End Node\n");
    printf("9. Count the number of nodes\n");
    printf("10. Delete a given positioned node\n");
    printf("11. Delete a given value node\n");
    printf("12. Reverse the entire list\n");
    printf("13. Delete duplicate values in the list\n");
    printf("14. Sort the list\n");
    printf("15. Exit\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert_beg();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        printf("Enter the location : ");
        scanf("%d", &location);
        insert_loc(location);
        break;
    case 4:
        printf("Enter the existing value : ");
        scanf("%d", &val);
        insert_val(val);
        break;
    case 5:
        printf("Enter the value : ");
        scanf("%d", &sv_val);
        search_val(sv_val);
        break;
    case 6:
        display();
        break;
    case 7:
        delete_beg();
        break;
    case 8:
        delete_end();
        break;
    case 9:
        count_nodes();
        break;
    case 10:
        printf("Enter the location : ");
        scanf("%d", &del_location);
        del_loc(del_location);
        break;
    case 11:
        printf("Enter the value : ");
        scanf("%d", &del_value);
        del_val(del_value);
        break;
    case 12:
        reverse_linked_list();
        break;
    case 13:
        del_duplicate_values();
        break;
    case 14:
        sort_linked_list();
        break;
    case 15:
        exit(0);
    default:
        printf("Wrong Input.\n");
    }
    }
    return 0;
}