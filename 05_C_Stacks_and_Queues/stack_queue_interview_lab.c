#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct {
    int items[CAPACITY];
    size_t top;
} Stack;

typedef struct {
    int items[CAPACITY];
    size_t front;
    size_t rear;
    size_t count;
} Queue;

static void stack_init(Stack *stack)
{
    stack->top = 0;
}

static bool stack_push(Stack *stack, int value)
{
    if (stack->top == CAPACITY)
        return false;

    stack->items[stack->top++] = value;
    return true;
}

static bool stack_pop(Stack *stack, int *value)
{
    if (stack->top == 0 || value == NULL)
        return false;

    *value = stack->items[--stack->top];
    return true;
}

static bool stack_peek(const Stack *stack, int *value)
{
    if (stack->top == 0 || value == NULL)
        return false;

    *value = stack->items[stack->top - 1];
    return true;
}

static void stack_print(const Stack *stack)
{
    printf("Stack (top -> bottom):");

    for (size_t i = stack->top; i > 0; --i)
        printf(" %d", stack->items[i - 1]);

    printf("\n");
}

static void queue_init(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
}

static bool queue_enqueue(Queue *queue, int value)
{
    if (queue->count == CAPACITY)
        return false;

    queue->items[queue->rear] = value;
    queue->rear = (queue->rear + 1) % CAPACITY;
    ++queue->count;
    return true;
}

static bool queue_dequeue(Queue *queue, int *value)
{
    if (queue->count == 0 || value == NULL)
        return false;

    *value = queue->items[queue->front];
    queue->front = (queue->front + 1) % CAPACITY;
    --queue->count;
    return true;
}

static bool queue_peek(const Queue *queue, int *value)
{
    if (queue->count == 0 || value == NULL)
        return false;

    *value = queue->items[queue->front];
    return true;
}

static void queue_print(const Queue *queue)
{
    printf("Queue (front -> rear):");

    for (size_t i = 0; i < queue->count; ++i) {
        size_t index = (queue->front + i) % CAPACITY;
        printf(" %d", queue->items[index]);
    }

    printf("\n");
}

int main(void)
{
    Stack stack;
    Queue queue;
    int value;

    stack_init(&stack);
    queue_init(&queue);

    puts("--- Stack ---");
    for (int i = 10; i <= 30; i += 10)
        stack_push(&stack, i);

    stack_print(&stack);

    if (stack_peek(&stack, &value))
        printf("Peek: %d\n", value);

    if (stack_pop(&stack, &value))
        printf("Pop: %d\n", value);

    stack_print(&stack);

    puts("\n--- Circular Queue ---");
    for (int i = 1; i <= 5; ++i)
        queue_enqueue(&queue, i * 10);

    queue_print(&queue);

    if (queue_dequeue(&queue, &value))
        printf("Dequeue: %d\n", value);

    if (queue_dequeue(&queue, &value))
        printf("Dequeue: %d\n", value);

    queue_enqueue(&queue, 60);
    queue_enqueue(&queue, 70);
    queue_print(&queue);

    if (queue_peek(&queue, &value))
        printf("Front: %d\n", value);

    return EXIT_SUCCESS;
}
