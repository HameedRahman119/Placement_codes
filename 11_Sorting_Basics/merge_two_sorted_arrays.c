#include <stdio.h>

void mergeArrays(int a[], int n1, int b[], int n2, int result[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            result[k] = a[i];
            i++;
        }
        else
        {
            result[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        result[k] = a[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        result[k] = b[j];
        j++;
        k++;
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
    int a[] = {1, 4, 7};
    int b[] = {2, 3, 8};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    int result[6];

    mergeArrays(a, n1, b, n2, result);

    printf("Merged array: ");
    display(result, n1 + n2);

    return 0;
}
