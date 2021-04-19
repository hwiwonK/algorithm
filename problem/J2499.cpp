//무게가 양의 정수인 N개의 저울추가 주어질 때,
//이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하는 프로그램을 작성하시오.

#include <iostream>

using namespace std;

const int N_MAX = 1000;
const int WEIGHT_MAX = 1000000;

int chu[N_MAX + 1] = { 0, };
int sumArr[N_MAX] = { 0, };
bool ifExist[WEIGHT_MAX+1] = { false, };


//quickSort
void quickSort(int start, int end) {

	int temp;
	int pivot = start;
	int i = pivot + 1; //왼쪽
	int j = end; //오른쪽

	if (start >= end) return;

	while (i <= j) {
		while (i <= end && chu[i] <= chu[pivot]) {
			i++;
		}
		while (j > start && chu[j] >= chu[pivot]) {
			j--;
		}

		if (i > j) {
			temp = chu[j];
			chu[j] = chu[pivot];
			chu[pivot] = temp;
		}
		else {
			temp = chu[i];
			chu[i] = chu[j];
			chu[j] = temp;
		}
	}

	quickSort(start, j - 1);
	quickSort(j + 1, end);


}



int greedy(int N, int weight) {

	for (int i = N; i >= 1 && weight != 0; i--) {

		if (sumArr[i] < weight) return -1;

		if (weight >= chu[i]) {
			weight = weight - chu[i];
		}
	}

	if (weight == 0) return 1;
	else return -1;
}

int main() {

	freopen("input.txt", "r", stdin);

	int N, result = 1, weight = 1;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> chu[i];
		ifExist[chu[i]] = true;
	}

	//추 정렬하기
	//chuSort(N);
	quickSort(1, N);

	//sumArr 구하기
	for (int i = 1; i <= N; i++) {
		sumArr[i] = sumArr[i - 1] + chu[i];
	}

	int limit = chu[N];
	for (weight = 1; weight <= limit && result == 1; weight++) {
		if (!ifExist[weight]) {
			result = greedy(N, weight);
		}
	}


	if (result == -1) {
		cout << weight - 1;

		return 0;
	}
	else {
		while (result > 0) {
			result = greedy(N, weight);
			weight++;
		}
	}


	cout << weight - 1;

	return 0;
}
