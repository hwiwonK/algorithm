//아이디어 어려움

#include <iostream>

using namespace std;

const int N_MAX = 30;

int dpArr[N_MAX + 1][2] = { 0, };

int pow(int n) {
	int tmp = 1;

	for (int i = 1; i <= n; i++) {
		tmp *= 2;
	}

	return tmp;
}

int main() {
	freopen("input.txt", "r", stdin);

	int N;

	scanf("%d", &N);
	

	dpArr[2][0] = 3;


	for (int i = 2; i <= N; i += 2) {
		dpArr[i][1] = pow((i >> 1) - 1);
	}

	int i = 4;
	int cnt = 2;

	dpArr[2][1] = 0;

	while (i <= N) {
		dpArr[i][0] = dpArr[i - 2][0] * 3;
		dpArr[i][1] = dpArr[i][1] + dpArr[i-2][1] * 3;

		cnt++;
		i = 2 * cnt;

	}

	printf("%d", dpArr[N][0] + dpArr[N][1]);

	return 0;
}
