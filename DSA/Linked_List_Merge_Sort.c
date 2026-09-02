#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

struct node* reverse()
{
    struct node* curr = head;
    struct node* prev = NULL;

    while(head != NULL)
    {
        head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }

    head = prev;
    return head;
}

void display()
{
    struct node* temp = head;

    printf("\n");

    while(temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

struct node* merge(struct node* left, struct node* right)
{
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    if(left->data <= right->data)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        return right;
    }
}

struct node* mergesort(struct node* head)
{
    struct node *slow = head;
    struct node *fast = head->next;
    struct node *mid = NULL;
    struct node *midnext = NULL;

    if(head == NULL || head->next == NULL)
        return head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    mid = slow;
    midnext = mid->next;
    mid->next = NULL;

    struct node* left = mergesort(head);
    struct node* right = mergesort(midnext);

    return merge(left, right);
}

int main()
{
    insert(1);
    insert(3);
    insert(7);
    insert(3);

    display();

    head = mergesort(head);

    display();

    return 0;
}
