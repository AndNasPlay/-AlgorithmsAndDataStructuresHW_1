//
//  HW_5.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 08.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

#define T int
#define MaxN 1000

void menu(void) {
	printf("1 - Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
	printf("2 - Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение.\n");
	printf("4 - Создать функцию, копирующую односвязный список.\n");
	printf("5 - Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.\n");
	printf("6 - Реализовать очередь.\n");

	printf("0 - Выход.\n");
}

// MARK: Задание 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

T Stack[MaxN];
int N = -1;

void push(T i) {
	if (N < MaxN) {
		N++;
		Stack[N] = i;
	} else {
		printf("Stack overflow");
	}
}

T pop(void) {
	if (N != -1) {
		return Stack[N--];
	} else {
		printf("Stack is empty");
		return 0;
	}
}

void solution1(void) {
	int n = 0;

	printf("Input you value N \n");
	scanf("%d", &n);

	while (n != 0) {
		if (n % 2 == 0) {
			push(0);
			n = n / 2;
		} else {
			push(1);
			n = n / 2;
		}
	}

	while(N != -1) {
		printf("%i",pop());
	}

	printf("\n");

}

// MARK: Задание 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение.

struct TNode {
	T value;
	struct TNode *next;
};

typedef struct TNode Node;

struct SecondStack {
	Node *head;
	int size;
	int maxSize;
};

struct SecondStack MyStack;

void secondPush(T value) {

	if (MyStack.size >= MyStack.maxSize) {
		printf("Error stack size");
		return;
	}

	Node *tmp = (Node*) malloc(sizeof(Node));
	if (!tmp) {
		printf("Выделения памяти не произошло \n");
	}
	tmp->value = value;
	tmp->next = MyStack.head;
	MyStack.head = tmp;
	MyStack.size++;
}

T secondPop(void) {
	if (MyStack.size == 0) {
		printf("Stack is empty");
		return 0;
	}
	Node* next = NULL;
	T value;
	value = MyStack.head->value;
	next = MyStack.head;
	MyStack.head = MyStack.head->next;
	free(next);
	MyStack.size--;
	return value;
}

void PrintStack(void) {

	Node *current = MyStack.head;

	while(current != NULL) {
		printf("%i ", current->value);
		current = current->next;
	}
	printf("\n");
}

void solution2(void) {

	MyStack.maxSize = 100;
	MyStack.head = NULL;
	secondPush(1);
	secondPush(2);
	secondPush(3);
	secondPush(4);
	secondPush(5);
	secondPush(6);
	PrintStack();
}

// MARK: Задание 4. Создать функцию, копирующую односвязный список.


typedef struct NewNode {
	int value;
	struct NewNode *next;
} NodeSolutionFour;

typedef struct CopyNode {
	int value;
	struct CopyNode *next;
} CopySolutionFourNode;

typedef struct TempNode {
	int value;
	struct TempNode *next;
} NewTempNode;

void addValue(NodeSolutionFour **head, int data) {
	NodeSolutionFour *tmp = (NodeSolutionFour*) malloc(sizeof(NodeSolutionFour));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

void copyValuetooTemp(const NodeSolutionFour *head, NewTempNode **tempHead) {
	while (head) {
		NewTempNode *tmp = (NewTempNode*) malloc(sizeof(NewTempNode));
		tmp->value = head->value;
		if (tempHead != NULL) {
			tmp->next = (*tempHead);
			(*tempHead) = tmp;
		}
		head = head->next;
	}
}

void secondCopyValue(const NewTempNode *tempHead, CopySolutionFourNode **newHead) {
	while (tempHead) {
		CopySolutionFourNode *tmp = (CopySolutionFourNode*) malloc(sizeof(CopySolutionFourNode));
		tmp->value = tempHead->value;
		if (newHead != NULL) {
			tmp->next = (*newHead);
			(*newHead) = tmp;
		}
		tempHead = tempHead->next;
	}
}

void fromArray(NodeSolutionFour **head, int *arr, size_t size) {
	size_t i = size - 1;
	if (arr == NULL || size == 0) {
		return;
	}
	do {
		addValue(head, arr[i]);
	} while(i--!=0);
}

void printLinkedList(const NodeSolutionFour *head) {
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void printCopyLinkedList(const CopySolutionFourNode *newHead) {
	while (newHead) {
		printf("%d ", newHead->value);
		newHead = newHead->next;
	}
	printf("\n");
}

void solution4(void) {

	NodeSolutionFour* head = NULL;
	CopySolutionFourNode* newHead = NULL;
	NewTempNode* tempHead = NULL;

	int arr[] = {1,2,3,4,5,6,7,8,9,10};

	fromArray(&head, arr, 10);

	printLinkedList(head);
	copyValuetooTemp(head, &tempHead);
	secondCopyValue(tempHead, &newHead);
	printCopyLinkedList(newHead);

}

// MARK: Задание 5. Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.

void solution5(void) {

	char n[] = {'2','+','2','*','4'};
	char new[2];
	int i, symbols = 0;

	for (i = 0; i < sizeof(n); i++) {
		if (n[i] == '*' || n[i] == '+' || n[i] == '/' || n[i] == '-') {
			new[symbols] = n[i];
			symbols++;
			n[i] = n[i + 1];
			n[i+1] = NULL;
		}
	}

	for (i = 0; i < sizeof(n); i++) {
		printf("%c", n[i]);
	}
	printf("\n");
	for (i = 0; i < sizeof(new); i++) {
		printf("%c", new[i]);
	}
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
			case 4:
				solution4();
				break;
			case 5:
				solution5();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
