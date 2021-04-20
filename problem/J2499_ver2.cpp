//무게가 양의 정수인 N개의 저울추가 주어질 때,
//이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하는 프로그램을 작성하시오.

//(아이디어!) 지금 올리려는 추가 누적합 + 1 보다 크면, 누적합 + 1이 측정할 수 없는 최솟값


#include <iostream>

using namespace std;

const int N_MAX = 1000;
const int WEIGHT_MAX = 1000000;

int chu[N_MAX + 1] = { 0, };


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


int main() {

	freopen("input.txt", "r", stdin);

	int N, result = 1;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &chu[i]);
	}

	//추 정렬하기
	quickSort(1, N);

	if (chu[1] != 1) {
		printf("1\n");
		return 0;
	}

	int weight = 0;

	for (int i = 1; i <= N; i++) {
		if (chu[i] <= weight + 1) {
			weight += chu[i];
		}
		else {
			break;
		}
	}

	printf("%d", weight + 1);

	return 0;
}
