#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Before deletion: ");
    printList(head);

    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("After deletion: ");
    printList(head);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
