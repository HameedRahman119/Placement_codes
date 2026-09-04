#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    display(arr, n);

    bubbleSort(arr, n);

    printf("\nAfter sorting: ");
    display(arr, n);

    return 0;
}
