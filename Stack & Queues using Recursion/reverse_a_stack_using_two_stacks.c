#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack_1[MAX], stack_2[MAX];
int top_1 = -1, top_2 = -1;

void push(int val) {
    if(top_1 == MAX - 1) {
        printf("Overflow Condition");
    } else {
        stack_1[++top_1] = val;
    }
}

void pop_and_push() {
    if(top_1 == -1) {
        printf("Underflow Condition");
    } else {
        int count = top_1;
        while(count >= 0) {
        int ele = stack_1[top_1--];
        stack_2[++top_2] = ele;
        count--;
        }
    }
}

void peep() {
        for (int i = 0; i <= top_2; i++)
        {
          printf("%d ", stack_2[i]);
        }
}

void reverse_the_stack() {
    int index,val;
    printf("Enter the index : ");
    scanf("%d", &index);
    for (int i = 0; i < index; i++)
    {
        printf("Enter the value %d : ", i + 1);
        scanf("%d", &val);
        push(val);
    }
    pop_and_push();
    peep();
}


int main() {
    reverse_the_stack();
    return 0;
}