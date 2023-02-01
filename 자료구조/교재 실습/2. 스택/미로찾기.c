#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAZE_SIZE 10 // 미로의 가로, 세로 크기

typedef struct Mouse {
	short x;
	short y;
}Mouse;

typedef struct Stack {
	Mouse data[MAX_SIZE];
	int top;
}Stack;

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1','1','1','1','1'},
	{'m','0','0','0','1','0','0','0','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','1','1','0','0','1','0','1'},
	{'1','0','0','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','1','0','0','1','0','1'},
	{'1','0','1','0','0','0','0','1','0','X'},
	{'1','1','1','1','1','1','1','1','1','1'} };

void init(Stack* p) {
	p->top = -1;
}

int isFull(Stack* p) {
	return (p->top == MAX_SIZE - 1);
}

int isEmpty(Stack* p) {
	return (p->top == -1);
}

void push(Stack* p, Mouse data) {
	if (isFull(p)) {
		printf("스택 포화 에러\n");
		return;
	}
	else {
		p->top++;
		p->data[p->top].x = data.x;
		p->data[p->top].y = data.y;
	}
}

Mouse pop(Stack* p) {
	if (isEmpty(p)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	return p->data[(p->top)--];
}

void FindWay(Stack* s, int x, int y) {
	if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE)
		return;
	if (maze[x][y] != '1' && maze[x][y] != '.') {
		Mouse tmp;
		tmp.x = x;
		tmp.y = y;
		push(s, tmp);
	}
}

int main() {
	Stack s;
	Mouse m;
	int x, y;

	init(&s);

	// 시작점 탐색
	for (int i = 0; i < MAZE_SIZE; i++)
		for (int j = 0; j < MAZE_SIZE; j++)
			if (maze[i][j] == 'm') {
				m.x = i;
				m.y = j;
			}

	printf("<이동 경로>\n");
	printf("입구 -> (%d,%d) -> ", m.x, m.y);
	while (maze[m.x][m.y] != 'X') {
		x = m.x;
		y = m.y;

		// 방문한 곳을 표시
		maze[x][y] = '.'; 
		// 이동 가능한 곳을 탐색
		FindWay(&s, x - 1, y);
		FindWay(&s, x + 1, y);
		FindWay(&s, x, y - 1);
		FindWay(&s, x, y + 1);

		if (isEmpty(&s)) {
			printf("길이 없습니다.\n실패\n");
			return 0;
		}
		else {
			m = pop(&s); // 현재 좌표를 변경
			printf("(%d,%d) -> ", m.x, m.y);
		}
	}
	printf("출구\n");

	printf("\n<결과>\n");
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			if (maze[i][j] == '0')
				printf("0");
			else if (maze[i][j] == '1')
				printf("1");
			else
				printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}