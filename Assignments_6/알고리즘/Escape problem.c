#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 큐를 나타내는 구조체
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

int** adjacency; // 인접 행렬
int n; // nxn 크기의 그리드

void initializeMatrix(int n);	// 인접 행렬 초기화 함수
void adjacencyMatrix(int n);	// nxn 그리드에 대한 인접 행렬을 생성하는 함수
void setSource(int n, int x, int y); // 출발지 노드와 입력한 좌표를 연결하는 함수
void setSink(int n);	// 목적지 노드와 nxn 그리드의 테두리의 좌표를 연결하는 함수
void freeMatrix(int n);	// 인접 행렬 해제 함수

struct Queue* createQueue(unsigned capacity);	// 주어진 용량으로 새 큐를 생성하는 함수
int isFull(struct Queue* queue);	// 큐가 가득 찼는지 확인하는 함수
int isEmpty(struct Queue* queue);	// 큐가 비어 있는지 확인하는 함수
void enqueue(struct Queue* queue, int item);	// 큐에 요소를 추가하는 함수
int dequeue(struct Queue* queue);	// 큐에서 요소를 제거하고 반환하는 함수

int fordFulkerson(int source, int sink); // Ford-Fulkerson 알고리즘 구현 함수
void drawMatrix(int n, int path[], int path_length); // 탈출 경로를 그래픽으로 구현하는 함수

int main() {
	int r;		// 탈출을 위한 정점의 수를 나타내는 변수
	int i = 0;	// r개의 정점을 입력했는지 확인하는 변수

	// n 입력
	printf("정수 n을 입력하세요: ");
	scanf("%d", &n);

	initializeMatrix(n);	// 인접 행렬 초기화 함수 호출

	adjacencyMatrix(n);		// nxn 그리드에 대한 인접 행렬을 생성하는 함수 호출

	// r 입력
	do {
		printf("정수 r을 입력하세요: ");
		scanf("%d", &r);

		if (r >= n * n) {
			printf("다시 입력하세요. %d보다 작아야 합니다.\n", n * n);
		}
	} while (r >= n * n);

	// 탈출을 위한 정점들의 좌표 입력
	printf("\n**좌측 하단의 점을 (1, 1)이라고 하고 우측 상단의 좌표가 (%d, %d)이 됨**\n", n, n);
	do {
		int x, y;

		printf("정수 x와 y를 입력하세요 (각각 %d보다 작거나 같아야 합니다): ", n);
		scanf("%d %d", &x, &y);

		if (x <= n && y <= n) {
			setSource(n, x, y); // 출발지 노드를 작성한 좌표와 연결
			i++;
		}
		else {
			printf("다시 입력하세요. 각각 %d보다 작거나 같아야 합니다.\n", n);
		}
	} while (i < r);

	setSink(n); // 목적지 노드를 nxn 그리드의 테두리 좌표와 연결

	int max_flow = fordFulkerson(0, n * n + 1, n * n + 2); // Ford-Fulkerson 알고리즘 구현 함수 호출

	if (r == max_flow)	// 입력한 정점의 개수와 최대 유량 값이 같다면
		printf("\n[탈출 가능]\n");
	else				// 입력한 정점의 개수와 최대 유량 값이 다르다면
		printf("\n[탈출 불가능]\n");

	freeMatrix(n); // 인접 행렬 해제 함수 호출

	return 0;
}

// 인접 행렬 초기화 함수
void initializeMatrix(int n) {
	adjacency = (int**)malloc((n * n + 2) * sizeof(int*));
	for (int i = 0; i < (n * n + 2); i++) {
		adjacency[i] = (int*)malloc((n * n + 2) * sizeof(int));
		for (int j = 0; j < (n * n + 2); j++) {
			adjacency[i][j] = 0;
		}
	}
}

// nxn 그리드에 대한 인접 행렬을 생성하는 함수
void adjacencyMatrix(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 용량이 1
			if (i > 0) adjacency[i * n + j + 1][(i - 1) * n + j + 1] = 1;       // 상
			if (i < n - 1) adjacency[i * n + j + 1][(i + 1) * n + j + 1] = 1;   // 하
			if (j > 0) adjacency[i * n + j + 1][i * n + (j - 1) + 1] = 1;       // 좌
			if (j < n - 1) adjacency[i * n + j + 1][i * n + (j + 1) + 1] = 1;   // 우
		}
	}
}

// 출발지 노드와 입력한 좌표를 연결하는 함수(네트워크 플로우로 변환 과정)
void setSource(int n, int x, int y) {
	// 용량이 1
	adjacency[0][y + n * (n - x)] = 1;
	adjacency[y + n * (n - x)][0] = 1;
}

