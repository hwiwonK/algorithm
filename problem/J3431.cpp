//all pairs shortest
#include <iostream>

using namespace std;

const int N_MAX = 100000;
const int INFINITI = 999;
const int Q_MAX = 100000;

int result[Q_MAX + 1] = { 0, };
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
void quickSort(int start, int end, int N) {

	int temp;
	int pivot = start;
	int i = pivot + 1; //왼쪽
	int j = end; //오른쪽

	if (start >= end) return;

	while (i <= j) {
		while (i <= end && tong[sortIdx[i]][0] <= tong[sortIdx[pivot]][0]) {
			i++;
		}
		while (j > start && tong[sortIdx[j]][0] >= tong[sortIdx[pivot]][0]) {
			j--;
		}

		if (i > j) {
			temp = sortIdx[j];
			sortIdx[j] = sortIdx[pivot];
			sortIdx[pivot] = temp;
		}
		else {
			temp = sortIdx[i];
			sortIdx[i] = sortIdx[j];
			sortIdx[j] = temp;
		}
	}

	quickSort(start, j - 1, N);
	quickSort(j + 1, end, N);
}

void grouping(int N) {
	//첫번째 group 1으로
	int groupN = 1;
	int flag = 0;
	int cur = 0;

	group[sortIdx[1]] = groupN;
	groupX2[groupN] = tong[sortIdx[1]][1];
	cur = groupX2[groupN];

	//전체 그룹 세팅해주기
	for (int i = 2; i <= N; i++) {
		//i번째 통나무 그룹 세팅
		/*for (int j = 1; j <= groupN; j++) {*/
		if (cur >= tong[sortIdx[i]][0]) { //그 그룹에 속함
			group[sortIdx[i]] = groupN;
			if (cur < tong[sortIdx[i]][1]) {
				groupX2[groupN] = tong[sortIdx[i]][1];
				cur = groupX2[groupN];
			}
		}
		else { //속한 그룹 없다면
			groupN++;
			group[sortIdx[i]] = groupN;
			groupX2[groupN] = tong[sortIdx[i]][1];
			cur = groupX2[groupN];
		}
	}
}


int main() {

	freopen("input.txt", "r", stdin);

	int N, Q, y, tong1, tong2, tmp;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> tong[i][0] >> tong[i][1] >> y;
		sortIdx[i] = i;
	}

	//x1(시작점) -> 길이 기준 정렬, 오름차순
	//sortTong(N);


	quickSort(1, N, N);

	grouping(N);

	//for (int i = 1; i <= N; i++) {
	//	cout << sortIdx[i] << " ";
	//}

	//cout << endl;

	//======================grouping=========================
	//int groupN = 1;
	//int flag = 0;

	//group[sortIdx[1]] = groupN;
	//groupX2[groupN] = tong[sortIdx[1]][1];

	////전체 그룹 세팅해주기
	//for (int i = 2; i <= N; i++) {
	//	//i번째 통나무 그룹 세팅
	//	/*for (int j = 1; j <= groupN; j++) {*/
	//	if (groupX2[groupN] >= tong[sortIdx[i]][0]) { //그 그룹에 속함
	//		group[sortIdx[i]] = groupN;
	//		groupX2[groupN] = groupX2[groupN] > tong[sortIdx[i]][1] ? groupX2[groupN] : tong[sortIdx[i]][1];
	//	}
	//	else { //속한 그룹 없다면
	//		groupN++;
	//		group[sortIdx[i]] = groupN;
	//		groupX2[groupN] = tong[sortIdx[i]][1];
	//	}
	//}

	for (int i = 1; i <= Q; i++) {
		cin >> tong1 >> tong2;

		if (group[tong1] == group[tong2]) {
			//cout << 1 << endl;
			result[i] = 1;
		}
		else {
			//cout << 0 << endl;
			result[i] = 0;
		}

	}

	for (int i = 1; i <= Q; i++) {
		cout << result[i] << endl;
	}

	return 0;
}
