# include <stdio.h>
# define MAX_SIZE 5

// 삽입 정렬
void insertion_sort(int list[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 8, 5, 6, 2, 4 };

    printf("삽입 정렬 전 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

    insertion_sort(list, n);

    printf("\n삽입 정렬 후 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
}