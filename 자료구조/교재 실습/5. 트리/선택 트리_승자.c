#include <stdio.h>
# define MAX_SIZE 5

void selection_winner(int tourn[], int n) {
	int i;

	for (i = 2 * n - 2; i > 1; i = i - 2) {
		if (tourn[i] >= tourn[i + 1])
			tourn[i / 2] = tourn[i];
		else
			tourn[i / 2] = tourn[i + 1];
	}
}

int main() {
	int i;
	int n = MAX_SIZE;
	int tourn[MAX_SIZE*2] = { 0, 0, 0, 0, 0, 4, 6, 7, 3, 5 };

	selection_winner(tourn, n);

	printf("ÃÖ´ñ°ª : %d ", tourn[1]);
}