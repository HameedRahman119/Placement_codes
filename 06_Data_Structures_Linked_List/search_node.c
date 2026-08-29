#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *search(struct Node *head, int value)
{
    while (head != NULL)
    {
        if (head->data == value)
            return head;

        head = head->next;
    }

    return NULL;
}

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));
    struct Node *found;

    if (head == NULL || second == NULL || third == NULL)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    found = search(head, 20);

    if (found != NULL)
        printf("Found: %d\n", found->data);
    else
        printf("Not found\n");

    free(head);
    free(second);
    free(third);

    return 0;
}
