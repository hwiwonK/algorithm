#include <iostream>

using namespace std;

const int N = 5;
const int CANDIDATE = N;

//int src[] = { 1,2,3 };

//a는 선택집합- 현재까지 선택된 부분해
//k는 선택집합에 포함된 해의 수, backtrack이 호출된 깊이
//n은 모든 선택 수, 뽑아야 될 숫자

int make_candidate(int a[], int k, int n, int c[]) {
	//순열 : nPr = n*(n-1)*(n-2)*...*1 = n*(n-1)P(r-1) (r<=n)
	//순열의 핵심 : 앞에서 선택한 것을 제외한 나머지가 다음 선택 대상이 된다.
	
	int inPerm[N+1] = { 0, }; //a[]에 포함된 값을 체크하기 위한 배열 선언
	for (int i = 1; i < k; i++) {
		inPerm[a[i]]++; //true로 마킹
	}

	int nCands = 0;
	for (int i = 1; i <= n; i++) {
		if (inPerm[i] == 0) { //a[]에 포함되지 않은 값이면
			c[nCands] = i;
			nCands += 1;
		}
	}

	return nCands;
}

void process_solution(int a[], int k, int n) {
	cout << " {";
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			//cout << i << " "; //원본 배열에 대한 인덱스 값을 생성하고 있다
			//cout << src[i - 1] << " ";
			cout << a[i] << " ";
		}
	}
	cout << "} \n";
}

void backtrack(int a[], int k, int n) {
	int c[CANDIDATE] = { 0, }; // 후보해 집합 // 이게 전역 변수가 아니라, 호출되는 함수별로 별도로 candidate 배열 가지고 있음
	int nCands = 0; //후보해 집합에 포함된 원소의 수

	if (k == n) {
		process_solution(a, k, n);
	}
	else {
		k++;
		//k번째 자리에 1~N 까지의 수가 올 수 있다! (순서 고려하기 때문에)
		nCands = make_candidate(a, k, n, c); //후보해 생성
		for (int i = 0; i < nCands; i++) {
			a[k] = c[i]; //후보해 중에 하나를 선택집합에 추가
			backtrack(a, k, n);
		}
	}

}

int main() {

	int a[N + 1] = { 0, };
	backtrack(a, 0, 3);

	return 0;
}
