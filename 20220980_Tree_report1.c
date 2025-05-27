#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // INT_MIN

// 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 노드 생성 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 전위 순회
void preorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// 중위 순회
void inorder(TreeNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// 후위 순회
void postorder(TreeNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// 트리 높이
int getHeight(TreeNode* node) {
    if (node == NULL) return -1;
    int l = getHeight(node->left);
    int r = getHeight(node->right);
    return (l > r ? l : r) + 1;
}

// 전체 노드 수
int countNodes(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// 리프 노드 수
int countLeaves(TreeNode* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

// 노드 값 총합
int getSum(TreeNode* node) {
    if (node == NULL) return 0;
    return node->data + getSum(node->left) + getSum(node->right);
}

// 최댓값
int getMax(TreeNode* node) {
    if (node == NULL) return INT_MIN;
    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);
    int max = node->data;
    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;
    return max;
}

// 범위 내 노드 출력 (전위 순회 방식)
void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL) return;
    if (node->data >= min && node->data <= max)
        printf("%d ", node->data);
    searchRange(node->left, min, max);
    searchRange(node->right, min, max);
}

// 트리 메모리 해제
void freeTree(TreeNode* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// 메인 함수
int main() {
    // 트리 구성
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // 순회 출력
    printf("전위 순회: ");
    preorder(root);
    printf("\n");

    printf("중위 순회: ");
    inorder(root);
    printf("\n");

    printf("후위 순회: ");
    postorder(root);
    printf("\n");

    // 속성 출력
    printf("\n트리 높이: %d\n", getHeight(root));
    printf("전체 노드 수: %d\n", countNodes(root));
    printf("리프 노드 수: %d\n", countLeaves(root));
    printf("노드 값 총합: %d\n", getSum(root));
    printf("최댓값: %d\n", getMax(root));

    // 범위 출력
    printf("\n값이 6 이상 20 이하인 노드: ");
    searchRange(root, 6, 20);
    printf("\n");

    // 메모리 해제
    freeTree(root);
    return 0;
}
