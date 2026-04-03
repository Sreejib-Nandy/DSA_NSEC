#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX],top = -1;

void push(int count) {
    int val;
    if(top == MAX - 1) {
        printf("Overflow Condition");
    } else {
        if (count == 0)
        {
           return;
        } else {
            printf("Enter the value : ");
            scanf("%d", &val);
            top++;
            stack[top] = val;
            push(--count);
        }    
    }
}

void pop(int count) {
    if(top == -1) {
        printf("Underflow Condition");
    } else {
        if (count == 0)
        {
           return;
        } else {
            printf("The Deleted Element is : %d\n", stack[top--]);
            pop(--count);
        }    
    }
}

void peep() {
    int i;
    if(top == -1) {
        printf("Underflow Condition");
    } else {
        printf("The elements in the stack is : ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        } 
    }
}

int main() {
    int choice,push_count,pop_count;
    while (1)
    {
       printf("\n------Menu------\n");
       printf("1. Push()\n");
       printf("2. Pop()\n");
       printf("3. Peep()\n");
       printf("4. Exit\n");
       printf("Enter your choice : ");
       scanf("%d", &choice);
       switch (choice)
       {
       case 1:
        printf("Enter the number of elements you want to push : ");
        scanf("%d", &push_count);
        push(push_count);
        break;
       case 2:
        printf("Enter the number of elements you want to pop : ");
        scanf("%d", &pop_count);
        pop(pop_count);
        break;
       case 3:
        peep();
        break;
       case 4:
        exit(0); 
       default:
        printf("Wrong Input!");
       }
    }
    return 0;
}