#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start;

void create(int n) {
    int val;
    struct node *temp, *newNode;
    int i, item;
    if(n <= 0) {
        printf("Negative index or zero is not allowed!");
        return;
    }
    start = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d", &val);
    start -> data = val;
    start -> next = start;
    temp = start;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value : ");
        scanf("%d", &val);
        newNode -> data = val;
        newNode -> next = start;
        temp -> next = newNode;
        temp = newNode;
    }
}

void insert_beg() {
    int item;
    struct node *temp, *p = start;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    while (p -> next != start)
    {
       p = p -> next;
    }
    temp -> next = start;
    p -> next = temp;
    start = temp; 
}

void insert_end() {
    int item;
    struct node *temp, *p = start;
    printf("Enter the value : ");
    scanf("%d", &item);
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    if (start == NULL) {
        start = temp;
        temp -> next = start;
        return;
    }
    while (p -> next != start)
    {
        p = p -> next;
    }
    p -> next = temp; 
    temp -> next = start;
}

void insert_loc(int location) {
    struct node* p = start, *temp;
    int item;
    if (location <= 0) {
        printf("Invalid location!\n");
        return;
    }
    if (location == 1) {
        insert_beg();
        return;
    }
    if(start == NULL) {
        if (location != 1) {
            printf("List is empty. You can only insert at location 1.\n");
            return;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value: ");
        scanf("%d", &item);
        temp->data = item;
        temp->next = temp; 
        start = temp;
        return;
    }
    for (int i = 1; i < location - 1 && p -> next != start; i++)
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
    temp -> data = item;
    temp -> next = p -> next;
    p -> next = temp;  
}
 
void insert_val(int value) {
    struct node* p = start, *temp;
    int item;
    printf("Enter the new value : ");
    scanf("%d", &item);
    if (start == NULL) {
        printf("List is empty! Cannot insert after value %d.\n", value);
        return;
    }
    while (p -> next != start && p -> data != value) 
    {
        p = p -> next;
    }
    if (p -> data != value) {
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
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    do {
        if (p->data == value) {
            printf("%d found at position %d in the linked list!\n", value, count);
            found = 1;
        }
        p = p->next;
        count++;
    } while (p != start);
    if (!found) {
        printf("%d not found in the linked list!\n", value);
    }
}

void display() {
    struct node* p = start;
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Elements in the linkedlist are : ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);
}

void delete_beg() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (start->next == start) {
        printf("Deleted node: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    struct node *p = start, *q = start;
    while (p->next != start)  
        p = p->next;

    printf("Deleted node: %d\n", q->data);
    p->next = q->next;  
    start = q->next;     
    free(q);  
}

void delete_end() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (start -> next == start) {
        free(start);
        start = NULL;
        return;
    }
    struct node* p = start, *old;
    while (p -> next != start)
    {
       old = p;
       p = p -> next;
    }
    old -> next = start;
    free(p);  
}

void count_nodes() {
    struct node* p = start;
    int count = 0;
    do {
        count++;
        p = p->next;
    } while (p != start);
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
    int i;
    for (i = 1; i < location && p -> next != start; i++)
    {
        old = p;
        p = p -> next;
    }
    if (i != location) {
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
    if (start->data == value) {
        struct node *last = start;
        while (last->next != start) {
            last = last->next;
        }
        last->next = start->next;
        struct node *temp = start;
        start = start->next;
        free(temp);
        return;
    }
    do {
        old = p;
        p = p->next;
        if (p->data == value) {
            old->next = p->next;
            free(p);
            return;
        }
    } while (p != start);
    
    printf("%d not found in the linked list!\n", value);
}

void reverse_linked_list() {
    struct node *prev = NULL, *curr = start, *nextNode = NULL;
    struct node *last = start;

    while (last->next != start) {
        last = last->next;
    }

    do {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != start);

    start->next = prev;
    start = prev;
}

void del_duplicate_values() {
    struct node *current = start, *index, *temp;
    do {
        index = current;
        while (index->next != start) {
            if (index->next->data == current->data) {
                temp = index->next;
                index->next = temp->next;
                free(temp);
            } else {
                index = index->next;
            }
        }
        current = current->next;
    } while (current->next != start);
}

void sort_linked_list() {
    struct node *p, *q;
    int swapped, temp;
    if (start == NULL) {
        return;
    }
    do {
        swapped = 0;
        p = start;
        do {
            q = p->next;
            if (q != start && p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                swapped = 1;
            }
            p = p->next;
        } while (p->next != start);
    } while (swapped);
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