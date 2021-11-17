//
//  HW_7.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 12.11.2021.
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX 20
//#define SIZE 40
//
//void menu(void) {
//	printf("1 - Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.\n");
//	printf("2 - Написать рекурсивную функцию обхода графа в глубину.\n");
//	printf("3 - Написать функцию обхода графа в ширину.\n");
//
//	printf("0 - Выход.\n");
//}
//
//// MARK: Задание 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
//
//const char* fileName = "/Users/andrejsekatunov/Desktop/GitHubs/-AlgorithmsAndDataStructuresHW_1/matrix.txt";
//
//int G[MAX][MAX], n;
//
//void printMatrix(int G[MAX][MAX]) {
//	printf("%s", "     ");
//	for (int i = 0; i < n; i++) {
//		printf("%c(%d) ", 65 + i, i);
//	}
//	printf("\n");
//	for (int i = 0; i < n; i++) {
//		printf("%c(%d)", 65 + i, i);
//		for (int j = 0; j < n; j++) {
//			printf("%5d", G[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//void solution1(void) {
//
//	int i, j;
//	printf("Enter no. of vert \n");
//	scanf("%d", &n);
//
//	FILE* file = fopen(fileName, "r");
//	if (file == NULL) {
//		printf("Cant't open file");
//		exit(1);
//	}
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++ ) {
//			fscanf(file, "%d", &G[i][j]);
//		}
//	}
//	fclose(file);
//
//	printf("Graph matrix: \n");
//	printMatrix(G);
//}
//
//// MARK: Задание 2. Написать рекурсивную функцию обхода графа в глубину
//
//int GraphArrayForDepth[MAX][MAX], pointForDepth;
//
//const char* fileNameSecond = "/Users/andrejsekatunov/Desktop/GitHubs/-AlgorithmsAndDataStructuresHW_1/matrixSecond.txt";
//
//void printMatrixFromGraphArrayForDepth(int GraphArrayForDepth[MAX][MAX]) {
//	printf("%s", "     ");
//	for (int i = 0; i < pointForDepth; i++) {
//		printf("%c(%d) ", 65 + i, i);
//	}
//	printf("\n");
//	for (int i = 0; i < pointForDepth; i++) {
//		printf("%c(%d)", 65 + i, i);
//		for (int j = 0; j < pointForDepth; j++) {
//			printf("%5d", GraphArrayForDepth[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//typedef struct nodeForDepth {
//	int vertex;
//	struct nodeForDepth* next;
//} nodeForDepth;
//
//typedef struct GraphForDepth {
//	int numVertices;
//	int* visited;
//	nodeForDepth** adjLists;
//} GraphForDepth;
//
//nodeForDepth* createNodeForDepth(int v) {
//	nodeForDepth* newNode = malloc(sizeof(nodeForDepth));
//	newNode->vertex = v;
//	newNode->next = NULL;
//	return newNode;
//}
//
//GraphForDepth* createGraphForDepth(int vertices) {
//
//	GraphForDepth* graph = malloc(sizeof(GraphForDepth));
//	graph->numVertices = vertices;
//
//	graph->adjLists = malloc(vertices * sizeof(nodeForDepth*));
//
//	graph->visited = malloc(vertices * sizeof(int));
//
//	for (int i = 0; i < vertices; i++) {
//		graph->adjLists[i] = NULL;
//		graph->visited[i] = 0;
//	}
//	return graph;
//}
//
//void addEdgeForDepth(GraphForDepth* graph, int src, int dest) {
//
//	nodeForDepth* newNode = createNodeForDepth(dest);
//	newNode->next = graph->adjLists[src];
//	graph->adjLists[src] = newNode;
//
//	newNode = createNodeForDepth(src);
//	newNode->next = graph->adjLists[dest];
//	graph->adjLists[dest] = newNode;
//}
//
//void printGraphForDepth(GraphForDepth* graph) {
//
//	for (int v = 0; v < graph->numVertices; v++) {
//		nodeForDepth* temp = graph->adjLists[v];
//		printf("\n Вершина: %d\n ", v);
//		while (temp) {
//			printf("%d -> ", temp->vertex);
//			temp = temp->next;
//		}
//		printf("\n");
//	}
//}
//
//void DFS(GraphForDepth* graph, int vertex) {
//	nodeForDepth* adjList = graph->adjLists[vertex];
//	nodeForDepth* temp = adjList;
//
//	graph->visited[vertex] = 1;
//	printf("Посещено %d \n", vertex);
//
//	while(temp!=NULL) {
//		int connectedVertex = temp->vertex;
//
//		if(graph->visited[connectedVertex] == 0) {
//			DFS(graph, connectedVertex);
//		}
//		temp = temp->next;
//	}
//}
//
//
//void solution2(void) {
//
//	printf("Enter no. of vert \n");
//	scanf("%d", &pointForDepth);
//
//	FILE* file = fopen(fileNameSecond, "r");
//	if (file == NULL) {
//		printf("Cant't open file");
//		exit(1);
//	}
//	for (int i = 0; i < pointForDepth; i++) {
//		for (int j = 0; j < pointForDepth; j++ ) {
//			fscanf(file, "%d", &GraphArrayForDepth[i][j]);
//		}
//	}
//	fclose(file);
//
//	printf("Graph matrix: \n");
//	printMatrixFromGraphArrayForDepth(GraphArrayForDepth);
//
//	GraphForDepth* graph = createGraphForDepth(pointForDepth);
//
//	for (int i = 0; i < pointForDepth; i++) {
//		for (int j = 0; j < pointForDepth; j++ ) {
//			if (GraphArrayForDepth[i][j] == 1) {
//				addEdgeForDepth(graph, i, j);
//				printf("i - %i, j - %i \n", i, j);
//			}
//		}
//	}
//
//	printGraphForDepth(graph);
//
//	DFS(graph, pointForDepth);
//}
//
//// MARK: Задание 3. Написать функцию обхода графа в ширину.
//
//int GraphArray[MAX][MAX], point;
//
//void printMatrixFromGraphArray(int GraphArray[MAX][MAX]) {
//	printf("%s", "     ");
//	for (int i = 0; i < point; i++) {
//		printf("%c(%d) ", 65 + i, i);
//	}
//	printf("\n");
//	for (int i = 0; i < point; i++) {
//		printf("%c(%d)", 65 + i, i);
//		for (int j = 0; j < point; j++) {
//			printf("%5d", GraphArray[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//typedef struct QNodeForWidth {
//	int vertex;
//	struct QNodeForWidth *next;
//} QNodeForWidth;
//
//typedef struct QueueForWidth {
//	int items[SIZE];
//	int front;
//	int rear;
//} QueueForWidth;
//
//typedef struct GraphForWidth {
//	int numVertices;
//	QNodeForWidth** adjLists;
//	int* visited;
//}GraphForWidth;
//
//QNodeForWidth* newNode(int k) {
//	QNodeForWidth* temp = (QNodeForWidth*)malloc(sizeof(QNodeForWidth));
//	temp->vertex = k;
//	temp->next = NULL;
//	return temp;
//}
//QueueForWidth* createQueue(void) {
//	QueueForWidth* q = malloc(sizeof(QueueForWidth));
//	q->front = -1;
//	q->rear = -1;
//	return q;
//}
//
//void enqueue(QueueForWidth* q, int value){
//	if(q->rear == SIZE-1)
//		printf("\nQueue is Full!!");
//	else {
//		if(q->front == -1)
//			q->front = 0;
//		q->rear++;
//		q->items[q->rear] = value;
//	}
//}
//
//int isEmpty(QueueForWidth* q) {
//	if (q->rear == -1) {
//		return 1;
//	} else {
//		return 0;
//	}
//}
//
//void printQueue(QueueForWidth *q) {
//	int i = q->front;
//	if(isEmpty(q)) {
//		printf("Queue is empty");
//	} else {
//		printf("\nQueue contains \n");
//		for(i = q->front; i < q->rear + 1; i++) {
//			printf("%d ", q->items[i]);
//		}
//	}
//}
//
//int dequeue(QueueForWidth* q){
//	int item;
//	if(isEmpty(q)){
//		printf("Queue is empty");
//		item = -1;
//	}
//	else{
//		item = q->items[q->front];
//		q->front++;
//		if(q->front > q->rear){
//			printf("Resetting queue");
//			q->front = q->rear = -1;
//		}
//	}
//	return item;
//}
//
//void wave(GraphForWidth* graph, int startVertex) {
//	QueueForWidth* q = createQueue();
//
//	graph->visited[startVertex] = 1;
//	enqueue(q, startVertex);
//
//	while(!isEmpty(q)){
//		printQueue(q);
//		int currentVertex = dequeue(q);
//		printf("Visited %d\n", currentVertex);
//
//		QNodeForWidth* temp = graph->adjLists[currentVertex];
//
//		while(temp) {
//			int adjVertex = temp->vertex;
//			if(graph->visited[adjVertex] == 0){
//				graph->visited[adjVertex] = 1;
//				enqueue(q, adjVertex);
//			}
//			temp = temp->next;
//		}
//	}
//}
//
//GraphForWidth* createGraph(int vertices) {
//	GraphForWidth* graph = malloc(sizeof(GraphForWidth));
//	graph->numVertices = vertices;
//
//	graph->adjLists = malloc(vertices * sizeof(QNodeForWidth*));
//	graph->visited = malloc(vertices * sizeof(int));
//
//	for (int i = 0; i < vertices; i++) {
//		graph->adjLists[i] = NULL;
//		graph->visited[i] = 0;
//	}
//
//	return graph;
//}
//
//void addEdge(GraphForWidth* graph, int src, int dest) {
//	QNodeForWidth* node = newNode(dest);
//	node->next = graph->adjLists[src];
//	graph->adjLists[src] = node;
//
//	node = newNode(src);
//	node->next = graph->adjLists[dest];
//	graph->adjLists[dest] = node;
//}
//
//
//void solution3(void) {
//
//	printf("Enter no. of vert \n");
//	scanf("%d", &point);
//
//	FILE* file = fopen(fileNameSecond, "r");
//	if (file == NULL) {
//		printf("Cant't open file");
//		exit(1);
//	}
//	for (int i = 0; i < point; i++) {
//		for (int j = 0; j < point; j++ ) {
//			fscanf(file, "%d", &GraphArray[i][j]);
//		}
//	}
//	fclose(file);
//
//	printf("Graph matrix: \n");
//	printMatrixFromGraphArray(GraphArray);
//
//	GraphForWidth* graph = createGraph(point);
//
//	for (int i = 0; i < point; i++) {
//		for (int j = 0; j < point; j++ ) {
//			if (GraphArray[i][j] == 1) {
//				addEdge(graph, i, j);
//				printf("i - %i, j - %i \n", i, j);
//			}
//		}
//	}
//
//	wave(graph, 0);
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
