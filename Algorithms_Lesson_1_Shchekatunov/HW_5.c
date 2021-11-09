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
#define QMAX 100

void menu(void) {
	printf("1 - Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.\n");
	printf("2 - Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение.\n");
	printf("4 - Создать функцию, копирующую односвязный список.\n");
	printf("5 - Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную. (не реализовал!) \n");
	printf("6 - Реализовать очередь на массиве.\n");

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

struct PostfixNode {
	char value;
	struct PostfixNode *next;
};

typedef struct PostfixNode NewPostfixNode;

struct OtherNode {
	char value;
	struct OtherNode *next;
};

typedef struct OtherNode NewOtherNode;

struct PostfixStack {
	NewPostfixNode *head;
	int size;
	int maxSize;
};

struct PostfixStack NewPostfixStack;

struct OtherStack {
	NewOtherNode *head;
	int size;
	int maxSize;
};

struct OtherStack NewOtherStack;

void postfixPush(char value) {

	if (NewPostfixStack.size >= NewPostfixStack.maxSize) {
		printf("Error stack size");
		return;
	}
	if (value == '+' || value == '-' || value == '*' || value == '/') {
		NewOtherNode *other = (NewOtherNode*) malloc(sizeof(NewOtherNode));
		other->value = value;
		other->next = NewOtherStack.head;
		NewOtherStack.head = other;
		NewOtherStack.size++;
	} else {
		NewPostfixNode *tmp = (NewPostfixNode*) malloc(sizeof(NewPostfixNode));
		tmp->value = value;
		tmp->next = NewPostfixStack.head;
		NewPostfixStack.head = tmp;
		NewPostfixStack.size++;
	}
}

char postfixPop(void) {
	if (NewPostfixStack.size == 0) {
		printf("Stack is empty");
		return 0;
	}
	NewPostfixNode* next = NULL;
	char value;
	value = NewPostfixStack.head->value;
	next = NewPostfixStack.head;
	NewPostfixStack.head = NewPostfixStack.head->next;
	free(next);
	NewPostfixStack.size--;
	return value;
}

char newArr[100];

void printPostfixStack(void) {

	int counter = 0;
	int characterCounter = 0;

	NewPostfixNode *current = NewPostfixStack.head;
	NewOtherNode *other = NewOtherStack.head;

	for (int i = 0; other != NULL; i++) {

		newArr[i] = other->value;
		other = other->next;
		characterCounter++;
		counter++;
	}


	for (int i = characterCounter; current != NULL; i++) {
		newArr[i] = current->value;
		current = current->next;
		counter++;
	}

	while (counter >= 0) {
		printf("%c ", newArr[counter]);
		counter--;
	}
	printf("\n");
}

void solution5(void) {

	NewPostfixStack.maxSize = 100;
	NewPostfixStack.head = NULL;
	postfixPush('2');
	postfixPush('*');
	postfixPush('2');
	postfixPush('+');
	postfixPush('3');
	printPostfixStack();
}

// MARK: Задание 6. Реализовать очередь на массиве.

typedef struct Queue {

	int queueArr[QMAX];
	int lasElem, firstElem;

} ArrQueueNew;

void initQueue(struct Queue *q) {

	q->firstElem = 1;
	q->lasElem = 0;
	return;
}

void pushArrQueue(struct Queue *q, int x) {
	if (q->lasElem < QMAX-1) {
		q->lasElem++;
		q->queueArr[q->lasElem] = x;
	} else {
		printf("Очередь полна!\n");
	}
}

int queueIsempty(struct Queue *q) {
	if(q->lasElem < q->firstElem) {
		return 1;
	} else  {
		return 0;
	}
}

void printQueue(struct Queue *q) {
	int h;
	if (queueIsempty(q) == 1) {
		printf("Очередь пуста!\n");
		return;
	}
	for(h = q->firstElem; h<= q->lasElem; h++) {
		printf("%d ",q->queueArr[h]);
	}
	return;
}

int popFromQueue(struct Queue *q) {
	int x, h;
	if (queueIsempty(q) == 1) {
		printf("Очередь пуста!\n");
		return 0;
	}
	x = q->queueArr[q->firstElem];
	for(h = q->firstElem; h < q->lasElem; h++) {
		q->queueArr[h] = q->queueArr[h+1];
	}
	q->lasElem--;
	return x;
}

void solution6(void) {

	struct Queue *q;
	int a;
	q = (ArrQueueNew*)malloc(sizeof(ArrQueueNew));

	initQueue(q);
	printQueue(q);

	for(int i=0;i<4;i++) {
		printf("Введите элемент очереди: ");
		scanf("%d", &a);
		pushArrQueue(q, a);
	}

	printf("\n");
	printQueue(q);

	while(q->firstElem <= q->lasElem) {
		a = popFromQueue(q);
		printf("\nУдален элемент %d\n", a);
		printQueue(q);
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
			case 4:
				solution4();
				break;
			case 5:
				solution5();
				break;
			case 6:
				solution6();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
