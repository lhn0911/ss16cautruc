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

int findMax(Node* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    int max = root->data;
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }

    return max;
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    int maxValue = findMax(root);
    printf("Gia tri lon nhat trong cay la: %d\n", maxValue);

    return 0;
}

