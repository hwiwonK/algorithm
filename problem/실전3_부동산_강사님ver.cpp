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


		for (int x1 = 1; x1 <= C; x1++) {
			for (int x2 = x1; x2 <= C; x2++) {
				long long tmpSum = 0;
				for (int y = 1, h = 1; y <= R; y++, h++) {
					tmpSum += sumArr[y][x2] - sumArr[y][x1 - 1];
					if (maxVal < tmpSum) {
						maxVal = tmpSum;
						maxSize = (x2 - x1 + 1)*h;
					}

					else if (maxVal == tmpSum) {
						maxSize = maxSize < (x2 - x1 + 1)*h ? maxSize : (x2 - x1 + 1)*h;
					}

					else if (tmpSum < 0) {
						tmpSum = 0;
						h = 0;
					}

				}
			}

		}





		printf("#%d %d ", tc, maxVal);
		printf("%d\n", maxSize * curCost);


	}



	return 0;
}
