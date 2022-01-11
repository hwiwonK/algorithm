// bfs로 풀어보기
// (다익스트라, 다익스트라 + 우선순위큐, dfs)

#include <iostream>

using namespace std;

const int MAP_MAX = 102; //인덱스 0과 101은 경계선
const int INFINITI = 10000;

int mapArr[MAP_MAX][MAP_MAX] = { 0, }; //-1만나면 경계
bool visit[MAP_MAX][MAP_MAX] = { false, };
int minVal[MAP_MAX][MAP_MAX] = { 0, };
int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //상하좌우

//최소값 구하기, 방문 안한
//최소값 노드의 x, y좌표 반환
void getMin(int minPos[], int N) {
	int getMinVal = INFINITI;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == false && getMinVal > minVal[i][j]) {
				getMinVal = minVal[i][j];
				minPos[0] = i;
				minPos[1] = j;
			}
		}
	}
}

//a, b = 처음 방문할 노드의 좌표  N= 지도 한쪽 길이
int findRoad(int a, int b, int N) { //mapArr[i][j]가 정점

	int totalNodes = N * N;

	//첫번째 방문 + 상하좌우 minVal setting
	minVal[a][b] = 0;
	visit[a][b] = true;

	//아래쪽, 오른쪽 바꾸기
	minVal[a + d[1][0]][b+ d[1][1]] = mapArr[a + d[1][0]][b + d[1][1]];
	minVal[a + d[3][0]][b+ d[3][1]] = mapArr[a + d[3][0]][b + d[3][1]];

	

	for (int n = 2; n <= totalNodes; n++) { //모든 노드 방문 필요(출발점은 이미 방문)
		int minPos[2] = { 0, };
		getMin(minPos, N); //최솟값 구하기

		//최솟값 노드의 x, y 좌표(가로, 세로)
		int xPos = minPos[0];
		int yPos = minPos[1];

		//방문 처리
		visit[xPos][yPos] = true;

		//인접한 것, 상-하-좌-우 minVal 갱신하기
		for (int i = 0; i < 4; i++) {
			int x = xPos + d[i][0];
			int y = yPos + d[i][1];
			if (mapArr[x][y] != -1) { //범위 초과 안했을 때
				minVal[x][y] = (minVal[xPos][yPos] + mapArr[x][y]) < minVal[x][y] ?
					minVal[xPos][yPos] + mapArr[x][y] : minVal[x][y];
			}
		}
	}

	return minVal[N][N];
}

int main() {

	freopen("input.txt", "r", stdin);

	int T, N;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 0; i < MAP_MAX; i++) {
			for (int j = 0; j < MAP_MAX; j++) {
				mapArr[i][j] = -1;
				minVal[i][j] = INFINITI;
				visit[i][j] = false;
			}
		}

		//지도 입력받기 - 확인
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%1d", &mapArr[i][j]);
			}
		}

		int result = findRoad(1 , 1, N);

		cout << "#" << tc << " " << result << endl;
	}


	return 0;
}
