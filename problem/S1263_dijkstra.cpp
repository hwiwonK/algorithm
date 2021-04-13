#include <iostream>

using namespace std;

const int INFINITI = 9999;
const int N_MAX = 1001;

int dist[N_MAX] = { 0, };
bool network[N_MAX][N_MAX] = { 0, };
bool visit[N_MAX] = { 0, };

//우선순위 큐 사용해보기

int main() {
	freopen("input.txt", "r", stdin);

	int tc, T, N, minVal;

	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		minVal = 99999;

		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> network[i][j];
			}
		}


		for (int start = 1; start <= N; start++) { //start : 시작정점
			//dist 배열 setting
			for (int i = 1; i <= N; i++) {
				dist[i] = INFINITI;
				visit[i] = false;
			}

			//함수 호출
			int sumTmp = 0;
			int v = start;
			int cnt = 0;
			//시작정점 방문 & 인접 정점 dist 갱신
			visit[v] = true;
			cnt++;
			for (int i = 1; i <= N; i++) {
				if (network[v][i] == 1) dist[i] = 1;
			}
			dist[v] = 0;

			while (cnt != N) {
				//extract min
				int minVal = 99999;
				int minIdx = -1;
				for (int i = 1; i <= N; i++) {
					if (!visit[i] && dist[i] < minVal) {
						minVal = dist[i];
						minIdx = i;
					}
				}

				//minIdx 방문
				visit[minIdx] = true;
				cnt++;
				sumTmp += dist[minIdx];

				//인접정점 갱신
				for (int i = 1; i <= N; i++) {
					if (network[minIdx][i] == 1) {
						if (dist[i] > dist[minIdx] + 1) {
							dist[i] = dist[minIdx] + 1;
						}
					}
				}


			}

			if (minVal > sumTmp) minVal = sumTmp;
			//dist배열 합 구하기

		}

		cout << "#" << tc << " " << minVal << endl;

		//초기화하기

	}


}
