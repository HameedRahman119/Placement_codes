#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stddef.h>

int array_sum(const int values[], size_t size);
int array_min(const int values[], size_t size, int *result);
int array_max(const int values[], size_t size, int *result);

#endif
