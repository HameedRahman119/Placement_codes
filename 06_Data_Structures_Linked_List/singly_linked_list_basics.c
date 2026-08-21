#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_list(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        Node *next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main(void)
{
    Node *head = create_node(10);
    Node *second = create_node(20);
    Node *third = create_node(30);

    if (head == NULL || second == NULL || third == NULL)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->next = second;
    second->next = third;

    print_list(head);
    free_list(head);

    return 0;
}
