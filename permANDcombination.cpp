#include <iostream>

using namespace std;

int arr[] = {1, 2, 3, 4, 5};
int t[] = { 0, };

void printArray(int * a, int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//순열 반복
void perm_loop() {
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (j == i) continue;
			for (int k = 1; k < 4; k++) {
				if (k == j || k == i) continue;
				printf("{ %d %d %d }\n", i, j, k);
			}
		}

	}
}

int perm_recursive(int k, int n) {
	if (k == n) { //다 뽑음
		printArray(arr, n);

	}
	else {
		for (int i = k; i < n; i++) {
			swap(arr[i], arr[k]);
			perm_recursive(k + 1, n);
			swap(arr[i], arr[k]);
			//순서가 중요하기 때문에 swap을 되돌린다
		}

	}

}
//순열 재귀


//nPr = n*(n-1)P(r-1)
void perm_fomular(int n, int r, int q) {
	if (r==0) {
		printArray(t, q);//r 값은 변하기 때문에, q를 그대로 가지고 있다가 이용

	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			t[r - 1] = arr[n - 1]; // 제일 앞에 있는 n 구하기
			perm_fomular(n - 1, r - 1, q); // 이후 점화식
			swap(arr[i], arr[n - 1]);//되돌려 놓기
		}
	}
}

//nPIr
void nPIr(int n, int r, int q) {
	if (r == 0) {
		printArray(t, q);//r 값은 변하기 때문에, q를 그대로 가지고 있다가 이용

	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(arr[i], arr[n - 1]);
			t[r - 1] = arr[n - 1]; // 제일 앞에 있는 n 구하기
			perm_fomular(n , r - 1, q); // 이후 점화식, nPr 과 여기만 다르다
			swap(arr[i], arr[n - 1]);//되돌려 놓기
		}
	}
}


//조합 nCr = (n-1)C(r-1) + (n-1)C(r)
void nCr(int n, int r, int q)
{
	if (r==0) {
		printArray(t, q);

	}
	else if (n < r) {
		return;
	}
	else {
		t[r - 1] = arr[n - 1];
		nCr(n - 1, r - 1, q);
		nCr(n - 1, r, q);

	}
}


int main() {

	perm_loop();
	return 0;
}
