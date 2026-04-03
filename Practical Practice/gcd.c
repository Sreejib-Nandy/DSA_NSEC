#include <stdio.h>

int gcd_iterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd_recursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        if (a >= b)
        {
            return gcd_recursive(b, a % b);
        }
        else
        {
            return gcd_recursive(a, b % a);
        }
    }
}

int main()
{
    int choice, num1, num2, gcd1, gcd2;

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
            printf("Enter the first number : ");
            scanf("%d", &num1);
            printf("Enter the second number : ");
            scanf("%d", &num2);
            gcd1 = gcd_iterative(num1, num2);
            printf("The GCD of %d and %d is : %d\n", num1, num2, gcd1);
            break;
        case 2:
            printf("Enter the first number : ");
            scanf("%d", &num1);
            printf("Enter the second number : ");
            scanf("%d", &num2);
            gcd2 = gcd_recursive(num1, num2);
            printf("The GCD of %d and %d is : %d\n", num1, num2, gcd2);
            break;
        case 3:
            return 0;
        default:
            printf("Invalid Input!\n");
        }
    }
}