//https://cafe.naver.com/cozal

#include <iostream>

using namespace std;

const int N_MAX = 300; //코끼리 수, 최대 코 길이
const int MOD_VAL = 1000000007;

int dpArr[N_MAX + 1][N_MAX + 1][2] = { 0, }; //i마리 코끼리, j로 시작, 0: 작커, 1: 커작

int main() {

	freopen("input.txt", "r", stdin);

	//dp 테이블 세팅

	dpArr[3][1][0] = 1;
	dpArr[3][2][0] = 1;
	dpArr[3][2][1] = 1;
	dpArr[3][3][1] = 1;

	//n = 코끼리 수 (최대 코 길이)
	for (int n = 4; n <= N_MAX; n++) {
		//first = 수열에서 첫번째 수
		for (int first = 1; first <= n; first++) {
			//작커 경우의 수
			for (int k = first; k < n; k++) {
				dpArr[n][first][0] = (dpArr[n][first][0] % MOD_VAL + dpArr[n - 1][k][1] % MOD_VAL) % MOD_VAL;
				
			}

			//커작 경우의 수
			for (int k = 1; k < first; k++) {
				dpArr[n][first][1] = (dpArr[n][first][1] % MOD_VAL + dpArr[n - 1][k][0] % MOD_VAL) % MOD_VAL;
				
			}

		}

	}


	//입력 받고 결과 출력하기
	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int N;
		int sumVal = 0;
		scanf("%d", &N);

		//결과 출력
		for (int i = 1; i <= N; i++) {
			sumVal = (sumVal + (dpArr[N][i][0] + dpArr[N][i][1]) % MOD_VAL) % MOD_VAL;

		}

		printf("#%d %d\n", tc, sumVal);

	}




	return 0;
}
