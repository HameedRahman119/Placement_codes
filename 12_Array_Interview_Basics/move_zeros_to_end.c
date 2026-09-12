#include <stdio.h>

void move_zeros_to_end(int arr[], int n)
{
    int next = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[next] = arr[i];
            next++;
        }
    }

    while (next < n)
    {
        arr[next] = 0;
        next++;
    }
}

void display(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int arr[] = {0, 5, 0, 3, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    display(arr, n);

    move_zeros_to_end(arr, n);

    printf("\nAfter:  ");
    display(arr, n);
    printf("\n");

    return 0;
}
