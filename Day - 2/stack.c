#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int top = -1;
int arr[MAX];
int i;

void push() {
    int val;
    if( top == MAX - 1) {
        printf("Overflow condition");
    } else {
        top += 1;
        printf("Enter the value : ");
        scanf("%d", &val);
        arr[top] = val;
    }
}
void pop() {
    if( top ==  - 1) {
        printf("Underflow condition");
    } else {
        printf("The deleted element is: %d\n", arr[top]);
        top -= 1;
    }
}
void peep() {
    if( top == - 1) {
        printf("Underflow condition");
    } else {
        printf("The elements in the stack is : ");
        for ( i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
void peek() {
    if( top == - 1) {
        printf("Underflow condition");
    } else {
        printf("The top element in the stack is : ");
        printf("%d\n", arr[top]);
    } 
}
int main() {
    int choice;
    while(1) {
        printf("\n------Menu------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP (display content of stack)\n");
        printf("4. PEEK (showing the top element)\n");
        printf("5. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
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
            exit(0);
        default:
            printf("Wrong Input");
        }
    }
    return 0;
}
