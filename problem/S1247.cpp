#include <iostream>

using namespace std;
int location[12][2] = { 0, }; //인덱스 0: 회사, 1~10 : 고객, 11: 집
bool visit[11] = { false, }; //인덱스 1~10
int distArr[11][11] = { 0, }; //거리 정보
int N;
int minDist;

//a와 b 사이의 거리 구하기
int getDist(int location[][2], int a, int b) {
	int rowDist = location[a][0] - location[b][0];
	int colDist = location[a][1] - location[b][1];
	rowDist = (rowDist < 0) ? rowDist * (-1) : rowDist;
	colDist = (colDist < 0) ? colDist * (-1) : colDist;

	return rowDist + colDist;
}

int findCandi(int location[][2], bool visit[], int pre, int candi[][2], int dist) {
	int candiN = 1;
	int predictDist = 0;

	for (int i = 1; i <= N; i++) { // N개의 집에서 후보 고르기
		if (visit[i] == false) {
			predictDist = dist + distArr[pre][i]; //pre와 i 집 사이 거리 구하기
			if (minDist > predictDist) {  // 이미 최솟값보다 크면 후보에서 탈락
				candi[candiN][0] = i;
				candi[candiN++][1] = predictDist;
			}
		}
	}

	return candiN - 1;

}

//dist = 현재까지 거리, cnt = 방문한 집 수, pre = 이전에 방문한 집
void findRoad(int location[][2], bool visit[], int dist, int cnt, int pre) {
	//다 골랐을 때
	if (cnt == N) { //고객 다 방문함
		dist = dist + getDist(location, pre, 11); //집까지 오는 거리도 더하기
		if (dist < minDist) minDist = dist;
		return;
	}

	int candi[11][2] = { 0, };
	int candiN = findCandi(location, visit, pre, candi, dist);

	//후보값들 방문하기
	for (int i = 1; i <= candiN; i++) {
		visit[candi[i][0]] = true; // 방문 처리
		findRoad(location, visit, candi[i][1], cnt + 1, candi[i][0]);
		visit[candi[i][0]] = false; // 방문 해제
	}

}

int main() {

	int T;
	int tc;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (tc = 1; tc <= T; tc++) {

		minDist = 10000;
		//입력받기 -확인완료
		cin >> N;
		cin >> location[0][0] >> location[0][1] >> location[11][0] >> location[11][1];
		for (int i = 1; i <= N; i++) {
			cin >> location[i][0] >> location[i][1];
		}


		for (int i = 0; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				distArr[i][j] = getDist(location, i, j);
				distArr[j][i] = distArr[i][j];
			}
		}


		findRoad(location, visit, 0, 0, 0);



		cout << "#" << tc << " " << minDist << endl;


	}



	return 0;
}
