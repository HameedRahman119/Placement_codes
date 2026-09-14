#include <stdio.h>

int find_two_sum(const int arr[], int n, int target, int *first, int *second)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == target)
            {
                *first = i;
                *second = j;
                return 1;
            }
        }
    }

    return 0;
}

int main(void)
{
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int first;
    int second;

    if (find_two_sum(arr, n, target, &first, &second))
    {
        printf("Pair found at indexes %d and %d\n", first, second);
        printf("Values: %d + %d = %d\n", arr[first], arr[second], target);
    }
    else
    {
        printf("No pair found\n");
    }

    return 0;
}
