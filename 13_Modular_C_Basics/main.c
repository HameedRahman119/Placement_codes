#include <stdio.h>
#include "array_utils.h"

int main(void)
{
    const int values[] = {12, 5, 19, 8, 3};
    const size_t size = sizeof(values) / sizeof(values[0]);
    int minimum;
    int maximum;

    printf("Sum = %d\n", array_sum(values, size));

    if (array_min(values, size, &minimum))
        printf("Minimum = %d\n", minimum);

    if (array_max(values, size, &maximum))
        printf("Maximum = %d\n", maximum);

    return 0;
}
