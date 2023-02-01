# include <stdio.h>
# define MAX_SIZE 8
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }

    for (l = left; l <= right; l++)
        list[l] = sorted[l];
}

// 합병 정렬
void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

    printf("합병 정렬 전 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

    merge_sort(list, 0, n - 1);

    printf("\n합병 정렬 후 : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
}