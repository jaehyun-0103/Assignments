#include <stdio.h>

void hanoi_tower(int, char, char, char);

int main() {
    int n;
    char from = 'A', tmp = 'B', to = 'C';
    printf("원판의 개수 : ");
    scanf_s("%d", &n);
    printf("\n");
    hanoi_tower(n, from, tmp, to);
}

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1)
        printf("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}