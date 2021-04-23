#include <iostream>

using namespace std;

const int N_MAX = 50;

char treasure[N_MAX][N_MAX] = { 0, };
bool visit[N_MAX][N_MAX] = { 0, };
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int maxDist = -1;

//queue 관련
struct land
{
	int y;
	int x;
	int time;
};

struct land queue[(N_MAX * N_MAX)] = { 0, }; // y좌표, x좌표, 시간

int front = -1;
int rear = -1;

void enqueue(int y, int x, int time) {
	rear++;
	queue[rear].y = y;
	queue[rear].x = x;
	queue[rear].time = time;
}

void bfs(int y, int x, int N, int M) {

	//y, x 큐에 넣기
	enqueue(y, x, 0); //시간은 0
	visit[y][x] = true;

	while (front != rear) {
		//방문
		front++;
		int curX = queue[front].x;
		int curY = queue[front].y;
		int curTime = queue[front].time;

		for (int a = 0; a < 4; a++) {

			int xpos = curX + d[a][1];
			int ypos = curY + d[a][0];

			//경계선 체크
			if (ypos >= N || xpos >= M || xpos < 0 || ypos < 0) continue;

			//queue에 없다면 & 육지라면 enqueue
			if (!visit[ypos][xpos] && treasure[ypos][xpos] == 'L') {
				visit[ypos][xpos] = true;
				enqueue(ypos, xpos, curTime + 1);
			}
		}
	}

	// 더 큰 육지-육지 최단거리 나왔을 때 maxDist 갱신
	if (maxDist < queue[rear].time) maxDist = queue[rear].time;

}

//queue, visit 배열 초기화
void resetQueue(int N, int M) {
	front = -1;
	rear = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = false;
		}
	}
	
}

int main() {

	freopen("input.txt", "r", stdin);

	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &treasure[i][j]);
		}
	}

	//육지 찾으면 bfs
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (treasure[i][j] == 'L') {
				bfs(i, j, N, M);
				resetQueue(N, M);
			}
		}
	}
	
	printf("%d", maxDist);

	return 0;
}