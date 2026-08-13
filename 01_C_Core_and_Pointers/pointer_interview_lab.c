#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void reverse_array(int *arr, size_t count)
{
    if (arr == NULL || count < 2)
        return;

    int *left = arr;
    int *right = arr + count - 1;

    while (left < right) {
        swap(left, right);
        ++left;
        --right;
    }
}

static int find_max(const int *arr, size_t count)
{
    if (arr == NULL || count == 0)
        return 0;

    int max = arr[0];

    for (size_t i = 1; i < count; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

static int **allocate_matrix(size_t rows, size_t cols)
{
    int **matrix = calloc(rows, sizeof(*matrix));
    if (matrix == NULL)
        return NULL;

    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = calloc(cols, sizeof(*matrix[i]));
        if (matrix[i] == NULL) {
            while (i > 0)
                free(matrix[--i]);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

static void free_matrix(int **matrix, size_t rows)
{
    if (matrix == NULL)
        return;

    for (size_t i = 0; i < rows; ++i)
        free(matrix[i]);

    free(matrix);
}

int main(void)
{
    int values[] = {10, 4, 25, 7, 18};
    const size_t count = sizeof(values) / sizeof(values[0]);

    printf("Original max: %d\n", find_max(values, count));

    reverse_array(values, count);

    printf("Reversed: ");
    for (size_t i = 0; i < count; ++i)
        printf("%d%s", values[i], i + 1 == count ? "\n" : " ");

    int **matrix = allocate_matrix(2, 3);
    if (matrix == NULL) {
        fprintf(stderr, "matrix allocation failed\n");
        return EXIT_FAILURE;
    }

    matrix[0][0] = 10;
    matrix[0][1] = 20;
    matrix[0][2] = 30;
    matrix[1][0] = 40;
    matrix[1][1] = 50;
    matrix[1][2] = 60;

    printf("Matrix[1][2] = %d\n", *(*(matrix + 1) + 2));

    free_matrix(matrix, 2);
    return EXIT_SUCCESS;
}
