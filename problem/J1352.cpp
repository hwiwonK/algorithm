//아이디어 어려움

#include <iostream>

using namespace std;

const int N_MAX = 30;
const int WEIGHT_MAX = 500;

int weightSum[N_MAX + 1] = { 0, };
int chu[N_MAX + 1] = { 0, };

bool dpArr[N_MAX + 1][N_MAX*WEIGHT_MAX] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);

	int chuN;

	scanf("%d", &chuN);

	for (int i = 1; i <= chuN; i++) {
		int tmp;
		scanf("%d", &tmp);
		chu[i] = tmp;
		weightSum[i] = weightSum[i - 1] + tmp;
	}

	//dp
	for (int row = 1; row <= chuN; row++) {
		dpArr[row][chu[row]] = true;

		int limit = weightSum[row - 1];

		for (int col = 1; col <= limit; col++) {
			if (dpArr[row - 1][col]) {
				//추 포함 안함
				dpArr[row][col] = true;

				//현재 추 더하기
				dpArr[row][col + chu[row]] = true;

				//반대쪽에 추 놓기
				int abs = col - chu[row] > 0 ? col - chu[row] : chu[row] - col;
				dpArr[row][abs] = true;

			}

		}

	}


	//구슬 입력, 출력은 나중에
	int bubbleN, bubbleWeight;
	scanf("%d", &bubbleN);
	for (int i = 1; i <= bubbleN; i++) {
		scanf("%d", &bubbleWeight);

		if (dpArr[chuN][bubbleWeight]) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
		
	}

	return 0;
}
