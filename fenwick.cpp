#include <iostream>

using namespace std;

int t_size;

int getMax(int * tree, int left, int right) {
	int result = 0;
	int tmp;
	for (left += t_size, right += t_size; left <= right; left >>= 1, right >>= 1) {
		if (left & 1) {
			tmp = tree[left++];
			if (tmp > result) result = tmp;
			//left++;
		}
		if (!(right & 1)) {
			tmp = tree[right--];
			if (tmp > result) result = tmp;
			//right--;
		}
	}

	return result;
}

int main() {

	freopen("input.txt", "r", stdin);

	int N, Q;
	cin >> N >> Q;

	int t[100000] = { 0, };
	//int results[]

	t_size = N - 1;
	//int *t = new int[2 * N];

	//t[0] = 0;

	for (int i = 1; i <= N; i++) {
		cin >> t[t_size + i];
	}

	//트리 구성
	for (int i = N - 1; i > 0; i--) {
		int L = t[i << 1];
		int R = t[i << 1 | 1];
		t[i] = (L > R) ? L : R; //큰거 세팅
	}

	for (int i = 1; i <= Q; i++) { //Q개의 입력 받기
		int left, right;
		cin >> left >> right;

		//int result = getMax(t, left, right);
		int result = getMax(t, left, right);
		cout << result << endl;
	}

	return 0;
}
