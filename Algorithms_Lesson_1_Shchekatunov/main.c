//
//  main.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 18.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <curses.h>

void menu(void) {
	printf("1 - Найти индекс массы тела.\n");
	printf("2 - Найти максимальное из четырех чисел.\n");
	printf("3 - Написать программу обмена значениями двух целочисленных переменных.\n");
	printf("4 - Написать программу нахождения корней заданного квадратного уравнения.\n");
	printf("5 - К какому времени года относится месяц.\n");
	printf("6 - Возраст человека (от 1 до 150 лет).\n");
	printf("7 - Координаты двух полей шахматной доски, относятся поля к одному цвету или нет.\n");
	printf("8 - Ввести a и b и вывести квадраты и кубы чисел от a до b.\n");
	printf("9 - Найти частное от деления нацело N на K, а также остаток от этого деления.\n");
	printf("10 - С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры.\n");
	printf("11 - С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.\n");

	printf("0 - Выход.\n");
}

// MARK: Задание 1. Ввести вес и рост человека.
//Рассчитать и вывести индекс массы тела по формуле I=m/(h*h)  где m-масса тела в килограммах, h - рост в метрах.

double funcBodyMassIndex(double weight, double height) {
	return  weight / (height * height);
}

void solution1(void) {

	double weight, height;
	double bodyMassIndex;

	printf("Input you weight (kilo) and height (meter): ");
	scanf("%lf %lf", &weight, &height);

	bodyMassIndex = funcBodyMassIndex(weight, height);

	if (bodyMassIndex <= 16) {
		printf("Body Mass Index = %.2lf  У вас - выраженный дефицит массы тела\n", bodyMassIndex);
	} else if (16 < bodyMassIndex && bodyMassIndex <= 18.5) {
		printf("Body Mass Index = %.2lf  У вас - Недостаточная (дефицит) масса тела\n", bodyMassIndex);
	} else if (18.5 < bodyMassIndex && bodyMassIndex <= 25) {
		printf("Body Mass Index = %.2lf  У вас - Норма\n", bodyMassIndex);
	} else if (25 < bodyMassIndex && bodyMassIndex <= 30) {
		printf("Body Mass Index = %.2lf  У вас - Избыточная масса тела (предожирение)\n", bodyMassIndex);
	} else if (30 < bodyMassIndex && bodyMassIndex <= 35) {
		printf("Body Mass Index = %.2lf  У вас - Ожирение первой степени\n", bodyMassIndex);
	} else if (35 < bodyMassIndex && bodyMassIndex <= 40) {
		printf("Body Mass Index = %.2lf  У вас - Ожирение второй степени\n", bodyMassIndex);
	} else if (40 < bodyMassIndex) {
		printf("Body Mass Index = %.2lf  У вас - Ожирение третьей степени (морбидное)\n", bodyMassIndex);
	}
}

// MARK: Задание 2. Найти максимальное из четырех чисел.

int funcFindMaxValue(int a, int b) {
	return ((a) > (b) ? (a) : (b));
}

int funcFindTheGreatestValue(int a, int b, int c, int d) {
	return ((funcFindMaxValue(a, b)) > (funcFindMaxValue(c, d)) ? ((funcFindMaxValue(a, b))) : ((funcFindMaxValue(c, d))));
}

