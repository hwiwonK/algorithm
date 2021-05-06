//Kadane's 알고리즘은 최대 연속 부분합을 O(N) 으로 구한다
//D[0] = ai
//D[i] = max(D[i-1] + ai, ai)



#include <iostream>

using namespace std;

const int N_MAX = 300;

long long maxVal = -1;
int maxSize = 90000;

long long sumArr[N_MAX + 1][N_MAX + 1] = { 0, };
long long gain[N_MAX + 1][N_MAX + 1] = { 0, };

long long dpArrLeft[N_MAX + 1][N_MAX + 1][3] = { 0, };
long long dpArrUp[N_MAX + 1][N_MAX + 1][3] = { 0, };
long long dpArr[N_MAX + 1][N_MAX + 1][3] = { 0, };

void printArr(long long arr[][N_MAX + 1], int R, int C) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int R, C;
		long long curCost, tmp;

		maxVal = -1;
		maxSize = 90000;

		scanf("%d %d %d", &R, &C, &curCost);

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf("%d ", &tmp);
				gain[i][j] = tmp - curCost;
			}
		}

		//합 구하기
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				sumArr[i][j] = sumArr[i - 1][j];
				for (int k = 1; k <= j; k++) {
					sumArr[i][j] += gain[i][k];
				}
			}
		}

		//printArr(sumArr, R, C);


		////dpArr 채우기

		//1열, 1행 채우기
		for (int j = 1; j <= C; j++) {
			dpArrUp[1][j][0] = gain[1][j];
			dpArrUp[1][j][1] = 1;
			dpArrUp[1][j][2] = j;

			if (dpArrLeft[1][j - 1][0] + gain[1][j] > gain[1][j]) {
				dpArrLeft[1][j][0] = dpArr[1][j][0] = dpArrLeft[1][j - 1][0] + gain[1][j];
				dpArrLeft[1][j][1] = dpArr[1][j][1] = dpArrLeft[1][j - 1][1];
				dpArrLeft[1][j][2] = dpArr[1][j][2] = dpArrLeft[1][j - 1][2];
			}
			else {
				dpArrLeft[1][j][0] = gain[1][j];
				dpArrLeft[1][j][1] = 1;
				dpArrLeft[1][j][2] = j;
			}

			//max값 갱신

			if (maxVal < dpArrLeft[1][j][0]) {
				maxVal = dpArrLeft[1][j][0];
				maxSize = j - dpArrLeft[1][j][2] + 1;
			}

		}

		for (int i = 2; i <= R; i++) {
			dpArrLeft[i][1][0] = gain[i][1];
			dpArrLeft[i][1][1] = i;
			dpArrLeft[i][1][2] = 1;

			if (dpArrUp[i - 1][1][0] + gain[i][1] > gain[i][1]) {
				dpArrUp[i][1][0] = dpArr[i][1][0] = dpArrUp[i - 1][1][0] + gain[i][1];
				dpArrUp[i][1][1] = dpArr[i][1][1] = dpArrUp[i - 1][1][1];
				dpArrUp[i][1][2] = dpArr[i][1][2] = dpArrUp[i - 1][1][2];
			}
			else {
				dpArrUp[i][1][0] = gain[i][1];
				dpArrUp[i][1][1] = i;
				dpArrUp[i][1][2] = 1;
			}

			//max값 갱신
			if (maxVal <= dpArrUp[i][1][0]) {
				maxVal = dpArrUp[i][1][0];
				if (maxSize > i) maxSize = i;
			}

		}


		for (int i = 2; i <= R; i++) {
			for (int j = 2; j <= C; j++) {
				//자기자신 포함, 위쪽으로
				if (dpArrUp[i - 1][j][0] + gain[i][j] > gain[i][j]) {
					dpArrUp[i][j][0] = dpArrUp[i - 1][j][0] + gain[i][j];
					dpArrUp[i][j][1] = dpArrUp[i - 1][j][1];
					dpArrUp[i][j][2] = dpArrUp[i - 1][j][2];
				}
				else {
					dpArrUp[i][j][0] = gain[i][j];
					dpArrUp[i][j][1] = i;
					dpArrUp[i][j][2] = j;
				}


				//왼쪽으로
				if (dpArrLeft[i][j - 1][0] + gain[i][j] > gain[i][j]) {
					dpArrLeft[i][j][0] = dpArrLeft[i][j - 1][0] + gain[i][j];
					dpArrLeft[i][j][1] = dpArrLeft[i][j - 1][1];
					dpArrLeft[i][j][2] = dpArrLeft[i][j - 1][2];
				}
				else {
					dpArrLeft[i][j][0] = gain[i][j];
					dpArrLeft[i][j][1] = i;
					dpArrLeft[i][j][2] = j;
				}


				//대각선으로 모든 경우 확인해야 함
				int r = dpArr[i][j - 1][1], c = dpArr[i][j - 1][2];

				//직사각형 두개 + 작은 네모 빼기
				//long long sumTmp = sumArr[i][j] - sumArr[i][c - 1] - sumArr[r - 1][j] + sumArr[r - 1][c - 1] -
				//	(sumArr[i - 1][j - 1] - sumArr[i - 1][c - 1] - sumArr[r - 1][j - 1] + sumArr[r - 1][c - 1]);

				long long sumTmp = sumArr[i][j] - sumArr[i][c - 1] - sumArr[r - 1][j] + sumArr[r - 1][c - 1] -
					(sumArr[i][j - 1] - sumArr[i][c - 1] - sumArr[r - 1][j - 1] + sumArr[r - 1][c - 1]);

				//long long sumTmp = sumArr[i][j] - sumArr[i][j - 1] - (sumArr[r - 1][j] - sumArr[r - 1][j - 1]);


				if (dpArr[i][j - 1][0] + sumTmp > gain[i][j]) {
					dpArr[i][j][0] = dpArr[i][j - 1][0] + sumTmp;
					dpArr[i][j][1] = dpArr[i][j - 1][1];
					dpArr[i][j][2] = dpArr[i][j - 1][2];
				}
				else {
					dpArr[i][j][0] = gain[i][j];
					dpArr[i][j][1] = i;
					dpArr[i][j][2] = j;
				}


				//위, 왼쪽, 대각선 중에 큰거 찾기, update

				if (maxVal <= dpArrUp[i][j][0]) {
					maxVal = dpArrUp[i][j][0];
					int tmpMaxSize = (i - dpArrUp[i][j][1] + 1) * (j - dpArrUp[i][j][2] + 1);
					if (maxVal != dpArrUp[i][j][0] || maxSize > tmpMaxSize) maxSize = tmpMaxSize;
				}

				if (maxVal <= dpArrLeft[i][j][0]) {
					maxVal = dpArrLeft[i][j][0];
					int tmpMaxSize = (i - dpArrLeft[i][j][1] + 1) * (j - dpArrLeft[i][j][2] + 1);
					if (maxVal != dpArrLeft[i][j][0] || maxSize > tmpMaxSize) maxSize = tmpMaxSize;
				}

				if (maxVal <= dpArr[i][j][0]) {
					int tmpMaxSize = (i - dpArr[i][j][1] + 1) * (j - dpArr[i][j][2] + 1);
					if (maxVal != dpArr[i][j][0] || maxSize > tmpMaxSize) maxSize = tmpMaxSize;
					maxVal = dpArr[i][j][0];
				}
			}
		}

		long long toPay = maxSize * curCost;

		printf("#%d %d ", tc, maxVal);
		printf("%d\n", toPay);


	}



	return 0;
}
