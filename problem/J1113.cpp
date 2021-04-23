#include <iostream>

using namespace std;

const int N_MAX = 100;
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
//가로 방향은 +1, 세로 방향은 -1
int M, N;


int village[N_MAX][N_MAX] = { 0, };
bool visit[N_MAX][N_MAX] = { 0, };
int minCorner[N_MAX][N_MAX] = { 0, };
int minVal = 99999;

//dir이 0이면 시작점
void dfs(int y, int x, int m, int n, int dir) {

	//지금 길 가기
	visit[y][x] = true;

	if (y == m && x == n) {
		minVal = minCorner[m][n];
	}

	//앞으로의 길 탐색
	for (int a = 0; a < 4; a++) {
		int xpos = x + d[a][1];
		int ypos = y + d[a][0];

		//경계선 체크
		if (ypos >= N || xpos >= M || xpos < 0 || ypos < 0) continue;

		//코너 체크
		int curdir;
		int samedir = 1; //1 = 다른 방향, 0 = 같은 방향

		if (a == 0 || a == 2) curdir = 1;
		else curdir = -1;

		if (curdir == dir || dir == 0) samedir = 0;

		//아직 미방문, 길이 있다면
		if (village[ypos][xpos] == 1 && !visit[ypos][xpos]) {
			int tmp = minCorner[y][x] + samedir;
			if (tmp <= minCorner[ypos][xpos] && tmp < minVal) {
				minCorner[ypos][xpos] = tmp;
				dfs(ypos, xpos, m, n, curdir);
				visit[ypos][xpos] = false;
			}
		}
	}

}

int main() {

	freopen("input.txt", "r", stdin);

	int m, n;

	scanf("%d %d %d %d", &M, &N, &m, &n);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &village[i][j]);
		}
	}


	//minCorner배열 초기화)
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			minCorner[i][j] = minVal;
		}
	}

	minCorner[0][0] = 0;

	dfs(0, 0, m, n, 0);

	//m, n 위치의 minCorner 값 출력
	printf("%d", minCorner[m][n]);

	return 0;
}