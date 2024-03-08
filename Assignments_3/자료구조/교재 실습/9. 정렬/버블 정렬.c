# include <stdio.h>
# define MAX_SIZE 5

// 버블 정렬
void bubble_sort(int list[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 7, 4, 5, 1, 3 };

    printf("버블 정렬 전 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

    bubble_sort(list, n);

    printf("\n버블 정렬 후 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
}