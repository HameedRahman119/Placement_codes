#include <stdio.h>

/*
 * Binary search works on a sorted array.
 * Each step removes half of the remaining search range.
 * Time: O(log n)
 * Extra space: O(1)
 */

int binary_search(const int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target)
            return middle;

        if (arr[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int main(void)
{
    int values[] = {3, 7, 12, 18, 25, 31, 40};
    int size = sizeof(values) / sizeof(values[0]);
    int target = 25;

    int index = binary_search(values, size, target);

    if (index != -1)
        printf("%d found at index %d\n", target, index);
    else
        printf("%d not found\n", target);

    return 0;
}
