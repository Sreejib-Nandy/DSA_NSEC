#include <stdio.h>

void fib_iterative(int term) {
    int x = 0, y = 1, next;
    printf("The Fibonacci Series upto %d is : ", term);
    for (int i = 0; i < term; i++)
    {
        printf("%d ", x);
        next = x + y;
        x = y;
        y = next;
    }  
    printf("\n");
}

int fib_recursive(int term) {
    if(term == 0 || term == 1) {
        return term;
    } else {
        return fib_recursive(term - 1) + fib_recursive(term - 2);
    }
}

int main()
{
    int choice, term;

    while (1)
    {
        printf("--------Menu--------\n");
        printf("1. Iteration Method\n");
        printf("2. Recursion Method\n");
        printf("3. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the term upto which you want to print the fibonacci series : ");
            scanf("%d", &term);
            fib_iterative(term);
            break;
        case 2:
            printf("Enter the term upto which you want to print the fibonacci series : ");
            scanf("%d", &term);
            printf("The Fibonacci Series upto %d is : ", term);
            for (int i = 0; i < term; i++)
            {
                printf("%d ", fib_recursive(i));
            }
            printf("\n");
            break;
        case 3:
            return 0;
        default:
            printf("Invalid Input!");
        }
    }
}