// 목적지 노드와 nxn 그리드의 테두리의 좌표를 연결하는 함수(네트워크 플로우로 변환 과정)
void setSink(int n) {
	for (int i = 1; i <= n; i++) {
		// 용량이 1
		adjacency[n * n + 1][i] = 1;
		adjacency[i][n * n + 1] = 1;
	}

	for (int j = 1; j < n - 1; j++) {
		// 용량이 1
		adjacency[n * n + 1][1 + j * n] = 1;
		adjacency[1 + j * n][n * n + 1] = 1;
		adjacency[n * n + 1][n + j * n] = 1;
		adjacency[n + j * n][n * n + 1] = 1;
	}

	for (int i = n * n - 3; i <= n * n; i++) {
		// 용량이 1
		adjacency[n * n + 1][i] = 1;
		adjacency[i][n * n + 1] = 1;
	}
}

// 인접 행렬 해제 함수
void freeMatrix(int n) {
	for (int i = 0; i < n * n + 2; i++) {
		free(adjacency[i]);
	}
	free(adjacency);
}

// 주어진 용량으로 새 큐를 생성하는 함수
struct Queue* createQueue(unsigned capacity) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// 큐가 가득 찼는지 확인하는 함수
int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// 큐가 비어 있는지 확인하는 함수
int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// 큐에 요소를 추가하는 함수
void enqueue(struct Queue* queue, int item) {
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

// 큐에서 요소를 제거하고 반환하는 함수
int dequeue(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Ford-Fulkerson 알고리즘 구현 함수
int fordFulkerson(int source, int sink) {
	int u, v;
	int cnt = 1; // 탈출 경로 개수를 카운트하는 변수
	int max_flow = 0; // 최대 유량 값을 저장하는 변수

	// 경로를 저장할 배열 동적 할당
	int* path = (int*)malloc((n * n + 2) * sizeof(int));

	// 잔여 그래프를 표현할 2차원 배열 동적 할당
	int** rGraph = (int**)malloc((n * n + 2) * sizeof(int*));
	for (u = 0; u < (n * n + 2); u++) {
		rGraph[u] = (int*)malloc((n * n + 2) * sizeof(int));
		for (v = 0; v < (n * n + 2); v++)
			rGraph[u][v] = adjacency[u][v];
	}

	// 부모 노드를 저장할 배열 동적 할당
	int* parent = (int*)malloc((n * n + 2) * sizeof(int));

	// 방문 여부를 나타내는 배열 동적 할당 및 초기화
	int* visited = (int*)malloc((n * n + 2) * sizeof(int));
	for (int i = 0; i < (n * n + 2); i++) {
		visited[i] = 0;
	}

	// Ford-Fulkerson 알고리즘
	while (1) {
		// BFS를 위한 초기화
		for (int i = 0; i < (n * n + 2); i++) {
			parent[i] = -1;
		}
		struct Queue* queue = createQueue((n * n + 2));
		enqueue(queue, source);
		parent[source] = source;

		// BFS 수행
		while (!isEmpty(queue)) {
			u = dequeue(queue);

			for (v = 0; v < (n * n + 2); v++) {
				if (parent[v] == -1 && rGraph[u][v] > 0 && !visited[v]) {
					enqueue(queue, v);
					parent[v] = u;
				}
			}
		}
		free(queue);

		// BFS 결과로 경로를 찾은 경우
		if (parent[sink] == -1)
			break;

		// 찾은 경로에서 최소 유량을 찾음
		int path_flow = INT_MAX;
		for (v = sink; v != source; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// 찾은 경로에 최소 유량을 더하고 빼줌
		for (v = sink; v != source; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;

		// 경로를 저장
		int path_length = 0;
		path[path_length++] = sink;
		for (v = parent[sink]; v != source; v = parent[v]) {
			path[path_length++] = v;
			visited[v] = 1;
		}
		path[path_length++] = source;

		// 경로를 출력
		printf("\n%d번째 경로 : %d", cnt, source);
		for (int i = path_length - 2; i >= 0; i--) {
			printf(" -> %d", path[i]);
		}
		printf("\n");

		cnt++;

		drawMatrix(n, path, path_length); // 탈출 경로를 그래픽으로 구현하는 함수 호출
	}

	// 동적 할당된 메모리 해제
	for (u = 0; u < (n * n + 2); u++)
		free(rGraph[u]);
	free(rGraph);
	free(parent);
	free(visited);

	return max_flow; // 최대 유량 반환
}

// 탈출 경로를 그래픽으로 구현하는 함수
void drawMatrix(int n, int path[], int path_length) {
	int k, i;
	int x, y;

	// 경로를 나타내는 2차원 배열 동적 할당
	char** result = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		result[i] = (char*)malloc(n * sizeof(char));
	}

	// 경로를 나타내는 행렬 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = 'O';
		}
	}

	// 경로를 표시
	for (i = 1; i < path_length - 1; i++) {
		k = path[i];
		x = (k - 1) / n;
		y = ((k - 1) % n);
		if (i == path_length - 2)
			result[x][y] = '$'; // 탈출을 위한 정점
		else
			result[x][y] = '@'; // 이동 경로 표시
	}

	// 경로를 나타내는 행렬 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", result[i][j]);
		}
		printf("\n");
	}

	// 동적 할당된 메모리 해제
	for (int i = 0; i < n; i++)
		free(result[i]);
	free(result);
}