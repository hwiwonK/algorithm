//all pairs shortest
#include <iostream>

using namespace std;

const int N_MAX = 100000;
const int INFINITI = 999;

int tong[N_MAX + 1][2] = { 0, };
int sortIdx[N_MAX + 1] = { 0, };
int group[N_MAX + 1] = { 0, };
int groupX2[N_MAX + 1] = { 0, };
//int sortIdx2[N_MAX + 1] = { 0, }; //x2 기준
//int maxLen[N_MAX + 1] = { 0, }; //각 인덱스까지 중 길이 max인 통나무 인덱스 저장

void sortTong(int N) {
	int minIdx = -1;
	int minVal = 2099999999;
	int tmp = -1;

	for (int i = 1; i <= N; i++) {
		sortIdx[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		minIdx = i;
		minVal = tong[sortIdx[minIdx]][0];

		for (int j = i + 1; j <= N; j++) {
			if (tong[sortIdx[j]][0] <= minVal) {
				if (tong[sortIdx[j]][0] == minVal) {
					if (tong[sortIdx[minIdx]][1] - tong[sortIdx[minIdx]][0] > tong[sortIdx[j]][1] - tong[sortIdx[j]][0]) {
						minIdx = j;
						minVal = tong[sortIdx[minIdx]][0];
					}

				}
				else {
					minIdx = j;
					minVal = tong[sortIdx[minIdx]][0];
				}
			}
		}

		//idx swap하기
		tmp = sortIdx[i];
		sortIdx[i] = sortIdx[minIdx];
		sortIdx[minIdx] = tmp;
	}

}


//quick sort로 구현해보기



int jump(int tong1, int tong2, int N) {
	
	int nextTong, tong1SortIdx, tong2SortIdx;

	for (int i = 1; i <= N; i++) {
		if (sortIdx[i] == tong1) {
			tong1SortIdx = i;
		}
		if (sortIdx[i] == tong2) {
			tong2SortIdx = i;
		}
	}

	//tong1 index에서 tong2 index 사이 통나무 생각하기

	for (int i = tong1SortIdx; i < tong2SortIdx; i++) {
		if (tong[sortIdx[i]][1] < tong[sortIdx[i+1]][0]) {
			return 0;
		}
	}

	return 1;
}

void grouping(int N) {



}

int main() {

	freopen("input.txt", "r", stdin);

	int N, Q, y, tong1, tong2, tmp;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> tong[i][0] >> tong[i][1] >> y;
	}
	
	//x1(시작점) -> 길이 기준 정렬, 오름차순
	sortTong(N);

	grouping(N);

	for (int i = 1; i <= Q; i++) {
		cin >> tong1 >> tong2;

		if (tong[tong2][0] < tong[tong1][0]) {
			tmp = tong2;
			tong2 = tong1;
			tong1 = tmp;
		}

		if (tong[tong1][1] >= tong[tong2][0]) {
			cout << 1 << endl;
		}
		else {
			cout << jump(tong1, tong2, N) << endl;
		}
	}

	return 0;
}
