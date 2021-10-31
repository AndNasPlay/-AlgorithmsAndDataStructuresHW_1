//
//  HW_2.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 20.10.2021.
//
//#include <stdio.h>
//#include <math.h>
//
//void menu(void) {
//	printf("1 - Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.\n");
//	printf("2 - Реализовать функцию возведения числа a в степень b.\n");
//
//	printf("0 - Выход.\n");
//}
//
//// MARK: Задание 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
//
//void solution1(void) {
//
//	int n, i = 0;
//	int arr[100];
//
//	printf("Input you value N \n");
//	scanf("%d", &n);
//
//	while (n != 0) {
//		if (n % 2 == 0) {
//			arr[i] = 0;
//			n = n / 2;
//		} else {
//			arr[i] = 1;
//			n = n / 2;
//		}
//		i++;
//	}
//
//	i--;
//
//	while (i >= 0) {
//		printf("%d", arr[i]);
//		i--;
//	}
//
//	printf( "\n" );
//}
//
//// MARK: Задание 2. Реализовать функцию возведения числа a в степень b
//
//double exponentiationFunction(double a, long b) {
//	if (b == 0) {
//		return 1;
//	}
//	if(b < 0) {
//		return exponentiationFunction ( 1 / a, -b);
//	}
//	if (b % 2) {
//		return a * exponentiationFunction (a, b - 1);
//	}
//	return exponentiationFunction(a * a, b / 2);
//}
//
//void solution2(void) {
//
//	int a, b, choice = 0;
//	double totalValue = 1;
//
//	printf("Реализовать функцию возведения числа a в степень b. Без рекурсии - 0, рекурсивно - 1 \n");
//	scanf("%d", &choice);
//
//	printf("Введите число a и степень числа a \n");
//	scanf("%d %d", &a, &b);
//
//	if (choice == 0) {
//
//		if (b == 0) {
//
//			printf("Результат = 1");
//			printf( "\n" );
//
//		} else if (b > 0) {
//
//			while (b != 0) {
//				totalValue *= a;
//				b--;
//			}
//
//			printf("Результат =  %.0lf", totalValue);
//			printf( "\n" );
//
//		} else  if (b < 0) {
//
//			while (b != 0) {
//				totalValue = totalValue * a;
//				b++;
//			}
//
//			printf("Результат = %lf", 1 / totalValue);
//			printf( "\n" );
//		}
//	} else if (choice == 1) {
//		printf("Результат = %lf", exponentiationFunction(a, b));
//		printf( "\n" );
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
//			default:
//				break;
//		}
//	} while (sel != 0);
//	return 0;
//}
