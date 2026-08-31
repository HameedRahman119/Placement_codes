#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    rear++;
    queue[rear] = value;
}

void dequeue(void)
{
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Removed: %d\n", queue[front]);
    front++;
}

void display(void)
{
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue: ");
    display();

    dequeue();

    printf("After dequeue: ");
    display();

    return 0;
}
