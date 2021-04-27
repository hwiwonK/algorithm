//====================================================================
//indexing 이용하기

void quickSort(int start, int end, int N) {

	int temp;
	int pivot = start;
	int i = pivot + 1; //왼쪽
	int j = end; //오른쪽

	if (start >= end) return;

	while (i <= j) {
		while (i <= end && lineA[sortIdx[i]] <= lineA[sortIdx[pivot]]) {
			i++;
		}
		while (j > start && lineA[sortIdx[j]] >= lineA[sortIdx[pivot]]) {
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

//========================================================================
//indexing 이용하기
void quickSort(int start, int end, int N) {

	int temp;
	int pivot = start;
	int i = pivot + 1; //왼쪽
	int j = end; //오른쪽

	if (start >= end) return;

	while (i <= j) {
		while (i <= end && lader1Dist[i] <= lader2Dist[pivot]) {
			i++;
		}
		while (j > start && lader1Dist[j] >= lader2Dist[pivot]) {
			j--;
		}

		if (i > j) {
			temp = j;
			j = pivot;
			pivot = temp;
		}
		else {
			temp = i;
			i = j;
			j = temp;
		}
	}

	quickSort(start, j - 1, N);
	quickSort(j + 1, end, N);
}
