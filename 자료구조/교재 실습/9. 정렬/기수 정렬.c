#include<stdio.h>
# define MAX_SIZE 5

void radixSort(int* a, int n) {
	int result[MAX_SIZE], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue / exp > 0) {
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			result[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = result[i];
		exp *= 10;
	}
}

int main() {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE] = { 9, 4, 2, 6, 3 };

	printf("기수 정렬 전 : ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);

	radixSort(list, n);

	printf("\n기수 정렬 후 : ");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
}