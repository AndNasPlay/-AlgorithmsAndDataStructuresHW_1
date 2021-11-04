//
//  HW_3.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 31.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//void menu(void) {
//	printf("1 - Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.\n");
//	printf("2 - Реализовать шейкерную сортировку.\n");
//	printf("3 - Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.\n");
//
//	printf("0 - Выход.\n");
//}
//
//// MARK: Задание 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
//
//void swap(int *a, int *b) {
//	int t = *a;
//	*a = *b;
//	*b = t;
//}
//
//void print(int N, int *a) {
//	int i;
//	for (i = 0; i < N; i++) {
//		printf("%3i", a[i]);
//	}
//	printf("\n");
//}
//
//void solution1(void) {
//
//	int firstArr[101];
//	int secondArr[101];
//	int arrayLength, z = 0, y, x, i, j = 0;
//	int counterForFirstArr = 0, counterForSecondArr = 0;
//
//	printf("Введите размер массива \n");
//	scanf("%i", &arrayLength);
//	for (i = 0; i < arrayLength; i++) {
//		firstArr[i] = rand()% 100;
//		secondArr[i] = firstArr[i];
//	}
//
//	printf("Массив до сортировки -------------\n");
//	print(arrayLength, firstArr);
//
//	for (i = 0; i < arrayLength; i++) {
//		for (j = 0; j < arrayLength - 1; j++) {
//			if (firstArr[j] > firstArr[j + 1]) {
//				counterForFirstArr += 1;
//				swap(&firstArr[j], &firstArr[j +1]);
//			}
//		}
//	}
//
//	for (z = arrayLength - 1; z >= 0; z--) {
//		x = z;
//		for (y = z; y >= 0; y--) {
//			if (secondArr[x] < secondArr[y]) {
//				counterForSecondArr += 1;
//				x = y;
//			}
//		}
//		swap(&secondArr[x], &secondArr[z]);
//	}
//
//	printf("Массив после сортировки не оптимизированной программы -------------\n");
//	print(arrayLength, firstArr);
//	printf("Количество операций сравнения не оптимизированной программы - %i, асимптотическая сложность %i\n", counterForFirstArr, arrayLength * arrayLength);
//	printf("-------------\n");
//	printf("Массив после сортировки оптимизированной программы-------------\n");
//	print(arrayLength, secondArr);
//	printf("Количество операций сравнения оптимизированной программы - %i, асимптотическая сложность %i\n", counterForSecondArr, arrayLength * arrayLength);
//	printf("-------------\n");
//}
//
//// MARK: Задание 2. Реализовать шейкерную сортировку.
//
//void solution2(void) {
//
//	int arr[101];
//	int arrayLength = 0, i;
//	int left = 0;
//	int right = 0;
//	int counter = 0;
//	int counterForArr = 0;
//
//	printf("Введите размер массива \n");
//	scanf("%i", &arrayLength);
//
//	for (i = 0; i < arrayLength; i++) {
//		arr[i] = rand()% 100;
//	}
//
//	printf("Массив до сортировки -------------\n");
//	print(arrayLength, arr);
//
//	right = arrayLength - 1;
//
//	while (left < right) {
//
//		for (counter = left; counter < right; counter++) {
//			if (arr[counter] > arr[counter + 1]) {
//				counterForArr += 1;
//				swap(&arr[counter], &arr[counter + 1]);
//			}
//		}
//		right -= 1;
//
//		for (counter = right; counter > left; counter--) {
//			if (arr[counter] < arr[counter - 1]) {
//				counterForArr += 1;
//				swap(&arr[counter], &arr[counter - 1]);
//			}
//		}
//		left += 1;
//	}
//
//	printf("Массив после сортировки -------------\n");
//	print(arrayLength, arr);
//	printf("Количество операций сравнения - %i, асимптотическая сложность %i\n", counterForArr, arrayLength * arrayLength);
//}
//
//// MARK: Задание 3. Реализовать бинарный алгоритм поиска.
//
//void solution3(void) {
//
//	int arr[101];
//	int arrayLength = 10, i;
//	int value;
//	int start, middle, maximum;
//	int counter = 0;
//
//	printf("Введите размер массива \n");
//	scanf("%i", &arrayLength);
//
//	for (i = 0; i < arrayLength; i++) {
//		arr[i] = i + 2;
//	}
//
//	printf("Массив \n");
//	print(arrayLength, arr);
//	printf("Введите искомое значение \n");
//	scanf("%i", &value);
//
//	start = 0;
//	maximum = arrayLength - 1;
//
//	while (start <= maximum) {
//		middle = (start + maximum) / 2;
//		if (value < arr[middle]) {
//			maximum = middle - 1;
//		}
//		else if (value > arr[middle]) {
//			start = middle + 1;
//		}
//		else {
//			printf("Индекс найденного элемента - %i \n", middle);
//			counter+=1;
//			break;
//		}
//	}
//	if (counter == 0) {
//		printf("Элемент не найден -1 \n");
//	}
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
//			case 3:
//				solution3();
//				break;
//			default:
//				break;
//		}
//	} while (sel != 0);
//	return 0;
//}
