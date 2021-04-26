//실수하지 말기, 꼼꼼히 쓰기, INPUT부터 확인하기

#include <iostream>

using namespace std;

const int R_MAX = 50;
const int INFINITI = 99999;

char map[R_MAX][R_MAX] = { 0, };
int fireTime[R_MAX][R_MAX] = { 0, };
bool visitArr[R_MAX][R_MAX] = { 0, };

//상-하-좌-우
int d[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

//선언 순서 착각하지 말기
struct road {
	int r;
	int c;
	int time;
};

//queue 관련
struct road queue[R_MAX * R_MAX] = { 0, };

int front = -1;
int rear = -1;

struct road pop() {
	front++;

	struct road tmp;
	tmp.r = queue[front].r;
	tmp.c = queue[front].c;
	tmp.time = queue[front].time;

	return tmp;
}

void push(int r, int c, int time) {
	rear++;
	queue[rear].r = r;
	queue[rear].c = c;
	queue[rear].time = time;
}

//불길 번지는 시간 구하기
void getFireTime(int R, int C) {

	while (front != rear) {
		//맨 처음 것 방문
		struct road visit = pop();

		for (int i = 0; i < 4; i++) {
			int rpos = visit.r + d[i][0];
			int cpos = visit.c + d[i][1];

			if (rpos < 0 || rpos >= R || cpos < 0 || cpos >= C) continue;

			//빈공간이고, 아직 미방문시
			if (map[rpos][cpos] == '.' && fireTime[rpos][cpos] == INFINITI) {
				push(rpos, cpos, visit.time + 1);
				fireTime[rpos][cpos] = visit.time + 1;
			}

		}


	}

}

int findRoad(int R, int C, int Srow, int Scol, int Drow, int Dcol) {

	visitArr[Srow][Scol] = true;
	push(Srow, Scol, 0);

	while (front != rear) {
		//맨 처음 것 방문
		struct road visit = pop();

		if (visit.r == Drow && visit.c == Dcol) return visit.time;

		for (int i = 0; i < 4; i++) {
			int rpos = visit.r + d[i][0];
			int cpos = visit.c + d[i][1];

			if (rpos < 0 || rpos >= R || cpos < 0 || cpos >= C) continue;

			//빈공간이고, 아직 미방문시
			if (map[rpos][cpos] == '.' && (visit.time + 1 < fireTime[rpos][cpos]) && visitArr[rpos][cpos] == false) {
				push(rpos, cpos, visit.time + 1);
				visitArr[rpos][cpos] = true;
			}

		}

	}

	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);

	//입력 받기

	int R, C, Srow, Scol, Drow, Dcol;

	scanf("%d %d", &R, &C);

	//fireTime 최댓값으로 초기화
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			fireTime[i][j] = INFINITI;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '*') { //불 있으면 queue에 넣고, fireTime 배열 세팅
				push(i, j, 0);
				fireTime[i][j] = 0;
			}
			else if (map[i][j] == 'S') {
				Srow = i;
				Scol = j;
			}
			else if (map[i][j] == 'D') {
				Drow = i;
				Dcol = j;
			}
		}
	}

	getFireTime(R, C);

	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < R; j++) {
	//		printf("%d ", fireTime[i][j]);
	//	}
	//	printf("\n");
	//}

	//queue 초기화
	front = -1;
	rear = -1;

	map[Drow][Dcol] = '.';

	//재우 출발(bfs)
	int result = findRoad(R, C, Srow, Scol, Drow, Dcol);

	if (result == -1) {
		printf("impossible\n");
	}
	else {
		printf("%d", result);
	}

	return 0;
}
