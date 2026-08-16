#include <stdio.h>
#include <stdlib.h>

/*
 * Placement practice: singly linked list operations.
 * Focus: pointer manipulation, edge cases, and O(n) traversal.
 */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *create_node(int data)
{
    Node *node = malloc(sizeof(*node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    return node;
}

static int append(Node **head, int data)
{
    Node *new_node = create_node(data);

    if (new_node == NULL)
        return 0;

    if (*head == NULL) {
        *head = new_node;
        return 1;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
    return 1;
}

static void reverse(Node **head)
{
    Node *previous = NULL;
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

static int find_kth_from_end(const Node *head, size_t k, int *result)
{
    const Node *fast = head;
    const Node *slow = head;

    if (k == 0 || result == NULL)
        return 0;

    for (size_t i = 0; i < k; ++i) {
        if (fast == NULL)
            return 0;
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    *result = slow->data;
    return 1;
}

static void print_list(const Node *head)
{
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf(" -> NULL\n");
}

static void free_list(Node **head)
{
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main(void)
{
    Node *head = NULL;
    int kth_value;

    const int values[] = {10, 20, 30, 40, 50};
    const size_t count = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < count; ++i) {
        if (!append(&head, values[i])) {
            fprintf(stderr, "Memory allocation failed\n");
            free_list(&head);
            return EXIT_FAILURE;
        }
    }

    printf("Original list: ");
    print_list(head);

    if (find_kth_from_end(head, 3, &kth_value))
        printf("3rd node from end: %d\n", kth_value);

    reverse(&head);
    printf("Reversed list: ");
    print_list(head);

    free_list(&head);
    return EXIT_SUCCESS;
}
