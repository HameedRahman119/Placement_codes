#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return;
    }

    top++;
    stack[top] = value;
}

void pop(void)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Popped: %d\n", stack[top]);
    top--;
}

void display(void)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("Stack: ");
    display();

    pop();

    printf("After pop: ");
    display();

    return 0;
}
