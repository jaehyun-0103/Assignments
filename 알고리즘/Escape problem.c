#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ť�� ��Ÿ���� ����ü
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

int** adjacency; // ���� ���
int n; // nxn ũ���� �׸���

void initializeMatrix(int n);	// ���� ��� �ʱ�ȭ �Լ�
void adjacencyMatrix(int n);	// nxn �׸��忡 ���� ���� ����� �����ϴ� �Լ�
void setSource(int n, int x, int y); // ����� ���� �Է��� ��ǥ�� �����ϴ� �Լ�
void setSink(int n);	// ������ ���� nxn �׸����� �׵θ��� ��ǥ�� �����ϴ� �Լ�
void freeMatrix(int n);	// ���� ��� ���� �Լ�

struct Queue* createQueue(unsigned capacity);	// �־��� �뷮���� �� ť�� �����ϴ� �Լ�
int isFull(struct Queue* queue);	// ť�� ���� á���� Ȯ���ϴ� �Լ�
int isEmpty(struct Queue* queue);	// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
void enqueue(struct Queue* queue, int item);	// ť�� ��Ҹ� �߰��ϴ� �Լ�
int dequeue(struct Queue* queue);	// ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�

int fordFulkerson(int source, int sink); // Ford-Fulkerson �˰��� ���� �Լ�
void drawMatrix(int n, int path[], int path_length); // Ż�� ��θ� �׷������� �����ϴ� �Լ�

int main() {
	int r;		// Ż���� ���� ������ ���� ��Ÿ���� ����
	int i = 0;	// r���� ������ �Է��ߴ��� Ȯ���ϴ� ����

	// n �Է�
	printf("���� n�� �Է��ϼ���: ");
	scanf("%d", &n);

	initializeMatrix(n);	// ���� ��� �ʱ�ȭ �Լ� ȣ��

	adjacencyMatrix(n);		// nxn �׸��忡 ���� ���� ����� �����ϴ� �Լ� ȣ��

	// r �Է�
	do {
		printf("���� r�� �Է��ϼ���: ");
		scanf("%d", &r);

		if (r >= n * n) {
			printf("�ٽ� �Է��ϼ���. %d���� �۾ƾ� �մϴ�.\n", n * n);
		}
	} while (r >= n * n);

	// Ż���� ���� �������� ��ǥ �Է�
	printf("\n**���� �ϴ��� ���� (1, 1)�̶�� �ϰ� ���� ����� ��ǥ�� (%d, %d)�� ��**\n", n, n);
	do {
		int x, y;

		printf("���� x�� y�� �Է��ϼ��� (���� %d���� �۰ų� ���ƾ� �մϴ�): ", n);
		scanf("%d %d", &x, &y);

		if (x <= n && y <= n) {
			setSource(n, x, y); // ����� ��带 �ۼ��� ��ǥ�� ����
			i++;
		}
		else {
			printf("�ٽ� �Է��ϼ���. ���� %d���� �۰ų� ���ƾ� �մϴ�.\n", n);
		}
	} while (i < r);

	setSink(n); // ������ ��带 nxn �׸����� �׵θ� ��ǥ�� ����

	int max_flow = fordFulkerson(0, n * n + 1, n * n + 2); // Ford-Fulkerson �˰��� ���� �Լ� ȣ��

	if (r == max_flow)	// �Է��� ������ ������ �ִ� ���� ���� ���ٸ�
		printf("\n[Ż�� ����]\n");
	else				// �Է��� ������ ������ �ִ� ���� ���� �ٸ��ٸ�
		printf("\n[Ż�� �Ұ���]\n");

	freeMatrix(n); // ���� ��� ���� �Լ� ȣ��

	return 0;
}

// ���� ��� �ʱ�ȭ �Լ�
void initializeMatrix(int n) {
	adjacency = (int**)malloc((n * n + 2) * sizeof(int*));
	for (int i = 0; i < (n * n + 2); i++) {
		adjacency[i] = (int*)malloc((n * n + 2) * sizeof(int));
		for (int j = 0; j < (n * n + 2); j++) {
			adjacency[i][j] = 0;
		}
	}
}

// nxn �׸��忡 ���� ���� ����� �����ϴ� �Լ�
void adjacencyMatrix(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// �뷮�� 1
			if (i > 0) adjacency[i * n + j + 1][(i - 1) * n + j + 1] = 1;       // ��
			if (i < n - 1) adjacency[i * n + j + 1][(i + 1) * n + j + 1] = 1;   // ��
			if (j > 0) adjacency[i * n + j + 1][i * n + (j - 1) + 1] = 1;       // ��
			if (j < n - 1) adjacency[i * n + j + 1][i * n + (j + 1) + 1] = 1;   // ��
		}
	}
}

// ����� ���� �Է��� ��ǥ�� �����ϴ� �Լ�(��Ʈ��ũ �÷ο�� ��ȯ ����)
void setSource(int n, int x, int y) {
	// �뷮�� 1
	adjacency[0][y + n * (n - x)] = 1;
	adjacency[y + n * (n - x)][0] = 1;
}

