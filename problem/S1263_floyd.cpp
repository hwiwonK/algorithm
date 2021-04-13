#include <iostream>

using namespace std;

const int INFINITI = 9999;
const int N_MAX = 1001;

int dist[N_MAX][N_MAX] = { 0, };
bool network[N_MAX][N_MAX] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);

	int tc, T, N;

	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> network[i][j];
			}
		}

		//dist 배열 setting
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (network[i][j] == true) dist[i][j] = 1;
				else dist[i][j] = INFINITI;
			}
		}


		for (int t = 1; t <= N; t++) { //경유점
			for (int i = 1; i <= N; i++) { //출발
				if (i == t) continue;
				for (int j = 1; j <= N; j++) { //도착
					if (i == j || t == j) continue;
					dist[i][j] = dist[i][j] < dist[i][t] + dist[t][j] ? dist[i][j] : dist[i][t] + dist[t][j];
					
				}

			}

		}


		int minVal = 999999;
		int sumTmp = 0;
		for (int i = 1; i <= N; i++) {
			sumTmp = 0;
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				sumTmp += dist[i][j];
			}
			if (sumTmp < minVal) minVal = sumTmp;
		}

		cout << "#" << tc << " " << minVal << endl;

	}


}
