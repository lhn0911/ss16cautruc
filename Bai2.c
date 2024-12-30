#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("PreOrder: ");
    preOrder(root);
    printf("\n");

    printf("InOrder: ");
    inOrder(root);
    printf("\n");

    printf("PostOrder: ");
    postOrder(root);
    printf("\n");

    return 0;
}
