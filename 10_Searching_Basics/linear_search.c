#include <stdio.h>

/*
 * Linear search checks each element from left to right.
 * Time: O(n)
 * Extra space: O(1)
 */

int linear_search(const int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main(void)
{
    int values[] = {12, 7, 25, 9, 31};
    int size = sizeof(values) / sizeof(values[0]);
    int target = 25;

    int index = linear_search(values, size, target);

    if (index != -1)
        printf("%d found at index %d\n", target, index);
    else
        printf("%d not found\n", target);

    return 0;
}
