#include <iostream>

using namespace std;

const int N_MAX = 500000;

int line[N_MAX + 1] = { 0, };
int LIS[N_MAX + 1][2] = { 0, };
int result[100001] = { 0, }; //LIS저장


//DP 이용하기
int getLIS(int N) {
	int lenLIS = 0;

	for (int i = 1; i <= N; i++) {
		if (line[i] == 0) continue;
		if (lenLIS == 0 || LIS[lenLIS - 1][0] < line[i]) {
			LIS[lenLIS][1] = i;
			LIS[lenLIS++][0] = line[i]; //크면 그냥 뒤에 붙이기
		}
		else { //자신보다 큰 것 중 가장 작은 애에 덮어 씌우기
			int low = 0;
			int high = lenLIS - 1;

			while (low <= high) {
				int mid = (low + high) / 2;
				if (line[i] > LIS[mid][0]) low = mid + 1;
				else high = mid - 1;
			}

			LIS[low][0] = line[i];
			LIS[low][1] = i;
		}
	}

	return lenLIS;

}


int main() {
	freopen("input.txt", "r", stdin);

	int N, start, end, maxLine = -1;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &start, &end);
		if (end > maxLine) maxLine = end;
		if (start > maxLine) maxLine = start;
		line[start] = end;
	}

	for (int i = 1; i <= maxLine; i++) {
		if (line[i] != 0) LIS[i][0] = 1;
	}

	//LIS 길이 찾기
	int idx = getLIS(maxLine); //길이는 idx
	int LISval = LIS[idx][0];

	printf("%d\n", N - idx);


	/*for (int i = 1; i <= maxLine; i++) {
		cout << LIS[i][0] << " ";
	}*/

	// LIS 구하기
	result[idx-1] = LIS[idx-1][1];

	for (int i = idx-2; i >= 0; i--) {
		//if (LIS[i][1] < LIS[i + 1][1]) {
		//	result[i] = LIS[i][1];
		//}
		if (LIS[i][1] < result[i + 1]) {
			result[i] = LIS[i][1];
		}
		else {
			int val = line[result[i + 1]];
			int j = result[i + 1] - 1;
			int lowerbound = i-1;
			
			while ((LIS[lowerbound][1] > j || line[lowerbound] == 0) && lowerbound>=1) {
				lowerbound--;
			}

			int k;
			int maxVal = -1;
			int maxIdx = -1;
			for (k = j; k > LIS[lowerbound][1]; k--) {
				if (line[k] == 0) continue;
				if (line[k] < val && maxVal < line[k]) {
					maxVal = line[k];
					maxIdx = k;
				}
			}

			result[i] = maxIdx;
		}

	}

	//for (int i = 0; i < idx; i++) {
	//	printf("%d ", result[i]);
	//}
	
	for (int i = 0; i < idx; i++) {
		line[result[i]] = 0;
	}

	for (int i = 1; i <= maxLine; i++) {
		if (line[i] != 0) printf("%d\n", i);
	}

	return 0;
}
