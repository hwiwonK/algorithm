#include <iostream>

using namespace std;

int arr[100];
int result[100];

//result 배열 선언, 결과값 임시로 저장할 곳

void merge(int *a, int *r, int begin, int mid, int end) {
	int i = begin;
	int j = mid + 1;
	int idx = 0;
	//양쪽 다 남아있음
	while (i <= mid && j <= end) {
		if (a[i] < a[j])
			r[idx++] = a[i++];
		else
			r[idx++] = a[j++];
	}

	//왼쪽만 남아있음
	while (i <= mid) {
		r[idx++] = a[i++];
	}

	//오른쪽만 남아있음
	while (j <= mid) {
		r[idx++] = a[j++];
	}

	idx = 0;
	for (int i = begin; i <= end; i++) {
		a[i] = r[idx++];
	}


}

void mergeSort(int *a, int * r, int begin, int end) {

	if (end - begin <= 0) return;

	int mid = (begin + end) >> 1;

	mergeSort(a, r, begin, mid);
	mergeSort(a, r, mid + 1, end);

	merge(a, r, begin, mid, end);
}


void quickSort(int *a, int begin, int end) {
	int pivot;
	if (begin < end)
		pivot = partition(a, begin, end);

	quickSort(a, begin, pivot - 1);
	quickSort(a, pivot + 1, end);
}

int partition(int *a, int begin, int end) {
	int pivot = a[begin];
	int i = begin;
	int j = end;

	while (i <= j) {
		while (i <= end && a[i] <= pivot) i++;
		while (j >= begin && a[j] > pivot) j--;

		if (i < j)
			swap(a[i], a[j]);
	}

	swap(a[begin], a[j]);
	return j;
}



int main() {

	mergeSort(arr, result, 0, 99);


	return 0;
}
