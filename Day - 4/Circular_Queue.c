#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX],front = -1,rear = -1;
void insert() {
    int val;
    printf("Enter the element to push into Queue : ");
    scanf("%d", &val);
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow Condition.\n");
    } else {
        if(front == -1) {
            front = 0;
            rear = 0;
        } else {
            if(rear == MAX - 1) {
                rear = 0;
            } else {
            rear++;
            }
        }
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
            if(front == MAX - 1) {
                front = 0;
            }
            front++;
        }
    }
}

void display() {
    int i;
    if(front == -1) {
        printf("Underflow Condition.\n");
    }
    printf("The elements in the Queue : ");
    if(front <= rear) {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }  
    } else {
        for (i = front; i <= MAX - 1; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
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