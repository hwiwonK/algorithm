// 1000ms, 64 MB
// 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
// 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우
// 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램

#include <iostream>

using namespace std;

const int N_MAX = 25;

char mapArr[N_MAX+1][N_MAX+1] = { 0, };
int block[N_MAX] = { 0, };

//상-우-하-좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

//단지 내 집의 수 출력
int dfs(int y, int x, int house) {
	
	//방문 처리
	house++;
	mapArr[y][x] = '0';

	int xdir, ydir;

	for (int i = 0; i < 4; i++) {
		xdir = x + dx[i];
		ydir = y + dy[i];

		//0이면 방문 X
		if (mapArr[ydir][xdir] == '1') {
			house = dfs(ydir, xdir, house);
		}
	}

	return house;

}

void sort(int N) {
	int minIdx = -1;
	int minVal = -1;
	int tmp = -1;

	for (int i = 0; i < N-1; i++) {
		minIdx = i;
		minVal = block[minIdx];

		for (int j = i + 1; j < N; j++) {
			if (block[j] <= minVal) {
				minIdx = j;
				minVal = block[minIdx];
			}
		}

		tmp = block[minIdx];
		block[minIdx] = block[i];
		block[i] = tmp;
	}

}

int main() {

	freopen("input.txt", "r", stdin);

	int N, blockCnt = 0, houseCnt;

	cin >> N;

	//입력받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mapArr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (mapArr[i][j] == '1') {
				houseCnt = dfs(i, j, 0);
				block[blockCnt++] = houseCnt;
			}
		}
	}

	cout << blockCnt << endl;

	//정렬하기
	sort(blockCnt);

	for (int i = 0; i < blockCnt; i++) {
		cout << block[i] << endl;
	}


	return 0;
}
