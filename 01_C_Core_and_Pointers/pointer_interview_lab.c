#include <stdio.h>

static void change_value(int *number)
{
    *number = *number + 10;
}

static void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

static void print_array(const int *array, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int number = 20;
    int first = 10;
    int second = 30;
    int values[] = {5, 10, 15, 20};

    printf("Before pointer change: %d\n", number);
    change_value(&number);
    printf("After pointer change:  %d\n", number);

    printf("Before swap: first=%d second=%d\n", first, second);
    swap(&first, &second);
    printf("After swap:  first=%d second=%d\n", first, second);

    printf("Array using pointer access: ");
    for (int i = 0; i < 4; ++i)
        printf("%d ", *(values + i));
    printf("\n");

    printf("Array using function: ");
    print_array(values, 4);

    return 0;
}
