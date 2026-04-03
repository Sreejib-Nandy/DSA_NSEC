#include <stdio.h>

int count = 0;
void tower_of_hanoi(int n,char beg, char aux, char end) {
    if( n == 1) {
        count++;
        printf("Move disk 1 from %c to %c\n", beg, end);
        return;
    } else {
        tower_of_hanoi(n - 1, beg, end, aux);
        count++;
        printf("Move %d disk from %c to %c\n", n, beg,end);
        tower_of_hanoi(n - 1, aux,beg,end);
    }
}

int main() {
    int disks;
    printf("Enter the no. of disks : ");
    scanf("%d", &disks);
    printf("The Sequence of moves to solve tower of hanoi with %d disks is  : \n", disks);
    tower_of_hanoi(disks, 'A', 'B', 'C');
    printf("The Total number of moves : %d", count);
    return 0;
}