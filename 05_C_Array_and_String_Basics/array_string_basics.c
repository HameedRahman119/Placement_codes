#include <stdio.h>
#include <string.h>

static int find_largest(const int values[], int size)
{
    int largest = values[0];

    for (int i = 1; i < size; ++i) {
        if (values[i] > largest)
            largest = values[i];
    }

    return largest;
}

static void reverse_array(int values[], int size)
{
    for (int left = 0, right = size - 1; left < right; ++left, --right) {
        int temp = values[left];
        values[left] = values[right];
        values[right] = temp;
    }
}

static int count_vowels(const char text[])
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' ||
            text[i] == 'o' || text[i] == 'u')
            ++count;
    }

    return count;
}

int main(void)
{
    int values[] = {12, 5, 19, 8, 3};
    int size = sizeof(values) / sizeof(values[0]);
    char word[] = "firmware";

    printf("Largest value: %d\n", find_largest(values, size));
    printf("String: %s\n", word);
    printf("String length: %zu\n", strlen(word));
    printf("Vowel count: %d\n", count_vowels(word));

    reverse_array(values, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; ++i)
        printf("%d ", values[i]);
    printf("\n");

    return 0;
}
