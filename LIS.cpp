#include <iostream>
//=================================================================
//way1
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

//==========================================================================================
//way2 - dp 이용
int getLISdp(int N) {

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j < i; j++) {

			if (line[sortIdx[j]] < line[sortIdx[i]] && LISdp[j][0] + 1 > LISdp[i][0]) {
				LISdp[i][0] = LISdp[j][0] + 1;
				LISdp[i][1] = j;
			}
		}

	}

	//최종 LIS 구하기
	int LISval = -1;
	int LISidx = -1;
	for (int i = N; i >= 1; i--) {
		if (LISdp[i][0] > LISval) {
			LISval = LISdp[i][0];
			LISidx = i;
		}
	}

	return LISidx;

}
