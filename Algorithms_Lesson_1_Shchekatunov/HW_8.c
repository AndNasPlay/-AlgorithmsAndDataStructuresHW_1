//
//  HW_8.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 16.11.2021.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define items 10

void menu(void) {
	printf("1 - Реализовать сортировку подсчетом.\n");
	printf("2 - Реализовать быструю сортировку.\n");
	printf("3 - Реализовать сортировку слиянием.\n");
	printf("4 - Реализовать алгоритм сортировки со списком.\n");

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

void countSort(int array[items]) {
	int secondArray[items];

	zeroingArray(secondArray);

	for (int i = 0; i < items; i++) {
		for (int j = 0; j < items; j++) {
			if (array[i] == j) {
				secondArray[j] = secondArray[j] + 1;
				array[i] = 0;
			}
		}
	}

	int positionInFirstArray = 0;
	int counter = 0;

	for (int j = 0; j < items; j++) {
		if (secondArray[j] != 0) {
			for (counter = secondArray[j]; counter > 0; counter--) {
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

	countSort(firstArray);

	printf("Отсортированный массив: \n");

	printArray(firstArray);

	printf("\n");
}

// MARK: Задание 2. Реализовать быструю сортировку.

void quickSort(int *numbers, int left, int right) {
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];

	while (left < right) {
		while ((numbers[right] >= pivot) && (left < right)) {
			right--;
		}
		if (left != right) {
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right)) {
			left++;
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
	}

	if (right > pivot) {
		quickSort(numbers, pivot + 1, right);
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

	quickSort(a, 0, items - 1);

	printf("Отсортированный массив: \n");

	printArray(a);

	printf("\n");

}

// MARK: Задание 3. Реализовать сортировку слиянием.

void mergeSort(int *a, int left, int right) {

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
		} else {
			tmp[step] = a[j];
			j++;
		}
	}

	for (int step = 0; step < right - left + 1; step++) {
		a[left + step] = tmp[step];
	}
}

void solution3(void) {

	int mergeArray[items];

	printf("Начальный массив: \n");

	for (int i = 0; i < items; i++) {
		mergeArray[i] = rand() % 100;
		printf(" %d ", mergeArray[i]);
	}

	mergeSort(mergeArray, 0, items - 1);

	printf("\n");

	printf("Отсортированный массив: \n");

	printArray(mergeArray);

	printf("\n");
}

// MARK: Задание 4. Реализовать алгоритм сортировки со списком.

void solution4(void) {

	int listArray[items];

	printf("Начальный массив: \n");

	for (int i = 0; i < items; i++) {
		listArray[i] = rand() % 100;
		printf(" %d ", listArray[i]);
	}



	printf("\n");

	printf("Отсортированный массив: \n");


	printf("\n");
}

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
			case 4:
				solution4();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