// ������ ���� nxn �׸����� �׵θ��� ��ǥ�� �����ϴ� �Լ�(��Ʈ��ũ �÷ο�� ��ȯ ����)
void setSink(int n) {
	for (int i = 1; i <= n; i++) {
		// �뷮�� 1
		adjacency[n * n + 1][i] = 1;
		adjacency[i][n * n + 1] = 1;
	}

	for (int j = 1; j < n - 1; j++) {
		// �뷮�� 1
		adjacency[n * n + 1][1 + j * n] = 1;
		adjacency[1 + j * n][n * n + 1] = 1;
		adjacency[n * n + 1][n + j * n] = 1;
		adjacency[n + j * n][n * n + 1] = 1;
	}

	for (int i = n * n - 3; i <= n * n; i++) {
		// �뷮�� 1
		adjacency[n * n + 1][i] = 1;
		adjacency[i][n * n + 1] = 1;
	}
}

// ���� ��� ���� �Լ�
void freeMatrix(int n) {
	for (int i = 0; i < n * n + 2; i++) {
		free(adjacency[i]);
	}
	free(adjacency);
}

// �־��� �뷮���� �� ť�� �����ϴ� �Լ�
struct Queue* createQueue(unsigned capacity) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// ť�� ��� �ִ��� Ȯ���ϴ� �Լ�
int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// ť�� ��Ҹ� �߰��ϴ� �Լ�
void enqueue(struct Queue* queue, int item) {
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

// ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int dequeue(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Ford-Fulkerson �˰��� ���� �Լ�
int fordFulkerson(int source, int sink) {
	int u, v;
	int cnt = 1; // Ż�� ��� ������ ī��Ʈ�ϴ� ����
	int max_flow = 0; // �ִ� ���� ���� �����ϴ� ����

	// ��θ� ������ �迭 ���� �Ҵ�
	int* path = (int*)malloc((n * n + 2) * sizeof(int));

	// �ܿ� �׷����� ǥ���� 2���� �迭 ���� �Ҵ�
	int** rGraph = (int**)malloc((n * n + 2) * sizeof(int*));
	for (u = 0; u < (n * n + 2); u++) {
		rGraph[u] = (int*)malloc((n * n + 2) * sizeof(int));
		for (v = 0; v < (n * n + 2); v++)
			rGraph[u][v] = adjacency[u][v];
	}

	// �θ� ��带 ������ �迭 ���� �Ҵ�
	int* parent = (int*)malloc((n * n + 2) * sizeof(int));

	// �湮 ���θ� ��Ÿ���� �迭 ���� �Ҵ� �� �ʱ�ȭ
	int* visited = (int*)malloc((n * n + 2) * sizeof(int));
	for (int i = 0; i < (n * n + 2); i++) {
		visited[i] = 0;
	}

	// Ford-Fulkerson �˰���
	while (1) {
		// BFS�� ���� �ʱ�ȭ
		for (int i = 0; i < (n * n + 2); i++) {
			parent[i] = -1;
		}
		struct Queue* queue = createQueue((n * n + 2));
		enqueue(queue, source);
		parent[source] = source;

		// BFS ����
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

		// BFS ����� ��θ� ã�� ���
		if (parent[sink] == -1)
			break;

		// ã�� ��ο��� �ּ� ������ ã��
		int path_flow = INT_MAX;
		for (v = sink; v != source; v = parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// ã�� ��ο� �ּ� ������ ���ϰ� ����
		for (v = sink; v != source; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;

		// ��θ� ����
		int path_length = 0;
		path[path_length++] = sink;
		for (v = parent[sink]; v != source; v = parent[v]) {
			path[path_length++] = v;
			visited[v] = 1;
		}
		path[path_length++] = source;

		// ��θ� ���
		printf("\n%d��° ��� : %d", cnt, source);
		for (int i = path_length - 2; i >= 0; i--) {
			printf(" -> %d", path[i]);
		}
		printf("\n");

		cnt++;

		drawMatrix(n, path, path_length); // Ż�� ��θ� �׷������� �����ϴ� �Լ� ȣ��
	}

	// ���� �Ҵ�� �޸� ����
	for (u = 0; u < (n * n + 2); u++)
		free(rGraph[u]);
	free(rGraph);
	free(parent);
	free(visited);

	return max_flow; // �ִ� ���� ��ȯ
}

// Ż�� ��θ� �׷������� �����ϴ� �Լ�
void drawMatrix(int n, int path[], int path_length) {
	int k, i;
	int x, y;

	// ��θ� ��Ÿ���� 2���� �迭 ���� �Ҵ�
	char** result = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		result[i] = (char*)malloc(n * sizeof(char));
	}

	// ��θ� ��Ÿ���� ��� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = 'O';
		}
	}

	// ��θ� ǥ��
	for (i = 1; i < path_length - 1; i++) {
		k = path[i];
		x = (k - 1) / n;
		y = ((k - 1) % n);
		if (i == path_length - 2)
			result[x][y] = '$'; // Ż���� ���� ����
		else
			result[x][y] = '@'; // �̵� ��� ǥ��
	}

	// ��θ� ��Ÿ���� ��� ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", result[i][j]);
		}
		printf("\n");
	}

	// ���� �Ҵ�� �޸� ����
	for (int i = 0; i < n; i++)
		free(result[i]);
	free(result);
}