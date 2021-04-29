//아이디어 어려움

#include <iostream>

using namespace std;

const int N_MAX = 1010000;

int dpArr[N_MAX + 1][6] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);

	int a, b, d, N;

	scanf("%d %d %d %d", &a, &b, &d, &N);

	dpArr[10000][1] = 1; //한마리 넣기
	dpArr[10000][2] = 1;
	dpArr[10000][5] = 1;

	N = N + 10000;

	for (int i = 10001; i <= N; i++) {
		//새로 생긴 성체
		dpArr[i][3] = dpArr[i - a][1];

		//현재 새끼 만들 수 있는 성체의 수
		dpArr[i][4] = dpArr[i - 1][4] + dpArr[i][3] - dpArr[i - b][1];

		//새로 생긴 개체
		dpArr[i][1] = dpArr[i][4];

		//현재 새끼의 수
		dpArr[i][2] = dpArr[i - 1][2] + dpArr[i][1] - dpArr[i][3];

		//현재 개체 총 수
		dpArr[i][5] = dpArr[i - 1][5] + dpArr[i][1] - dpArr[i - d][1];
	}

	int result = dpArr[N][5] % 1000;

	printf("%d", result);

	return 0;
}
