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
}

int main(void)
{
    struct Node *head = NULL;
    struct Node *newNode;
    struct Node *temp;
    int value;

    printf("Enter 3 values: ");

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &value);

        newNode = malloc(sizeof(struct Node));
        if (newNode == NULL)
            return 1;

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Linked list: ");
    printList(head);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
