#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

void insertbeginning(int val)
{
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    n++;
}

void insertlast(int val)
{
    arr[n] = val;
    n++;
}

void insertposition(int pos, int val)
{
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
}

void delete(int pos)
{
    if (pos < 1 || pos > n + 1)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

void search(int val)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            printf("Value was found at %d position\n", i + 1);
            return;
        }
    }
    printf("Value was not found!\n");
}

void delduplicates()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
}

void display()
{
    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findmaximum()
{
    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("The maximum value is : %d\n", max);
}

void findminimum()
{
    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The minimum value is : %d\n", min);
}

int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("--------Menu--------\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Search\n");
        printf("6. Delete Duplicates\n");
        printf("7. Display\n");
        printf("8. Find Maximum\n");
        printf("9. Find Minimum\n");
        printf("10. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value you want to insert : ");
            scanf("%d", &val);
            insertbeginning(val);
            break;
        case 2:
            printf("Enter the value you want to insert : ");
            scanf("%d", &val);
            insertlast(val);
            break;
        case 3:
            printf("Enter the position : ");
            scanf("%d", &pos);
            printf("Enter the value you want to insert : ");
            scanf("%d", &val);
            insertposition(pos, val);
            break;
        case 4:
            printf("Enter the position : ");
            scanf("%d", &pos);
            delete(pos);
            break;
        case 5:
            printf("Enter the value you want to search : ");
            scanf("%d", &val);
            search(val);
            break;
        case 6:
            delduplicates();
            break;
        case 7:
            display();
            break;
        case 8:
            findmaximum();
            break;
        case 9:
            findminimum();
            break;
        case 10:
            return 0;
        default:
            printf("Wrong Input!\n");
        }
    }
}