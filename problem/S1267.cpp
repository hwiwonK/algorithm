#include <iostream>
//위상정렬 이용하기

using namespace std;

const int MAX_V = 1001;
int workArr[MAX_V][MAX_V] = { 0, };
int result[MAX_V] = { 0, };
//i=0 부분에는 진입차수 기록 (-1이라면 방문한 곳)

int toVisit(int V) {
	for (int v = 1; v <= V; v++) {
		if (workArr[0][v] == 0) return v;
	}
}

void getPath(int V) {
	int visitV;
	for (int i = 1; i <= V; i++) {
		visitV = toVisit(V); //진입차수 0인 곳
		workArr[0][visitV] = -1; //방문 처리
		result[i] = visitV; //결과 배열에 추가

		for (int j = 1; j <= V; j++) {
			if (workArr[visitV][j] == 1) workArr[0][j]--;
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	int T = 10;

	for (int tc = 1; tc <= T; tc++) {
		int V, E;
		int from, to;

		cin >> V >> E;

		for (int i = 1; i <= E; i++) {
			cin >> from >> to;
			workArr[from][to] = 1;
			workArr[0][to]++; //진입차수 증가
		}

		getPath(V);

		//결과 출력
		cout << "#" << tc << " ";
		for (int i = 1; i <= V; i++) {
			cout << result[i] << " ";
		}
		cout << endl;

		//초기화
		for (int i = 0; i <= V; i++) {
			for (int j = 0; j <= V; j++) {
				workArr[i][j] = 0;
			}
			result[i] = 0;
		}
	}


	return 0;
}
