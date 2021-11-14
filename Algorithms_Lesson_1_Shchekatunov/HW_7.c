//
//  HW_7.c
//  Algorithms_Lesson_1_Shchekatunov
//
//  Created by Андрей Щекатунов on 12.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define SIZE 40

void menu(void) {
	printf("1 - Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.\n");
	printf("2 - Написать рекурсивную функцию обхода графа в глубину.\n");
	printf("3 - Написать функцию обхода графа в ширину.\n");

	printf("0 - Выход.\n");
}

// MARK: Задание 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.

const char* fileName = "/Users/andrejsekatunov/Desktop/GitHubs/-AlgorithmsAndDataStructuresHW_1/matrix.txt";

int G[MAX][MAX], n;

void printMatrix(int G[MAX][MAX]) {
	printf("%s", "     ");
	for (int i = 0; i < n; i++) {
		printf("%c(%d) ", 65 + i, i);
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%c(%d)", 65 + i, i);
		for (int j = 0; j < n; j++) {
			printf("%5d", G[i][j]);
		}
		printf("\n");
	}
}

void solution1(void) {

	int i, j;
	printf("Enter no. of vert \n");
	scanf("%d", &n);

	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Cant't open file");
		exit(1);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++ ) {
			fscanf(file, "%d", &G[i][j]);
		}
	}
	fclose(file);

	printf("Graph matrix: \n");
	printMatrix(G);
}

// MARK: Задание 3. Написать функцию обхода графа в ширину.

int GraphArray[MAX][MAX], point;

typedef struct QNode {
	int vertex;
	struct QNode *next;
} QNode;

typedef struct Queue {
	int items[SIZE];
	struct QNode *front;
	struct QNode *rear;
} Queue;

typedef struct Graph {
	int numVertices;
	struct QNode** adjLists;
	int* visited;
}Graph;

QNode* newNode(int k) {
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->vertex = k;
	temp->next = NULL;
	return temp;
}

Queue* createQueue(void) {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void addTooQueue(Queue* q, int k) {
	QNode* temp = newNode(k);

	if (q->rear == NULL) {

		q->front = temp;
		q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(Queue *q) {
	if (q->front == NULL) {
		return;
	}

	QNode* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(temp);
}

int deQueuePopFront(Queue *q) {
	if (q->front == NULL) {
		return 0;
	}

	QNode* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
		return 0;
	}
	free(temp);
	return temp->vertex;
}

int isEmpty(Queue* q) {
	if(q->rear == -1)
		return 1;
	else
		return 0;
}

void printQueue(Queue *q) {
	int i = q->front;
	if(isEmpty(q)) {
		printf("Queue is empty");
	} else {
		printf("\nQueue contains \n");
		for(i = q->front; i < q->rear + 1; i++) {
				printf("%d ", q->items[i]);
		}
	}
}

void bfs(Graph* graph, int startVertex) {
	Queue* q = createQueue();

	graph->visited[startVertex] = 1;
	addTooQueue(q, startVertex);

	while(!isEmpty(q)){
		printQueue(q);
		int currentVertex = deQueuePopFront(q);
		printf("Visited %d\n", currentVertex);

	   struct node* temp = graph->adjLists[currentVertex];

	   while(temp) {
			int adjVertex = temp->vertex;
			if(graph->visited[adjVertex] == 0){
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
	   }
	}
}

Graph* createGraph(int vertices) {
	Graph* graph = malloc(sizeof(Graph));
	graph->numVertices = vertices;

	graph->adjLists = malloc(vertices * sizeof(QNode*));
	graph->visited = malloc(vertices * sizeof(int));

	int i;
	for (i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}

void addEdge(Graph* graph, int src, int dest) {
	QNode* node = newNode(dest);
	node->next = graph->adjLists[src];
	graph->adjLists[src] = node;

	node = newNode(src);
	node->next = graph->adjLists[dest];
	graph->adjLists[dest] = node;
}


void solution3(void) {

	int i, j;
	printf("Enter no. of vert \n");
	scanf("%d", &point);

	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Cant't open file");
		exit(1);
	}
	for (i = 0; i < point; i++) {
		for (j = 0; j < point; j++ ) {
			fscanf(file, "%d", &G[i][j]);
		}
	}
	fclose(file);

	printf("Graph matrix: \n");
	printMatrix(G);

	int graphVisitArr[point];
	int currentPeak;
	Queue* q = createQueue();

	for (i = 0; i < point; i++) {
		graphVisitArr[i] = 1;
	}
	graphVisitArr[0] = 2;
	addTooQueue(q, 0);
	addTooQueue(q, 1);
	addTooQueue(q, 3);
	currentPeak = deQueuePopFront(q);
	printf("Queue pop %d \n", currentPeak);
	printf("Queue front %d \n", q->front->vertex);
	printf("Queue rear %d \n", q->rear->vertex);

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
			case 3:
				solution3();
				break;
			default:
				break;
		}
	} while (sel != 0);
	return 0;
}
