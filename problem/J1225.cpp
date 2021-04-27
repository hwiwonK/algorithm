#include <iostream>

using namespace std;

const int N_MAX = 5005;

double pLoc[N_MAX][2] = { 0, }; //사람들 좌표 저장
bool pExist[N_MAX] = { 0, }; //감시 가능 여부

//각 사람들 ~ 레이더 중심 거리
double lader1Dist[N_MAX + 1] = { 0, }; //마지막에는 0 저장
double lader2Dist[N_MAX + 1] = { 0, };

int lader1Sort[N_MAX + 1] = { 0, };
int lader2Sort[N_MAX + 1] = { 0, };

void quickSort(int start, int end, int N, double * arr, int * sortArr) {

	int temp;
	int pivot = start;
	int i = pivot + 1; //왼쪽
	int j = end; //오른쪽

	if (start >= end) return;

	while (i <= j) {
		while (i <= end && arr[sortArr[i]] >= arr[sortArr[pivot]]) {
			i++;
		}
		while (j > start && arr[sortArr[j]] <= arr[sortArr[pivot]]) {
			j--;
		}

		if (i > j) {
			temp = sortArr[j];
			sortArr[j] = sortArr[pivot];
			sortArr[pivot] = temp;
		}
		else {
			temp = sortArr[i];
			sortArr[i] = sortArr[j];
			sortArr[j] = temp;
		}
	}

	quickSort(start, j - 1, N, arr, sortArr);
	quickSort(j + 1, end, N, arr, sortArr);
}

//k보다 작은 값 중 제일 큰 값 찾기
//중복된 값 있다면 제일 앞에걸로
int binarySearch(int low, int high, double k) {
	while (low <= high) {
		int mid = (low + high) / 2;

		if (k >= lader2Dist[lader2Sort[mid]]) high = mid - 1;
		else low = mid + 1;
	}

	while ((lader2Dist[lader2Sort[low]] == lader2Dist[lader2Sort[low - 1]]) && low >=2) {
		low--;
	}

	return low;
}

int countPeople(int lader1, int lader2, int N) {
	//true가 감시 대상인 것
	
	for (int i = 1; i <= N; i++) {
		pExist[i] = false;
	}

	for (int i = lader1; i <= N; i++) {
		pExist[lader1Sort[i]] = true;
	}

	for (int i = lader2; i <= N; i++) {
		pExist[lader2Sort[i]] = true;
	}

	//false의 수 세기
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!pExist[i]) cnt++;
	}

	return cnt;
}

int findResult(int N, double limitR) {

	int minPeople = 9999;

	//시간 좀 더 줄이는 것 생각해보기 - BS 결과값을 다음에 이용
	//lader1 1부터 포함
	for (int lader1 = 1; lader1 <= N + 1; lader1) {
		//연속된 값 있다면 그만큼 lader1에 더해주기, 아니라면 ++
		int lader2 = N + 1;

		double r1 = lader1Dist[lader1Sort[lader1]];
		double r2 = limitR - r1;

		if (r2 >= 0) {
			//가능한 lader2 범위 구하기 - binarySearch
			//모두 불가능 하다면 BS X
			if (lader2Dist[lader2Sort[N]] <= r2) {
				lader2 = binarySearch(1, N, r2);
			}

			//lader1, lader2 이용해서 감시 불가능한 사람 수 구하기
			int peopleTmp = countPeople(lader1, lader2, N);

			if (peopleTmp < minPeople) minPeople = peopleTmp;
		}
		
		//이렇게 해주지 않으면 Runtime Error 발생                       int peopleTmp = countPeople(lader1, lader2, N);

113



114

                        if (peopleTmp < minPeople) minPeople = peopleTmp;

115

                }

116

                

117

                //이렇게 해주지 않으면 Runtime Error 발생  -> 끝 숫자가 0일 경우
		if (lader1Dist[lader1Sort[lader1]] == 0) break;

		while (lader1Dist[lader1Sort[lader1]] == lader1Dist[lader1Sort[lader1 + 1]]) lader1++;
		lader1++;

	}

	return minPeople;

}

void printList(int lader1Cnt, int lader2Cnt) {

	for (int i = 1; i <= lader1Cnt; i++) {
		printf("%.3f ", lader1Dist[lader1Sort[i]]);
	}
	cout << endl;

	for (int i = 1; i <= lader2Cnt; i++) {
		printf("%.3f ", lader2Dist[lader2Sort[i]]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int N;
	double lader1X, lader1Y, lader2X, lader2Y;
	double K; //최대 넓이

	scanf("%d", &N);
	scanf("%lf %lf %lf %lf %lf", &lader1X, &lader1Y, &lader2X, &lader2Y, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%lf %lf", &pLoc[i][1], &pLoc[i][0]);
	}

	//r1^2 + r2^2 최대
	double limitR = K / 3.141;

	//각 사람별로 각 레이더 중심과의 위치 구하기 - 더 가까운 레이더 배열로 넣기
	double tmp1, tmp2;
	double dist1, dist2;

	for (int i = 1; i <= N; i++) {
		tmp1 = pLoc[i][0] - lader1Y;
		tmp2 = pLoc[i][1] - lader1X;
		dist1 = (tmp1 * tmp1) + (tmp2 * tmp2);
		lader1Dist[i] = dist1;

		tmp1 = pLoc[i][0] - lader2Y;
		tmp2 = pLoc[i][1] - lader2X;
		dist2 = (tmp1 * tmp1) + (tmp2 * tmp2);

		lader2Dist[i] = dist2;

	}

	//printf("%d", lader1Cnt + lader2Cnt);


	//lader1과, lader2의 거리 배열 정렬(내림차순)
	for (int i = 1; i <= N; i++) {
		lader1Sort[i] = i;
		lader2Sort[i] = i;
	}


	quickSort(1, N, N, lader1Dist, lader1Sort);
	quickSort(1, N, N, lader2Dist, lader2Sort);

	//printList(N, N);

	int result = findResult(N, limitR);

	printf("%d", result);

	return 0;
}
