#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX],front = -1,rear = -1;
void insert() {
    int val;
    if(rear == MAX - 1) {
        printf("Overflow Condition.\n");
    } else {
        if(front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
    printf("Enter the element to push into Queue : ");
    scanf("%d", &val);
    queue[rear] = val;
    }
}

void delete() {
    if(front == -1) {
        printf("Underflow Condition.\n");
    } else {
        printf("The deleted element is : %d", queue[front]);
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            queue[front] = '#';
            front++;
        }
    }
}

void display() {
    int i;
    char j;
    if(front == -1) {
        printf("Underflow Condition.\n");
    } else {
        printf("The elements in the Queue : ");
        for (j = 0; j < front; j++)
        {
            printf("%c ", queue[j]);
        }
        for (i = front; i <= rear; i++)
        {   
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice;
    while(1) {
    printf("\n-----Menu-----\n");
    printf("1. Insert element\n");
    printf("2. Delete Element\n");
    printf("3. Display Element\n");
    printf("4. Exit the Queue\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        delete();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
    default:
        printf("Wrong Input.\n");
    }
    }
    return 0;
}