#include <stdio.h>
#include <stdlib.h>

static void set_bit(unsigned int *value, int position)
{
    *value = *value | (1u << position);
}

static void clear_bit(unsigned int *value, int position)
{
    *value = *value & ~(1u << position);
}

static int is_bit_set(unsigned int value, int position)
{
    return (value & (1u << position)) != 0;
}

int main(void)
{
    int *marks = malloc(3 * sizeof(int));

    if (marks == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    marks[0] = 70;
    marks[1] = 80;
    marks[2] = 90;

    printf("Marks: %d %d %d\n", marks[0], marks[1], marks[2]);

    free(marks);
    marks = NULL;

    unsigned int status = 0;

    set_bit(&status, 2);
    printf("After setting bit 2: %u\n", status);
    printf("Is bit 2 set? %s\n", is_bit_set(status, 2) ? "yes" : "no");

    clear_bit(&status, 2);
    printf("After clearing bit 2: %u\n", status);

    return 0;
}
