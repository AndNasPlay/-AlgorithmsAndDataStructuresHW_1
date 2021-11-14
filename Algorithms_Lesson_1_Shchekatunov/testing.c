//
//  testing.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 14.11.2021.
//

//const char* fileNameSecond = "/Users/andrejsekatunov/Desktop/GitHubs/-AlgorithmsAndDataStructuresHW_1/matrixSecond.txt";
//int GraphArray[MAX][MAX], z;
//
//void printMatrixSecond(int GraphArray[MAX][MAX]) {
//	printf("%s", "     ");
//	for (int i = 0; i < z; i++) {
//		printf("%c(%d) ", 65 + i, i);
//	}
//	printf("\n");
//	for (int i = 0; i < z; i++) {
//		printf("%c(%d)", 65 + i, i);
//		for (int j = 0; j < z; j++) {
//			printf("%5d", GraphArray[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//typedef struct List {
//	int value;
//	int visit;
//	struct List *next;
//} List;
//
//typedef struct Queue {
//	List *front, *end;
//} Queue;
//
//void initQueue(Queue *q) {
//	q->front = 0;
//	q->end = 0;
//}
//
//List* init(int a) {
//	List *lst;
//	lst = (List*)malloc(sizeof(List));
//	lst->value = a;
//	lst->next = NULL;
//	return(lst);
//}
//
//int isempty(Queue *q) {
//	if(q->front == 0)
//		return 1;
//	else
//		return 0;
//}
//
//List* addelem(List *lst, int number) {
//	List *temp, *p;
//	temp = (List*)malloc(sizeof(List));
//	p = lst->next;
//	lst->next = temp;
//	temp->value = number;
//	temp->next = p;
//	temp->visit = 0;
//	return(temp);
//}
//
//List* deletelem(List *lst, List *root) {
//	List *temp;
//	temp = root;
//	while (temp->next != lst) // просматриваем список начиная с корня
//	{ // пока не найдем узел, предшествующий lst
//		temp = temp->next;
//	}
//	temp->next = lst->next; // переставляем указатель
//	free(lst); // освобождаем память удаляемого узла
//	return(temp);
//}
//
//void insert(Queue *q, int x) {
//	if((q->end == 0) && (q->front == 0)) {
//		q->end = init(x);
//		q->front = q->end;
//	} else {
//		q->end = addelem(q->end, x);
//	}
//}
//
//void print(Queue *q) {
//	List *h;
//	if(isempty(q)==1) {
//		printf("Очередь пуста!\n");
//		return;
//	}
//	for(h = q->front; h!= NULL; h=h->next)
//		printf("%d ",h->value);
//	return;
//}
//
//int removeFromQueue(Queue *q) {
//	List *temp;
//	int x;
//	if(isempty(q)==1) {
//		printf("Очередь пуста!\n");
//		return 0;
//	}
//	x = q->front->next;
//	temp = q->front;
//	q->front = q->front->next;
//	free(temp);
//	return x;
//}
//
//void solution2(void) {
//
//	int i, j;
//
//	printf("Enter no. of vert \n");
//	scanf("%d", &z);
//
//	int graphVisitArr[z];
//
//	FILE* file = fopen(fileNameSecond, "r");
//
//	if (file == NULL) {
//		printf("Cant't open file");
//		exit(1);
//	}
//
//	for (i = 0; i < z; i++) {
//		for (j = 0; j < z; j++ ) {
//			fscanf(file, "%d", &GraphArray[i][j]);
//		}
//	}
//	fclose(file);
//
//	for (i = 0; i < z; i++) {
//		graphVisitArr[i] = 0;
//	}
//
//	Queue *q = (Queue*)malloc(sizeof(Queue));
//	List *list = (List*)malloc(sizeof(List));
//	init(q);
//
//	print(q);
//	list = init(GraphArray[0][0]);
//
//	for (i = 0; i < z; i++) {
//		for (j = 1; j < z; j++ ) {
//			addelem(list, GraphArray[i][j]);
//		}
//	}
//
//	for (i = 0; i < z; i++) {
//		printf("%i", list->value);
//		deletelem(list, list->value);
//	}
//
//	printf("\n");
//	print(q);
//	printf("\n");
//	printf("Graph matrix: \n");
//	printMatrixSecond(GraphArray);
//
//}
