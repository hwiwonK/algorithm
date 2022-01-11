// dp로 풀려고 했었음 -> 시간 초과(왜 그런지 모르겠음)

#include <iostream>

using namespace std;

const int N_MAX = 100000;

int height[N_MAX + 1] = { 0, };
int result[N_MAX + 1] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);

	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &height[i]);
	}

	result[N] = 0;

	for (int i = N-1; i >= 1; i--) {
		if (height[i] >= height[i + 1]) {
			if (result[i + 1] == 0 || height[i] == height[i+1]) result[i] = result[i+1];
			else if (height[i] < height[result[i + 1]]) {
				result[i] = result[i + 1];
			}
			else {

				for (int k = result[i+1]; k <= N; k) {
					if (height[k] > height[i]) {
						result[i] = k;
						break;
					}
					k = result[k];
				}
			}


		}
		else {
			result[i] = i + 1;

		}


	}



	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}
