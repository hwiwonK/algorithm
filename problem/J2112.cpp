//아이디어 어려움

#include <iostream>

using namespace std;

const int N_MAX = 30;

int dpArr[N_MAX + 1] = { 0, };

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
	

	dpArr[2] = 3;

	int i = 4;
	int cnt = 2;

	while (i <= N) {
		dpArr[i] = dpArr[i - 2] * 3 + pow(cnt - 1);
		cnt++;
		i = 2 * cnt;

	}

	printf("%d", dpArr[N]);

	return 0;
}
