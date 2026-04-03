#include <stdio.h>

int gcd_iterative(int a,int b) {
    while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
    }
    return a;
}

int gcd_recursive(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        if(a >= b)
        return gcd_recursive(b, a % b);
        else {
        return gcd_recursive(a, b % a);
        }
    }
}

int main() {
    int num_1,num_2,choice;
    printf("\n------Menu------\n");
    printf("1. Iteration\n");
    printf("2. Recursion\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    printf("Enter the First Number : ");
    scanf("%d", &num_1);
    printf("Enter the Second Number : ");
    scanf("%d", &num_2);
    int gcd_1,gcd_2;
    switch (choice)
    {
    case 1:
        gcd_1 = gcd_iterative(num_1,num_2);
        printf("The Gcd of %d and %d is : %d", num_1, num_2, gcd_1);
        break;
    case 2:
        gcd_2 = gcd_recursive(num_1,num_2);
        printf("The Gcd of %d and %d is : %d", num_1, num_2, gcd_2);
        break;
    default:
        printf("Wrong Input");
    }
    return 0;
}