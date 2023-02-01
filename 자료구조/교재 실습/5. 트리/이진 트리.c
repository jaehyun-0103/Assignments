#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* newNode(int data) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return(node);
}

// 전위 순회
void printPreorder(NODE* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// 중위 순회
void printInorder(NODE* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// 후위 순회
void printPostorder(NODE* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    NODE* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("전위 순회: ");
    printPreorder(root);
    printf("\n중위 순회: ");
    printInorder(root);
    printf("\n후위 순회: ");
    printPostorder(root);
}