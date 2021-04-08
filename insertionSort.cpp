#include <iostream>

using namespace std;

int insertionSort(int *a, int n) {
	int result = 0;
	for (int i = 1; i < n; i++) {//U의 인덱스
		int j = i - 1;
		int tmp = a[i];

		while (j >= 0 && a[j] > tmp) { //S의 인덱스
			a[j + 1] = a[j];
			j--;
			result++;
		}

		a[j + 1] = tmp;
	}

	return result;
}

int main() {
	int N;
	int arr[50] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = insertionSort(arr, N);

	cout << result;

	return 0;
}
