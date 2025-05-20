#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    return head;
}

void insertAfterValue(Node* head, int target, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (!newNode) {
                printf("�޸� �Ҵ� ����\n");
                exit(1);
            }
            newNode->data = data;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("�� %d�� ã�� �� �����ϴ�. ���� ����.\n", target);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchValue1(Node* head, int val) {
    int pos = 1;
    Node* current = head;
    while (current != NULL) {
        if (current->data == val)
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

void searchValue2(Node* head, int val) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val) {
            if (prev != NULL)
                printf("�� ��� ��: %d\n", prev->data);
            else
                printf("�� ��� ����\n");

            if (current->next != NULL)
                printf("�� ��� ��: %d\n", current->next->data);
            else
                printf("�� ��� ����\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("�� %d�� ã�� �� �����ϴ�.\n", val);
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // ��� ����
    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);
    head = insertLast(head, 70);
    head = insertLast(head, 80);
    head = insertLast(head, 90);
    insertAfterValue(head, 30, 40);
    insertAfterValue(head, 40, 50);
    insertAfterValue(head, 50, 60);

    printf("����Ʈ ���:\n");
    printList(head);

    int val1 = 30;
    int pos = searchValue1(head, val1);
    if (pos != -1)
        printf("%d�� ��ġ�� %d��°\n", val1, pos);
    else
        printf("%d�� ����Ʈ�� �����ϴ�.\n", val1);

    int val2 = 30;
    printf("\n%d�� ���� �յ� ��� ���:\n", val2);
    searchValue2(head, val2);

    freeList(head);
    return 0;
}
