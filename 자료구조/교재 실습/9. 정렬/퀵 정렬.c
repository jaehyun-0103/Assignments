# include <stdio.h>
# define MAX_SIZE 9

//# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )



int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left + 1;
    high = right;
    pivot = list[left];

    while (low <= high) {
        while (list[low] <= pivot) { low++; }
        while (list[high] > pivot) { high--; }
        if (low < high) {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    }
    temp = list[left];
    list[left] = list[high];
    list[high] = temp;

    return high;
}

// Äü Á¤·Ä
void quick_sort(int list[], int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
    
    printf("Äü Á¤·Ä Àü : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);

    quick_sort(list, 0, n - 1);

    printf("\nÄü Á¤·Ä ÈÄ : ");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
}