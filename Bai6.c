#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

int countNodesGreaterThanX(Node* root, int X) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->data > X) {
        count = 1;
    }

    count += countNodesGreaterThanX(root->left, X);
    count += countNodesGreaterThanX(root->right, X);

    return count;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 30);

    int X;
    printf("Nhap gia tri X: ");
    scanf("%d", &X);

    int count = countNodesGreaterThanX(root, X);
    printf("So luong nut co gia tri lon hon %d la: %d\n", X, count);

    return 0;
}

