//
//  HW_4.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 01.11.2021.
//

//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>
//#include <string.h>
//#define N 6
//#define M 6
//
//
//void menu(void) {
//	printf("1 - Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.\n");
//	printf("2 - Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.\n");
//
//	printf("0 - Выход.\n");
//}
//
//// MARK: Задание 1. Количество маршрутов с препятствиями.
//
//void PrintBoard(int n, int m, int a[N][M])
//{
//	int i, j;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			printf("%6d", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void solution1(void) {
//
//	int A[N][M];
//	int i, j;
//	for (j = 0; j < M; j++) {
//		A[0][j] = 1;
//	}
//	for (i = 1; i < N; i++) {
//		A[i][0] = 1;
//		A[1][0] = 0;
//		A[2][0] = 0;
//		A[4][4] = 0;
//		A[3][2] = 0;
//
//		for (j = 1; j < M; j++) {
//			A[i][j] = A[i][j - 1] + A[i - 1][j];
//		}
//	}
//	PrintBoard(N, M, A);
//}
//
//// MARK: Задание 2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
//
//int i, j, m, n, c[20][20];
//char x[20], y[20], b[20][20];
//
//void print(int i, int j) {
//	if (i == 0 || j == 0) {
//		return;
//	}
//	if (b[i][j] == 'c') {
//		print(i - 1, j - 1);
//		printf("%c", x[i - 1]);
//	} else if (b[i][j] == 'u') {
//		print(i - 1, j);
//	}
//	else {
//		print(i, j - 1);
//	}
//}
//
//void solution2(void) {
//
//	printf("Enter 1st sequence:");
//	scanf("%s", x);
//	printf("Enter 2nd sequence:");
//	scanf("%s", y);
//
//	m = strlen(x);
//	n = strlen(y);
//
//	for (i = 0; i <= m; i++)
//		c[i][0] = 0;
//	for (i = 0; i <= n; i++)
//		c[0][i] = 0;
//
//	for (i = 1; i <= m; i++) {
//		for (j = 1; j <= n; j++) {
//			if (x[i - 1] == y[j - 1]) {
//				c[i][j] = c[i - 1][j - 1] + 1;
//				b[i][j] = 'c';
//				printf("%c", b[i][j]);
//
//			} else if (c[i - 1][j] >= c[i][j - 1]) {
//				c[i][j] = c[i - 1][j];
//				b[i][j] = 'u';
//				printf("%c", b[i][j]);
//			} else {
//				c[i][j] = c[i][j - 1];
//				b[i][j] = 'l';
//				printf("%c", b[i][j]);
//			}
//		}
//	}
//	printf("\n");
//	printf("The Longest Common Subsequence is ");
//	print(m, n);
//	printf("\n");
//}
//
//int main(int argc, char *argv[]) {
//
//	int sel = 0;
//	do {
//		menu();
//		scanf("%i", &sel);
//		switch (sel) {
//			case 0:
//				printf("Thank you, bye! \n");
//				break;
//			case 1:
//				solution1();
//				break;
//			case 2:
//				solution2();
//				break;
//			default:
//				break;
//		}
//	} while (sel != 0);
//	return 0;
//}
