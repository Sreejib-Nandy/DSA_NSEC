#include <stdio.h>

int fact_iterative(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
  return fact;
}

int fact_tail(int n,int accumulator) {
    if( n == 0) {
        return accumulator;
    } else {
        return fact_tail(n-1, n * accumulator);
    }
}

int fact_non_tail(int n) {
    if (n == 0)
    {
        return 1;
    } else {
        return n * fact_non_tail(n - 1);
    }
}

int main() {
    int num,choice;
    printf("\n------Menu------\n");
    printf("1. Iteration\n");
    printf("2. Tail Recursion\n");
    printf("3. Nontail Recursion\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    printf("Enter the Number : ");
    scanf("%d", &num);
    int fact_1,fact_2,fact_3;
    switch (choice)
    {
    case 1:
        fact_1 = fact_iterative(num);
        printf("Factorial using iteration is : %d\n", fact_1);
        break;
    case 2:
        fact_2 = fact_tail(num,1);
        printf("Factorial using Tail Recursion is : %d\n", fact_2);
        break;
    case 3:
        fact_3 = fact_non_tail(num);
        printf("Factorial using Non Tail Recursion is : %d\n", fact_3);
        break;
    default:
        printf("Wrong Input");
    }
    return 0;
}