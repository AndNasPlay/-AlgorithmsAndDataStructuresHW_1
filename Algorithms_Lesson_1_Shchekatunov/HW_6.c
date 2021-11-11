//
//  HW_6.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 11.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))


void menu(void) {
	printf("1 - Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.\n");
	printf("2 - Переписать программу, реализующую двоичное дерево поиска.\n");

	printf("0 - Выход.\n");
}


// MARK: Задание 1. Реализовать простейшую хеш-функцию.

int makeHash (char str[]) {
	int newHash[80];
	int strCount = strlen(str);
	int seed = 159321;
	long long int hash = 0;
	int i = 0;
	int len = 8;
	int length = 100000000;

	for (i = 0; i < strCount; i++) {
		newHash[i] = str[i];
	}

	for (i = 0; i < strCount; i++) {
		newHash[i] = (newHash[i] * seed * len * 48) + i;
	}

	for (i = 0; i < strCount; i++) {
		newHash[i] = (newHash[i] * seed * len) / (i + len);
		hash = (newHash[i] * len);
	}

	if (hash > 0 ) {
		return hash%length;
	} else {
		hash = (hash * (-len));
		return hash%length;
	}
}

void solution1(void) {

	char value[80];
	printf("Введите данные \n");
	scanf("%80s", value);
	printf("%i", makeHash(value));
	printf("\n");
}

// MARK: Задание 2. Переписать программу, реализующую двоичное дерево поиска.

FILE* file;

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

Node* CreateTree(int n) {
	Node* newNode;
	int x, nl, nr;
	if (n == 0) {
		newNode = NULL;
	} else {
		fscanf(file, "%d", &x);
		nl = n / 2;
		nr = n - nl - 1;
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = x;
		newNode->left = CreateTree(nl);
		newNode->right = CreateTree(nr);
	}
	return newNode;
}

Node* getFreeNode(int value, Node *parent) {
	Node* tmp = (Node*) malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

void insert(Node **head, int value) {
	Node *tmp = NULL;
	if (*head == NULL) {
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (value> tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			} else {
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value< tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			} else {
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		} else {
			exit(2);
		}
	}
}

void preOrderTravers(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void printTree(Node *root) {
	if (root) {
		printf("%d",root->data);
		if (root->left || root->right) {
			printf("(");

			if (root->left) {
				printTree(root->left);
			} else {
				printf("NULL");
			}
			printf(",");

			if (root->right) {
				printTree(root->right);
			} else {
				printf("NULL");
			}
			printf(")");
		}
	}
}

void symmetricTraversalPrint(Node* root) {
	if (root) {
		symmetricTraversalPrint(root->left);
		printf("%d ", root->data);
		symmetricTraversalPrint(root->right);
	}
}

void reversePrint(Node* root) {
	if (root) {
		reversePrint(root->left);
		reversePrint(root->right);
		printf("%d ", root->data);
	}
}

Node *getNodeByValue(Node *root, int value) {
	while (root) {
		if (CMP_GT(root->data, value)) {
			root = root->left;
			continue;
		} else if (CMP_LT(root->data, value)) {
			root = root->right;
			continue;
		} else {
			return root;
		}
	}
	return NULL;
}

void solution2(void) {

	Node *Tree = NULL;
	int searchValue = 0;
	FILE* file = fopen("/Users/andrejsekatunov/Desktop/GitHubs/-AlgorithmsAndDataStructuresHW_1/data.txt", "r");
	if (file == NULL) {
		puts("Can't open file!");
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count);
	int i;
	for(i = 0; i < count; i++) {
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\nPreOrderTravers:");
	preOrderTravers(Tree);
	printf("\n");
	symmetricTraversalPrint(Tree);
	printf("\n");
	reversePrint(Tree);
	printf("\n");
	printf("Укажите искомое значение: ");
	scanf("%i", &searchValue);
	if (getNodeByValue(Tree, searchValue) == NULL) {
		printf("Значение отсутствует");
	} else {
		printf("Успех, значение %i найдено ", searchValue);
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
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
