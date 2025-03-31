//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#pragma warning(disable:4996)
//
//double calculateAverage(int scores[], int size);
//int getStudentScore(int scores[], int size, int studentNumber);
//void printScore(int scores[], int size, double average, int option);
//
//int main() {
//    int scores[30];
//    int studentNumber;
//    double average;
//
//    srand(time(0));
//
//    for (int i = 0; i < 30; i++) {
//        scores[i] = rand() % 101;
//    }
//
//    average = calculateAverage(scores, 30);
//    printf("�б� ��� ����: %.2f\n", average);
//
//    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
//    scanf("%d", &studentNumber);
//
//    int score = getStudentScore(scores, 30, studentNumber);
//    if (score != -1) {
//        printf("%d�� �л��� ����: %d\n", studentNumber, score);
//    }
//    else {
//        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n");
//    }
//
//    printScore(scores, 30, average, 2);
//
//    return 0;
//}
//
//double calculateAverage(int scores[], int size) {
//    int sum = 0;
//    for (int i = 0; i < size; i++) {
//        sum += scores[i];
//    }
//    return sum / (double)size;
//}
//
//int getStudentScore(int scores[], int size, int studentNumber) {
//    if (studentNumber >= 1 && studentNumber <= size) {
//        return scores[studentNumber - 1];
//    }
//    else {
//        return -1;
//    }
//}
//
//void printScore(int scores[], int size, double average, int option) {
//    switch (option) {
//    case 0:
//        for (int i = 0; i < size; i++) {
//            printf("�л���ȣ : %d, ���� %d\n", i + 1, scores[i]);
//        }
//        break;
//    case 1:
//        printf("����̻� �л�\n");
//        for (int i = 0; i < size; i++) {
//            if (scores[i] >= average) printf("�л���ȣ : %d, ���� %d\n", i + 1, scores[i]);
//        }
//    case 2:
//        printf("��չ̸� �л�\n");
//        for (int i = 0; i < size; i++) {
//            if (scores[i] < average) printf("�л���ȣ : %d, ���� %d\n", i + 1, scores[i]);
//        }
//        break;
//    default:
//        printf("��ȿ���� ���� �ɼ��Դϴ�.\n");
//        break;
//    }
//
// 
//}