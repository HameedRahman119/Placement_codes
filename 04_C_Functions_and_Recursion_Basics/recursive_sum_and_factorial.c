#include <stdio.h>

int sum_to_n(int n)
{
    if (n == 0)
        return 0;

    return n + sum_to_n(n - 1);
}

int factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

int main(void)
{
    int n;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Please enter 0 or a positive number.\n");
        return 1;
    }

    printf("Sum from 1 to %d = %d\n", n, sum_to_n(n));
    printf("Factorial of %d = %d\n", n, factorial(n));

    return 0;
}
