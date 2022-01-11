//아이디어 어려움
// 규칙성 찾기 어려움<br>
// - 내가 생각한 방법 : 2씩 끊어져서 타일 깔 때 (dpArr[i-2] * 3) <br>
// 모든 선에서 엇갈리게 넣을 때 (i번째라면 2^(i/2 -1)) <br>
// 부분 부분만 엇갈릴 때 : 이전에 엇갈린 경우의 수 * 3 * 3 <br>
// => 이렇게 하면 경우의 수 너무 많이 나옴 <br>

// - 정답<br>
// dp[31], sum[31] <br>
// dp[i] = dp[i-2] + sum[i-2]x2 <br>
// sum[i] = sum[i-2] + dp[i] <br>
// 맨 오른쪽 ㅣ 이렇게, ㅡ 이렇게 세우는 경우 나눠서 생각

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
