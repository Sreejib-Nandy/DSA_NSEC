#include <stdio.h>

#define MAX 10

int stack[MAX], top = -1;

void push(int val) {
    if(top == MAX - 1) {
        printf("Overflow\n");
    } else {
        stack[++top] = val;
    }
    printf("Value pushed successfully\n");
}

void pop() {
    if(top == -1) {
        printf("Underflow\n");
    } else {
        printf("Popped element is : %d\n", stack[top]);
        top--;
    }
}

void peep() {
    if(top == -1) {
        printf("Underflow\n");
    } else {
    printf("Elements in the stack are : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
 }
}

void peek() {
    if(top == -1) {
        printf("Underflow\n");
    } else {
    printf("The top element is : %d\n", stack[top]);
    }
}

int main() {
    int choice,val;

    while(1) {
        printf("--------Menu--------\n");
        printf("1. Push value\n");
        printf("2. Pop value\n");
        printf("3. Peep\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            peek();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Input!");
        }
    }
}