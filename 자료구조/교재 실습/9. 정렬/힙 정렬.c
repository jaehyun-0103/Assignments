#include <stdio.h>
# define MAX_SIZE 10

// �� ����
void heap_sort(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int child = i;
		do {
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);
	}
}

// �ֻ�� ���� ���ϴ� ��� ��ü
void heap(int* arr, int* size) {
	int temp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = temp;
	--(*size);
}

int main() {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };

	printf("�� ���� �� : ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	for (i = 0; i < 10; i++) {
		heap_sort(list, n);
		heap(list, &n);
	}

	n = MAX_SIZE;
	printf("\n�� ���� �� : ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}