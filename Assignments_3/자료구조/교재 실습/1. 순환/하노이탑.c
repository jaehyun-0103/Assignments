#include <stdio.h>

void hanoi_tower(int, char, char, char);

int main() {
    int n;
    char from = 'A', tmp = 'B', to = 'C';
    printf("������ ���� : ");
    scanf_s("%d", &n);
    printf("\n");
    hanoi_tower(n, from, tmp, to);
}

void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1)
        printf("���� 1�� %c���� %c���� �ű��.\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("���� %d�� %c���� %c���� �ű��.\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}