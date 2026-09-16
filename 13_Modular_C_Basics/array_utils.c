#include "array_utils.h"

int array_sum(const int values[], size_t size)
{
    int sum = 0;

    for (size_t i = 0; i < size; ++i)
        sum += values[i];

    return sum;
}

int array_min(const int values[], size_t size, int *result)
{
    if (size == 0 || result == NULL)
        return 0;

    *result = values[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (values[i] < *result)
            *result = values[i];
    }

    return 1;
}

int array_max(const int values[], size_t size, int *result)
{
    if (size == 0 || result == NULL)
        return 0;

    *result = values[0];

    for (size_t i = 1; i < size; ++i)
    {
        if (values[i] > *result)
            *result = values[i];
    }

    return 1;
}
