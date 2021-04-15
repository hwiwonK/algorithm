//비트
//0 - 2^n 까지, 짝수만 고려(1이 경로에 포함되는 경우는 제외)
//2, 4, 6, 8, ... , (2^n) -2 : 접근해야할 부분집합 인덱스


#include <iostream>

using namespace std;

const int INFINITI = 99999;
const int N_MAX = 19;
int dist[N_MAX + 1][2 << (N_MAX - 2)] = { 0, }; //총 2^(N-1) 부분집합 고려 (1이 있는 경우 제외)
int input[N_MAX + 1][N_MAX + 1] = { 0, };

void getRoad(int N) {
	//baseline 만들기(공집합 경우)
	int limit = 2 << (N - 2);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < limit; j++) {
			dist[i][j] = INFINITI;
		}
	}

	for (int i = 1; i <= N; i++) {
		dist[i][0] = input[i][1];
	}

	//부분집합 2 부터 2^(n-1)까지 (1은 시작정점이므로 제외)
	for (int c = 1; c < limit; c++) {
		for (int i = 1; i <= N; i++) { //정점 i에서 출발

			//부분집합 c에서 i를 포함한다면 pass (i번째 비트 확인)
			if ((c & (1 << (i - 2))) > 0 && i != 1) continue;

			//c가 i 포함하지 않는다면, c에서 선택된 모든 정점 돌면서 최솟값 갱신
			//dist[i][c] = min(input[i][j] + dist[j][c집합 -j정점])
			int tmp = c;
			int shift = 0;
			//dist[i][c] = INFINITI;
			while (tmp != 0) {
				if ((tmp & 1) == 1) {
					int j = shift + 2; //j번째 정점 거친다
					//j, i, 1을 뺀 정점 집합 = c에서 j번째 bit를 0으로 만든다(맨 오른쪽이 첫번째)
					int minVal = input[i][j] + dist[j][c & ~(1 << shift)];
					if (minVal < dist[i][c]) dist[i][c] = minVal;
				}

				shift++;
				tmp = c >> shift;
			}

		}

	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int N;
	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
			if (input[i][j] == 0) input[i][j] = INFINITI;
		}
	}

	//dist 채우기
	getRoad(N);

	//for (int i = 0; i <= N; i++) {
	//	for (int j = 0; j <= (2 << (N - 2)) - 1; j++) {
	//		cout << dist[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout << endl;
	//cout << (2 << (N - 1)) - 1 << endl;


	//최솟값 구하기
	cout << dist[1][(2 << (N-2)) - 1];

	return 0;
}
