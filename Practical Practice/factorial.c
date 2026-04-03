#include <stdio.h>

int iterative_factorial(int val) {
    int fact = 1;
    for (int i = 1; i <= val; i++)
    {
        fact *= i;
    }
    return fact;
}

int tail_recursion_factorial(int val, int accumulator) {
    if(val == 0) {
        return accumulator;
    } else {
        return tail_recursion_factorial(val - 1, val * accumulator);
    }
}

int nontail_recursion_factorial(int val) {
    if(val == 0) {
        return 1;
    } else {
        return val * nontail_recursion_factorial(val - 1);
    }
}

int main()
{
    int choice, val, fact_1, fact_2, fact_3;

    while (1)
    {
        printf("--------Menu--------\n");
        printf("1. Iteration Method\n");
        printf("2. Tail Recursion Method\n");
        printf("3. Non Tail Recursion Method\n");
        printf("4. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &val);
            fact_1 = iterative_factorial(val);
            printf("The factorial of %d is : %d\n", val, fact_1);
            break;
        case 2:
            printf("Enter the value : ");
            scanf("%d", &val);
            fact_2 = tail_recursion_factorial(val, 1);
            printf("The factorial of %d is : %d\n", val, fact_2);
            break;
        case 3:
            printf("Enter the value : ");
            scanf("%d", &val);
            fact_3 = nontail_recursion_factorial(val);
            printf("The factorial of %d is : %d\n", val, fact_3);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Input!\n");
        }
    }
}