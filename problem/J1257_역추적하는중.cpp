#include <iostream>

using namespace std;

const int N_MAX = 500000;

int line[N_MAX + 1] = { 0, };
int LIS[N_MAX + 1][2] = { 0, };
bool result[N_MAX + 1] = { 0, }; //그 숫자 배열에 있는지 없는지 저장
int backtrace[N_MAX + 1] = { 0, }; //역추적 위한 idx 저장 배열


//DP 이용하기
int getLIS(int N) {
	int lenLIS = 0;

	for (int i = 1; i <= N; i++) {
		if (line[i] == 0) continue;
		if (lenLIS == 0 || LIS[lenLIS - 1][0] < line[i]) {
			backtrace[i] = lenLIS;
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
			backtrace[i] = low;
		}
	}

	return lenLIS;

}


void getFinalLIS(int maxLine, int lenLIS) {

	//for (int i = lenLIS-1; i >= 0; i--) {

	//}


}

int main() {
	freopen("input2.txt", "r", stdin);

	int N, start, end, maxLine = -1;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &start, &end);
		if (end > maxLine) maxLine = end;
		if (start > maxLine) maxLine = start;
		line[start] = end;
		result[start] = true;
	}

	for (int i = 1; i <= maxLine; i++) {
		if (line[i] != 0) LIS[i][0] = 1;
	}

	//LIS 길이 찾기
	int lenLIS = getLIS(maxLine); //길이는 idx

	printf("%d\n", N - lenLIS);


	/*for (int i = 1; i <= maxLine; i++) {
		cout << LIS[i][0] << " ";
	}*/



	//역추적하기
	getFinalLIS(maxLine, lenLIS);


	//for (int i = 0; i < idx; i++) {
	//	printf("%d ", result[i]);
	//}

	/*for (int i = 0; i < idx; i++) {
		line[result[i]] = 0;
	}

	for (int i = 1; i <= maxLine; i++) {
		if (line[i] != 0) printf("%d\n", i);
	}*/

	return 0;
}
