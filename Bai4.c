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

bool searchRecursive(Node* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    return searchRecursive(root->left, value) || searchRecursive(root->right, value);
}

bool searchIterative(Node* root, int value) {
    if (root == NULL) {
        return false;
    }

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (current->data == value) {
            return true;
        }

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }

    return false;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    if (searchRecursive(root, value)) {
        printf("Gia tri %d duoc tim thay trong cay (de quy).\n", value);
    } else {
        printf("Gia tri %d khong duoc tim thay trong cay (de quy).\n", value);
    }

    if (searchIterative(root, value)) {
        printf("Gia tri %d duoc tim thay trong cay (vong lap).\n", value);
    } else {
        printf("Gia tri %d khong duoc tim thay trong cay (vong lap).\n", value);
    }

    return 0;
}

