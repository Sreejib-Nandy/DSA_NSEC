#include <stdio.h>



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