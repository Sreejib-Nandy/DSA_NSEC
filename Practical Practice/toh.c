#include <stdio.h>

int count = 0;

void tower_of_hanoi(int disks, char beg, char aux, char end) {
    if(disks == 1) {
        count++;
        printf("Move disk 1 from %c to %c\n", beg, end);
        return;
    } else {
        tower_of_hanoi(disks - 1, beg, end, aux);
        count++;
        printf("Move disk %d from %c to %c\n", disks, beg, end);
        tower_of_hanoi(disks - 1, aux , beg, end);
    }
}

int main() {
    int disks;
    printf("Enter the number of disks : ");
    scanf("%d", &disks);
    printf("The sequence of moves to solve tower of hanoi using %d disks : \n", disks);
    tower_of_hanoi(disks, 'A', 'B', 'C');
    printf("\n");
    printf("The number of moves : %d\n", count);
    return 0;
}