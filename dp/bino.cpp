#include <iostream>

using namespace std;

//중복 연산 발생 -> 2^n 호출 횟수
int bino_r(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	else {
		return bino_r(n - 1, k - 1) + bino_r(n - 1, k);
	}
}

int bino_dp(int n, int k) {
	int tbl[10][20] = { 0, };

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) { //i까지만 해도 된다, j가 i보다 크면 어차피 0
			if (j == 0 || i == j)
				tbl[i][j] = 1;
			else
				tbl[i][j] = tbl[i - 1][j - 1] + tbl[i - 1][j];
		}
	}

	return tbl[n][k];
}

int main() {

	cout << bino_dp(4, 3);

	return 0;
}
