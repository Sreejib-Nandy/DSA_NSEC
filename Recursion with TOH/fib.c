#include <stdio.h>

void fib_iterative(int term) {
    int x = 0,y = 1,next; 
    printf("The fibonacci Series upto %d is : ", term);
    for (int i = 1; i <= term; i++)
    {
        printf("%d ", x);
        next = x + y;
        x = y;
        y = next;
    }
}

int fib_recursive(int term) {
    if(term == 0 || term == 1) {
        return term;
    } else {
        return fib_recursive(term - 1) + fib_recursive(term - 2);
    }
}


int main() {
    int num,choice;
    printf("\n------Menu------\n");
    printf("1. Iteration\n");
    printf("2. Recursion\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    printf("Enter the Term : ");
    scanf("%d", &num);
    switch (choice)
    {
    case 1:
        fib_iterative(num);
        break;
    case 2:
        printf("The fibonacci Series upto %d is : ", num);
        for (int i = 0; i < num; i++)
        {
            printf("%d ", fib_recursive(i));
        }
        break;
    default:
        printf("Wrong Input");
    }
    return 0;
}