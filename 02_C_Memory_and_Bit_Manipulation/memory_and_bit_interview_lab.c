#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Placement interview lab:
 * - Dynamic memory ownership and resizing
 * - sizeof versus strlen
 * - Bit set/clear/toggle/test operations
 * - Bit-field updates without disturbing other bits
 * - Counting set bits efficiently
 */

static int *create_int_buffer(size_t count)
{
    if (count == 0)
        return NULL;

    return calloc(count, sizeof(int));
}

static int resize_int_buffer(int **buffer, size_t new_count)
{
    if (buffer == NULL || new_count == 0)
        return 0;

    int *tmp = realloc(*buffer, new_count * sizeof(**buffer));
    if (tmp == NULL)
        return 0;

    *buffer = tmp;
    return 1;
}

static void set_bit(uint32_t *value, unsigned int position)
{
    if (value == NULL || position >= 32)
        return;

    *value |= (UINT32_C(1) << position);
}

static void clear_bit(uint32_t *value, unsigned int position)
{
    if (value == NULL || position >= 32)
        return;

    *value &= ~(UINT32_C(1) << position);
}

static void toggle_bit(uint32_t *value, unsigned int position)
{
    if (value == NULL || position >= 32)
        return;

    *value ^= (UINT32_C(1) << position);
}

static int test_bit(uint32_t value, unsigned int position)
{
    if (position >= 32)
        return 0;

    return (value & (UINT32_C(1) << position)) != 0;
}

static uint32_t update_field(uint32_t value,
                             unsigned int shift,
                             unsigned int width,
                             uint32_t field_value)
{
    if (width == 0 || width > 32 || shift >= 32 || width > 32 - shift)
        return value;

    uint32_t mask = (UINT32_C(1) << width) - 1U;
    mask <<= shift;

    value &= ~mask;
    value |= (field_value << shift) & mask;
    return value;
}

static unsigned int count_set_bits(uint32_t value)
{
    unsigned int count = 0;

    while (value != 0) {
        value &= value - 1U;
        ++count;
    }

    return count;
}

static void print_bits(uint32_t value)
{
    for (int bit = 31; bit >= 0; --bit)
        putchar(test_bit(value, (unsigned int)bit) ? '1' : '0');
    putchar('\n');
}

int main(void)
{
    int *scores = create_int_buffer(3);
    if (scores == NULL) {
        fprintf(stderr, "initial allocation failed\n");
        return EXIT_FAILURE;
    }

    scores[0] = 80;
    scores[1] = 72;
    scores[2] = 91;

    if (!resize_int_buffer(&scores, 5)) {
        fprintf(stderr, "resize failed\n");
        free(scores);
        return EXIT_FAILURE;
    }

    scores[3] = 88;
    scores[4] = 95;

    printf("Dynamic buffer: ");
    for (size_t i = 0; i < 5; ++i)
        printf("%d%s", scores[i], i == 4 ? "\n" : " ");

    const char text[] = "firmware";
    printf("sizeof(text) = %zu, strlen(text) = %zu\n",
           sizeof(text), strlen(text));

    uint32_t status = 0;

    set_bit(&status, 0);       /* device enabled */
    set_bit(&status, 4);       /* error flag */
    toggle_bit(&status, 4);    /* clear error by toggling */
    clear_bit(&status, 0);     /* device disabled */

    /* Store a 3-bit mode value in bits 8..10. */
    status = update_field(status, 8, 3, 5);

    printf("Status bits: ");
    print_bits(status);
    printf("Mode = %u\n", (status >> 8) & 0x7U);
    printf("Set-bit count = %u\n", count_set_bits(status));

    free(scores);
    scores = NULL;

    return EXIT_SUCCESS;
}