void solution2(void) {

	int a, b, c, d;
	int greatestValue;

	printf("Input you 4 values ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	greatestValue = funcFindTheGreatestValue(a, b, c, d);

	printf("Самое больше значени - %d \n", greatestValue);
}

// MARK: Задание 3. Написать программу обмена значениями двух целочисленных переменных.
// a. с использованием третьей переменной, b. *без использования третьей переменной.

void solution3(void) {

	int a, b;
	int x, y;
	int c = -1;

	printf("Input you 2 values ");
	scanf("%d %d", &a, &b);

	x = a;
	y = b;

	c = a;
	a = b;
	b = c;

	x = x + y;
	y = y - x;
	y = -y;
	x = x - y;

	printf("C использованием 3 переменной \nЗначение а = %d, значение b = %d \n", a, b);
	printf("Без использования 3 переменной \nЗначение а = %d, значение b = %d \n", x, y);
}

// MARK: Задание 4. Написать программу нахождения корней заданного квадратного уравнения.

void solution4(void) {

	double a, b, c;
	double discriminant;

	printf("Input you 3 coefficients a, b, c \n");
	scanf("%lf %lf %lf", &a, &b, &c);

	discriminant = (pow(b, 2) - (4 * a * c));
	if (discriminant < 0) {
		printf("В квадратном уравнении нет корней \n");
	} else if (discriminant == 0) {
		printf("В квадратном уравнении один корень %.2lf \n", ((-b) / (2 * a)));
	} else {
		printf("В квадратном уравнении два кореня x1 =  %.2lf \n", (((-b) + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a)));
		printf("В квадратном уравнении два кореня x2 =  %.2lf \n", (((-b) - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a)));
	}
}

// MARK: Задание 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.

void solution5(void) {

	int mounth;

	printf("Input you mounth between 1...12\n");

	scanf("%d", &mounth);

	switch (mounth) {
		case 1 ... 2:
			printf("Зима\n");
			break;
		case 3 ... 5:
			printf("Весна\n");
			break;
		case 6 ... 8:
			printf("Лето\n");
			break;
		case 9 ... 11:
			printf("Осень\n");
			break;
		case 12:
			printf("Зима\n");
			break;
		default:
			printf("Нет такого месяца\n");
			break;
	}
}

// MARK: Задание 6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».

void solution6(void) {

	int age;

	printf("Input you age \n");
	scanf("%d", &age);

	if((age % 10) == 1 && age!= 11 && age!= 111) {
		printf("Вам %d год\n", age);
	} else if((age % 10) > 1 && (age % 10) < 5 && age!= 112 && age!= 113 && age!= 12 && age!= 13 && age!= 14 && age!= 114) {
		printf("Вам %d года\n", age);
	} else if(((age % 10) > 4 && (age % 10) < 10 ) || ((age % 10) == 0 && age >= 11 && age <= 20 && age >= 111)) {
		printf("Вам %d лет\n", age);
	} else if (age == 112 || age == 113) {
		printf("Вам %d лет\n", age);
	} else {
		printf("Вам %d лет\n", age);
	}
}

// MARK: Задание 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся поля к одному цвету или нет.

void solution7(void) {

	int x1, x2, y1, y2;

	printf("Input position x1, y1, x2, y2 \n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if ((x1 + y1 + x2 + y2) % 2 == 0) {
		printf("Поля относятся к одному цвету \n");
	} else {
		printf("Поля разных цветов \n");
	}
}

// MARK: Задание 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.

void solution8(void) {

	int a, b, z;

	printf("Input you a and b value: \n");
	scanf("%d %d", &a, &b);

	z = a;

	while (z <= b) {
		printf("Квадрат числа = %.0f \n",pow(z, 2));
		printf("Куб числа = %.0f \n",pow(z, 3));
		z += 1;
	}
}

// MARK: Задание 9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.

void solution9(void) {

	int n, k;
	int num = 0;

	printf("Input you n and k value: \n");
	scanf("%d %d", &n, &k);

	while (n >= k){
		n -= k;
		++num;
	}

	printf("Частное от деления нацело N на K %i \n",num);
	printf("Остаток от этого деления %i \n",n);

}

// MARK: Задание 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.

int funcSearchCountOfDigits(int n) {
	int countValue = 0;
	if (n / 10 == 0) {
		return 1;
	} else {
		while (n > 0) {
			n = n / 10;
			countValue += 1;
		}
		return countValue;
	}
};

void solution10(void) {

	int n, countValue, counter = 0, zeroNumber = 10, check = 0;

	printf("Input you N value: \n");
	scanf("%d", &n);

	countValue = funcSearchCountOfDigits(n);

	while (counter != countValue) {
		counter += 1;

		if (n % zeroNumber == 1 || n % zeroNumber == 3 || n % zeroNumber == 5 || n % zeroNumber == 7 || n % zeroNumber == 9 || n == zeroNumber) {
			check = 1;
			printf("TRUE \n");
			break;
		}
		zeroNumber = zeroNumber * 10;
	}
	if (check == 0) {
		printf("FALSE \n");
	}
}

// MARK: Задание 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.

void solution11(void) {

	int n = -1;
	int arr[10] = {0};

	while (n != 0) {
		printf("Input you N values for break input 0: \n");
		scanf("%d", &n);
		&arr[n];
		printf("%d ", arr[n]);
	}
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
			case 5:
				solution5();
				break;
			case 6:
				solution6();
				break;
			case 7:
				solution7();
				break;
			case 8:
				solution8();
				break;
			case 9:
				solution9();
				break;
			case 10:
				solution10();
				break;
			case 11:
				solution11();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
