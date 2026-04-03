#include <stdio.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int val;
    printf("Enter the value you want to insert : ");
    scanf("%d", &val);
    if(rear == MAX - 1) {
        printf("Overflow\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        queue[++rear] = val;
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
            queue[front++] = '#';
        }
    }
}

void display() {
    int i;
    char j;
    if(front == -1) {
        printf("Underflow\n");
    } else {
        printf("The elements in the queue are : ");
        for (j = 0; j < front; j++)
        {
            printf("%c ", queue[j]);
        }

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
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