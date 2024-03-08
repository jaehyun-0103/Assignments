# include <stdio.h>
# define MAX_SIZE 5

// ���� ����
void selection_sort(int list[], int n) {
    int i, j, least, temp;

    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least])
                least = j;
        }
        if (i != least) {
            temp = list[i];
            list[i] = list[least];
            list[least] = temp;
        }
    }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 9, 6, 7, 3, 5 };

    printf("���� ���� �� : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

    selection_sort(list, n);

    printf("\n���� ���� �� : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
}