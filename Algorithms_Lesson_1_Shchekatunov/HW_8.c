//
//  HW_8.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 16.11.2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define items 100

void menu(void) {
	printf("1 - Реализовать сортировку подсчетом.\n");
	printf("2 - Реализовать быструю сортировку.\n");
	printf("3 - Реализовать сортировку слиянием.\n");

	printf("0 - Выход.\n");
}

// MARK: Задание 1. Реализовать сортировку подсчетом.

void zeroingArray(int array[items]) {
	for (int i = 0; i < items; i++) {
		array[i] = 0;
	}
}

void printArray(int array[items]) {
	for (int i = 0; i < items; i++) {
		printf(" %d ", array[i]);
	}
}

int countingActionsCountSort = 0;

void countSort(int array[items]) {
	int secondArray[items];

	zeroingArray(secondArray);

	for (int i = 0; i < items; i++) {
		for (int j = 0; j < items; j++) {
			countingActionsCountSort++;
			if (array[i] == j) {
				secondArray[j] = secondArray[j] + 1;
				array[i] = 0;
			}
		}
	}

	int positionInFirstArray = 0;

	for (int j = 0; j < items; j++) {
		if (secondArray[j] != 0) {
			countingActionsCountSort++;
			for (int counter = secondArray[j]; counter > 0; counter--) {
				array[positionInFirstArray] = j;
				positionInFirstArray++;
			}
		}
	}

}

void solution1(void) {

	int firstArray[items];

	for (int i = 0; i < items; i++) {
		firstArray[i] = rand() % items;
	}

	printf("Начальный массив: \n");
	printArray(firstArray);

	printf("\n");

	clock_t begin = clock();

	countSort(firstArray);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Отсортированный массив: \n");

	printArray(firstArray);

	printf("\n");

	printf("Колличество сравнений: %d \n", countingActionsCountSort);

	printf("Затраченное время: %f \n", time_spent);

}

// MARK: Задание 2. Реализовать быструю сортировку.

long long int countingActionsQuickSort = 0;

void quickSort(int *numbers, int left, int right) {
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];

	while (left < right) {
		while ((numbers[right] >= pivot) && (left < right)) {
			right--;
			countingActionsQuickSort++;
		}
		if (left != right) {
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right)) {
			left++;
			countingActionsQuickSort++;
		}
		if (left != right) {
			numbers[right] = numbers[left];
			right--;
		}
	}

	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) {
		quickSort(numbers, left, pivot - 1);
		countingActionsQuickSort++;
	}

	if (right > pivot) {
		quickSort(numbers, pivot + 1, right);
		countingActionsQuickSort++;
	}
}

void solution2(void) {

	int a[items];

	for (int i = 0; i < items; i++) {
		a[i] = rand() % 100;
	}

	printf("Начальный массив: \n");

	printArray(a);

	printf("\n");

	clock_t begin = clock();

	quickSort(a, 0, items - 1);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Отсортированный массив: \n");

	printArray(a);

	printf("\n");

	printf("Колличество сравнений: %lld \n", countingActionsQuickSort);

	printf("Затраченное время: %f \n", time_spent);

}

// MARK: Задание 3. Реализовать сортировку слиянием.

int countingActionsMergeSort = 0;

void mergeSort(int *a, int left, int right) {
	countingActionsMergeSort++;

	if (left == right) {
		return;
	}

	int middle = (left + right) / 2;

	mergeSort(a, left, middle);
	mergeSort(a, middle + 1, right);

	int i = left;

	int j = middle + 1;

	int *tmp = (int*)malloc(right * sizeof(int));

	for (int step = 0; step < right - left + 1; step++) {

		if ((j > right) || ((i <= middle) && (a[i] < a[j]))) {
			tmp[step] = a[i];
			i++;
			countingActionsMergeSort++;
		} else {
			tmp[step] = a[j];
			j++;
			countingActionsMergeSort++;
		}
	}

	for (int step = 0; step < right - left + 1; step++) {
		a[left + step] = tmp[step];
		countingActionsMergeSort++;
	}
}

void solution3(void) {

	int mergeArray[items];

	printf("Начальный массив: \n");

	for (int i = 0; i < items; i++) {
		mergeArray[i] = rand() % 100;
		printf(" %d ", mergeArray[i]);
	}

	clock_t begin = clock();

	mergeSort(mergeArray, 0, items - 1);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("\n");

	printf("Отсортированный массив: \n");

	printArray(mergeArray);

	printf("\n");

	printf("Затраченное время: %f \n", time_spent);

	printf("Колличество сравнений: %d \n", countingActionsMergeSort);
}

// MARK: Задание 4. Проанализировать время работы каждого из вида сортировок для 100, 10000, 1000000 элементов.

int main(int argc, char *argv[]) {

	int sel = 0;
	do {
		menu();
		scanf("%i", &sel);
		switch (sel) {
			case 0:
				printf("Thank you, bye! \n");
				break;
			case 1:
				solution1();
				break;
			case 2:
				solution2();
				break;
			case 3:
				solution3();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
