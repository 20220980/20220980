#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#define NAME_SIZE 50
#define PHONE_SIZE 20

// 연락처 구조체 정의
typedef struct Contact {
    char name[NAME_SIZE];
    char phone[PHONE_SIZE];
    struct Contact* next;
} Contact;

// 헤드 포인터 선언
Contact* head = NULL;

// 함수 선언
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
        printf("\n전화번호부 관리 프로그램\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 검색\n");
        printf("3. 연락처 삭제\n");
        printf("4. 전체 연락처 출력\n");
        printf("5. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        getchar(); // 버퍼 정리

        switch (choice) {
        case 1:
            printf("이름 입력: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0'; // 개행 문자 제거

            printf("전화번호 입력: ");
            fgets(phone, PHONE_SIZE, stdin);
            phone[strcspn(phone, "\n")] = '\0';

            addContact(name, phone);
            printf("연락처가 추가되었습니다.\n");
            break;

        case 2:
            printf("검색할 이름 입력: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0';

            Contact* contact = searchContact(name);
            if (contact != NULL) {
                printf("이름: %s, 전화번호: %s\n", contact->name, contact->phone);
            }
            else {
                printf("해당 이름의 연락처를 찾을 수 없습니다.\n");
            }
            break;

        case 3:
            printf("삭제할 이름 입력: ");
            fgets(name, NAME_SIZE, stdin);
            name[strcspn(name, "\n")] = '\0';

            deleteContact(name);
            printf("연락처가 삭제되었습니다.\n");
            break;

        case 4:
            printContacts();
            break;

        case 5:
            freeContacts();
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}

// 연락처 추가 함수
void addContact(const char* name, const char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;

    if (head == NULL) {
        head = newContact;
    }
    else {
        // 리스트 끝에 추가
        Contact* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

// 연락처 검색 함수
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

// 연락처 삭제 함수
void deleteContact(const char* name) {
    Contact* temp = head;
    Contact* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                // 삭제할 노드가 헤드인 경우
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

// 전체 연락처 출력 함수
void printContacts() {
    if (head == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }
    printf("\n현재 전화번호부:\n");
    Contact* temp = head;
    while (temp != NULL) {
        printf("이름: %s, 전화번호: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// 프로그램 종료 시 동적 할당 해제 함수
void freeContacts() {
    Contact* temp = head;
    while (temp != NULL) {
        Contact* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}