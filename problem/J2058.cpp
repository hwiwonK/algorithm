#include <iostream>

//현재 정비소를 마지막으로 점검하게 될 때의 최솟값
//아이디어 어려움

using namespace std;

const int N_MAX = 26;

int village[N_MAX][N_MAX] = { 0, };
bool visit[N_MAX][N_MAX][N_MAX][N_MAX] = { 0, };
int d[][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0,1}, {1, -1}, {1, 0}, {1,1} };

struct godol {
	int curR;
	int curC;
	int homeR;
	int homeC;
} godol;

struct goso {
	int curR;
	int curC;
	int homeR;
	int homeC;
} goso;

//queue 관련
struct current {
	int godolR;
	int godolC;
	int gosoR;
	int gosoC;
	int hours;
};

struct current q[N_MAX * N_MAX * N_MAX * N_MAX] = { 0, };

int front = -1;
int rear = -1;

void push(int godolY, int godolX, int gosoY, int gosoX, int hour) {
	rear++;
	q[rear].godolR = godolY;
	q[rear].godolC = godolX;
	q[rear].gosoR = gosoY;
	q[rear].gosoC = gosoX;
	q[rear].hours = hour;
}

struct current * pop() {
	front++;

	return &q[front];
}

//bfs
int BFS(int N) {

	while (front != rear) {
		//pop하기
		struct current * cur = pop();

		//둘다 목적지면 return 시간
		if (cur->godolR == godol.homeR && cur->godolC == godol.homeC
			&& cur->gosoR == goso.homeR && cur->gosoC == goso.homeC) {
			return cur->hours;
		}

		int hours = cur->hours;

		//81가지 경우 체크하기 (경계선 + visit + 겹치는지 + 길 있는지) , 둘다 제자리면 안됨
		for (int i = 0; i < 9; i++) {
			int godolR = cur->godolR + d[i][0];
			int godolC = cur->godolC + d[i][1];
			if (godolR < 1 || godolR > N || godolC < 1 || godolC > N) continue;

			for (int j = 0; j < 9; j++) {
				if (i == 4 && j == 4) continue; //둘 다 제자리인 경우 pass
				int gosoR = cur->gosoR + d[j][0];
				int gosoC = cur->gosoC + d[j][1];

				if (gosoR < 1 || gosoR > N || gosoC < 1 || gosoC > N) continue;

				int Rdist = godolR - gosoR;
				int Cdist = godolC - gosoC;

				if (((Rdist > 1 || Rdist < -1) || (Cdist > 1 || Cdist < -1)) && !visit[godolR][godolC][gosoR][gosoC] &&
					village[godolR][godolC] == 0 && village[gosoR][gosoC] == 0) {
					visit[godolR][godolC][gosoR][gosoC] = true;
					push(godolR, godolC, gosoR, gosoC, hours + 1);
				}

			}
		}

	}



	return 0;
}


int main() {
	freopen("input.txt", "r", stdin);

	int N;

	scanf("%d", &N);

	scanf("%d %d %d %d", &godol.curR, &godol.curC, &godol.homeR, &godol.homeC);
	scanf("%d %d %d %d", &goso.curR, &goso.curC, &goso.homeR, &goso.homeC);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &village[i][j]);
		}
	}

	//현재 고돌, 고순 위치 push

	push(godol.curR, godol.curC, goso.curR, goso.curC, 0);
	visit[godol.curR][godol.curC][goso.curR][goso.curC] = true;

	int result = BFS(N);
	
	printf("%d", result);

	return 0;
}
