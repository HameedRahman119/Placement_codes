#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

static TreeNode *create_node(int data)
{
    TreeNode *node = malloc(sizeof(*node));

    if (node == NULL)
        return NULL;

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

static void inorder(const TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

static void preorder(const TreeNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

static void postorder(const TreeNode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

static const TreeNode *search(const TreeNode *root, int target)
{
    if (root == NULL || root->data == target)
        return root;

    if (target < root->data)
        return search(root->left, target);

    return search(root->right, target);
}

static void free_tree(TreeNode *root)
{
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    const int values[] = {50, 30, 70, 20, 40, 60, 80};
    const size_t count = sizeof(values) / sizeof(values[0]);
    TreeNode *root = NULL;

    for (size_t i = 0; i < count; ++i) {
        TreeNode *new_root = insert(root, values[i]);

        if (new_root == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free_tree(root);
            return EXIT_FAILURE;
        }

        root = new_root;
    }

    printf("Inorder:   ");
    inorder(root);
    printf("\n");

    printf("Preorder:  ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    const int target = 60;
    if (search(root, target) != NULL)
        printf("%d found in BST\n", target);
    else
        printf("%d not found in BST\n", target);

    free_tree(root);
    return EXIT_SUCCESS;
}
