#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX],front = -1,rear = -1;

void nqueue(int count) {
    int val;
    if(rear == MAX - 1) {
        printf("Overflow Condition");
    }
    if (count == 0)
    {
        return;
    } else {
        if (front == -1)
        {
            front = rear = 0;
        } 
        else {
            rear++;
        }
        printf("Enter the value : ");
        scanf("%d", &val);
        queue[rear] = val;
        nqueue(--count);
     }    
}

void dqueue(int count) {
    if(front == -1) {
        printf("Underflow Condition");
    }
    if (count == 0)
    {
      return;
    } else {
        if (front == rear)
        {
            front = rear = -1;
        } 
        else {
        printf("The Deleted Element is : %d\n", queue[front++]);
    }
    dqueue(--count);
    }    
}

void display() {
    int i;
    if(front == -1) {
        printf("Underflow Condition");
    } else {
        printf("The elements in the queue is : ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        } 
    }
}

int main() {
    int choice,nqueue_count,dqueue_count;
    while (1)
    {
       printf("\n------Menu------\n");
       printf("1. Insert Element\n");
       printf("2. Delete Element\n");
       printf("3. Display Element\n");
       printf("4. Exit\n");
       printf("Enter your choice : ");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
        printf("Enter the number of elements you want to push : ");
        scanf("%d", &nqueue_count);
        nqueue(nqueue_count);
        break;
       case 2:
        printf("Enter the number of elements you want to pop : ");
        scanf("%d", &dqueue_count);
        dqueue(dqueue_count);
        break;
       case 3:
        display();
        break;
       case 4:
        exit(0); 
       default:
        printf("Wrong Input!");
       }
    }
    return 0;
}