//all pairs shortest
#include <iostream>

using namespace std;

const int N_MAX = 500;
const int INFINITI = 999;

bool page[N_MAX + 1][N_MAX + 1] = { false, };
int dist[N_MAX + 1][N_MAX + 1] = { 0, };

void floyd(int N) {
	//dist 배열 setting
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (page[i][j] == true) dist[i][j] = 1;
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

}


int main() {

	freopen("input.txt", "r", stdin);

	int N, a, b;
	int pageMax = -1;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		if (a > pageMax) {
			pageMax = a;
		}
		if (b > pageMax) {
			pageMax = b;
		}
		page[a][b] = true;
	}


	//floyd
	floyd(pageMax);


	//최솟값 평균 구하기
	int sum = 0;

	for (int i = 1; i <= pageMax; i++) {
		for (int j = 1; j <= pageMax; j++) {
			if (i == j) continue;
			sum += dist[i][j];
		}

	}

	double result;
	result = (double)sum / (pageMax*(pageMax - 1));

	printf("%.3f", result);

	return 0;
}
