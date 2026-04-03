#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start;

void create(int n) {
    int val;
    struct node *p, *newNode;
    int i, item;
    if(n <= 0) {
        printf("Negative index or zero is not allowed!");
        return;
    }
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &val);
    p -> prev = NULL;
    p -> data = val;
    p -> next = NULL;
    start = p;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value : ");
        scanf("%d", &val);
        newNode -> prev = p;
        newNode -> data = val;
        newNode -> next = NULL;
        p -> next = newNode;
        p = newNode;
    }
}

void insert_beg() {
    int item;
    struct node *temp;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> prev = NULL;
    temp -> data = item;
    temp -> next = start;
    if(start != NULL) {
        start -> prev = temp;
    }
    start = temp; 
}

void insert_end() {
    int item;
    struct node *temp, *p = start;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = NULL;
    if (start == NULL) {
        temp->prev = NULL;
        start = temp;
        return;
    }
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    temp -> prev = p;
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
    if (p == NULL) {
        printf("Location out of range!\n");
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &item);
    temp -> prev = p;
    temp -> data = item;
    temp -> next = p -> next;
    if (p -> next != NULL) {
        p -> next -> prev = temp;
    }
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
    temp -> prev = p;
    temp -> data = item;
    temp -> next = p -> next;
    if (p -> next != NULL) {
        p -> next -> prev = temp;
    }
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
    if (start != NULL) {
        start -> prev = NULL;
    }
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
    struct node* p = start;
    while (p -> next != NULL)
    {
       p = p -> next;
    }
    p -> prev -> next = NULL;
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
    struct node* p = start;
    for (int i = 1; i < location && p != NULL; i++)
    {
        p = p -> next;
    }
    if (p == NULL) {
        printf("Location out of range!\n");
        return;
    }
    if (p -> prev != NULL) {
        p -> prev -> next = p -> next;
    }
    if (p -> next != NULL) {
        p -> next -> prev = p -> prev;
    }
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
    struct node* p = start;
    while(p != NULL && p -> data != value) {
        p = p -> next;
    }
    if (p == NULL) {
        printf("%d not found in the linked list!\n", value);
        return;
    }
    if (p -> prev != NULL) {
        p -> prev -> next = p -> next;
    }
    if (p -> next != NULL) {
        p -> next -> prev = p -> prev;
    }
    free(p);
}

void reverse_linked_list() {
    struct node *curr = start;
    struct node *temp = NULL;
    while(curr != NULL) {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }
    if(temp != NULL) {
        start = temp -> prev;
    }
}

void del_duplicate_values() {
    struct node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while(ptr1 != NULL && ptr1 -> next != NULL) {
        ptr2 = ptr1;
        while(ptr2 -> next != NULL) {
            if(ptr1 -> data == ptr2 -> next -> data) {
                dup = ptr2 -> next;
                if (dup -> next != NULL) {
                    dup -> next -> prev = ptr2;
                }
                ptr2 -> next = dup -> next;
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