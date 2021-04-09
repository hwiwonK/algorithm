#include <iostream>

using namespace std;

const int N = 100;
const int CANDIDATE = 2;

int K;

int make_candidate(int a[], int k, int n, int c[]) {
	c[0] = 1; //포함되는 경우
	c[1] = 0; //포함되지 않는 경우

	return 2;
}

int cnt;
void process_solution(int a[], int k, int n) {
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			sum += i;
		}
	}

	if (sum == K) {
		cnt++;
		/*cout << " {";
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				cout << i << " ";
			}
		}
		cout << "} \n";*/
	}
}


//a는 선택집합- 현재까지 선택된 부분해
//k는 선택집합에 포함된 해의 수, backtrack이 호출된 깊이
//n은 모든 선택 수, 뽑아야 될 숫자
void backtrack(int a[], int k, int n, int cSum, int tSum) {
	int c[CANDIDATE] = { 0, }; // 후보해 집합
	int nCands = 0; //후보해 집합에 포함된 원소의 수

	//가지치기
	if (cSum > K) return; //현재까지 고려한 값을 가지고 찾은 조건
	if (cSum + tSum < K) return;
	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;

		nCands = make_candidate(a, k, n, c); //후보해 생성
		for (int i = 0; i < nCands; i++) {
			a[k] = c[i]; //후보해 중에 하나를 선택집합에 추가 (a[k]가 1이면, 부분집합에 k 값 있는것)

			int num = 0;

			if (a[k] == 1) {
				num = k;
			}

			// 재귀호출의 횟수를 줄여라
			if (cSum + num <= K || cSum + tSum >= K) {
				backtrack(a, k, n, cSum + num, tSum - k);
			}
		}
	}

}

int main() {

	int a[N + 1] = { 0, };
	int tSum = N * (N + 1) / 2; //1부터 N까지의 합
	K = 100;

	backtrack(a, 0, N, 0, tSum);

	cout << cnt << endl;

	return 0;
}
