#include <stdio.h>

int findSecondLargest(int arr[], int n, int *second)
{
    int largest = arr[0];
    int foundSecond = 0;
    int i;

    for(i = 1; i < n; i++)
    {
        if(arr[i] > largest)
        {
            if(largest != arr[i])
            {
                *second = largest;
                foundSecond = 1;
            }
            largest = arr[i];
        }
        else if(arr[i] < largest)
        {
            if(!foundSecond || arr[i] > *second)
            {
                *second = arr[i];
                foundSecond = 1;
            }
        }
    }

    return foundSecond;
}

int main()
{
    int arr[] = {10, 5, 8, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int second;

    if(findSecondLargest(arr, n, &second))
        printf("Second largest = %d\n", second);
    else
        printf("No distinct second largest value\n");

    return 0;
}
