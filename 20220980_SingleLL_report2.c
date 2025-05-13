#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#define NAME_SIZE 50
#define PHONE_SIZE 20

// ����ó ����ü ����
typedef struct Contact {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct Contact* next;
} Contact;

// ��� ������ ����
Contact* head = NULL;

// �Լ� ����
void addContact(const char* name, const char* phone);
void deleteContact(const char* name);
Contact* searchContact(const char* name);
void printContacts();
void freeContacts();

int main() {
    int choice;
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];

    while (1) {
        printf("\n��ȭ��ȣ�� ���� ���α׷�\n");
        printf("1. ����ó �߰�\n");
        printf("2. ����ó �˻�\n");
        printf("3. ����ó ����\n");
        printf("4. ��ü ����ó ���\n");
        printf("5. ����\n");
        printf("����: ");
        scanf("%d", &choice);
        getchar(); // ���� ����

        switch (choice) {
        case 1:
            printf("�̸� �Է�: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0'; // ���� ���� ����

            printf("��ȭ��ȣ �Է�: ");
            fgets(phone, PHONE_SIZE, stdin);
            phone[strcspn(phone, "\n")] = '\0';

            addContact(name, phone);
            printf("����ó�� �߰��Ǿ����ϴ�.\n");
            break;

        case 2:
            printf("�˻��� �̸� �Է�: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0';

            Contact* contact = searchContact(name);
            if (contact != NULL) {
                printf("�̸�: %s, ��ȭ��ȣ: %s\n", contact->name, contact->phone);
            }
            else {
                printf("�ش� �̸��� ����ó�� ã�� �� �����ϴ�.\n");
            }
            break;

        case 3:
            printf("������ �̸� �Է�: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0';

            deleteContact(name);
            printf("����ó�� �����Ǿ����ϴ�.\n");
            break;

        case 4:
            printContacts();
            break;

        case 5:
            freeContacts();
            printf("���α׷��� �����մϴ�.\n");
            return 0;

        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    return 0;
}

// ����ó �߰� �Լ�
void addContact(const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if (head == NULL) {
        head = newContact;
    }
    else {
        // ����Ʈ ���� �߰�
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

// ����ó �˻� �Լ�
Contact* searchContact(const char* name) {
    Contact* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// ����ó ���� �Լ�
void deleteContact(const char* name) {
    Contact* temp = head;
    Contact* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                // ������ ��尡 ����� ���
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// ��ü ����ó ��� �Լ�
void printContacts() {
    if (head == NULL) {
        printf("��ȭ��ȣ�ΰ� ��� �ֽ��ϴ�.\n");
        return;
    }
    printf("\n���� ��ȭ��ȣ��:\n");
    Contact* temp = head;
    while (temp != NULL) {
        printf("�̸�: %s, ��ȭ��ȣ: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// ���α׷� ���� �� ���� �Ҵ� ���� �Լ�
void freeContacts() {
    Contact* temp = head;
    while (temp != NULL) {
        Contact* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}