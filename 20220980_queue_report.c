#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable : 4996)
#define SIZE 30

typedef struct {
	int data[SIZE];
	int front;
	int rear;
}LinearQueue;

void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;
}

bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;
}

bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1;
}
bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어있습니다.\n");
		initQueue(q);
		return -1;
	}
	int value = q->data[q->front];
	q->front++;
	return value;
}

void printQueue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다.\n");
		return;
	}
	printf("큐의 현재 상태: ");
	for (int i = q->front; i <= q->rear; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");
}
int main() {
	LinearQueue q;
	initQueue(&q);
	int choice, value;

	while (true) {
		printf("\n메뉴:\n");
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 큐 데이터 출력\n");
		printf("4. 종료\n");
		printf("선택: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: 
			printf("삽입할 데이터 입력: ");
			scanf("%d", &value);
			enqueue(&q, value);
			break;
		case 2:
			printf("삭제된 데이터: %d\n", dequeue(&q));
			break;
		case 3:
			printQueue(&q);
			break;
		case 4: 
			printf("프로그램을 종료합니다.\n");
			return 0;
		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
		}
	}

	return 0;
}