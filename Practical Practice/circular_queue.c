#include <stdio.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int val;
    if(front == (rear + 1) % MAX) {
        printf("Overflow\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        printf("Enter the value : ");
        scanf("%d", &val);
        queue[rear] = val;
    }
}

void dequeue() {
    if(front == -1) {
        printf("Underflow\n");
    } else {
        printf("The deleted element is : %d\n", queue[front]);
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if(front == -1) {
        printf("Underflow\n");
    } else {
        printf("The elements in the queue are : ");
        if(front <= rear) {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            } 
        } else {
            for (int i = front; i < MAX; i++)
            {
                printf("%d ", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("--------Menu--------\n");
        printf("1. Insert Into\n");
        printf("2. Delete From\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Input !\n");
        }
    }
}