#include <stdio.h>

/* Method 1: My original approach */
void my_way(void)
{
    char str[20];
    int freq[125] = {0};
    int count = 0, max = 0, end = 0;

    scanf("%19s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (freq[(unsigned char)str[i]] == 0)
        {
            freq[(unsigned char)str[i]] = i + 1;
            count++;
        }
        else
        {
            i = freq[(unsigned char)str[i]] - 1;

            for (int j = 0; str[j] != '\0'; j++)
                freq[(unsigned char)str[j]] = 0;

            count = 0;
        }

        if (max < count)
        {
            max = count;
            end = i;
        }
    }

    printf("My way: ");
    for (int i = end - max + 1; i <= end; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", max);
}

/* Method 2: Optimized sliding window */
void sliding_window(void)
{
    char str[100];
    int last[123] = {0};
    int left = 0, max = 0, start = 0, end = 0;

    scanf("%99s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (last[(unsigned char)str[i]] > left)
            left = last[(unsigned char)str[i]];

        last[(unsigned char)str[i]] = i + 1;

        int len = i - left + 1;

        if (len > max)
        {
            max = len;
            start = left;
            end = i;
        }
    }

    printf("Sliding window: ");
    for (int i = start; i <= end; i++)
        printf("%c", str[i]);

    printf("\nLength: %d\n", max);
}

int main(void)
{
    int choice;

    printf("1. My way\n2. Sliding window\nChoose method: ");
    scanf("%d", &choice);

    if (choice == 1)
        my_way();
    else if (choice == 2)
        sliding_window();
    else
        printf("Invalid choice\n");

    return 0;
}
