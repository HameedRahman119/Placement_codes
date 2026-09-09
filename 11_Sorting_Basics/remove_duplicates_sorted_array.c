#include <stdio.h>

int remove_duplicates(int arr[], int n)
{
    int i;
    int j = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;
}

int main(void)
{
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_n;
    int i;

    new_n = remove_duplicates(arr, n);

    printf("Array after removing duplicates: ");

    for (i = 0; i < new_n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
