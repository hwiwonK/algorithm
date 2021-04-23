#include <iostream>

using namespace std;

const int N_MAX = 100;

//부모 정보 저장
int tree[N_MAX + 1] = { 0, };

int findParent(int child1, int child2) {

	int child1Parent[N_MAX] = { 0, };

	//child1 조상 찾기
	int parentCnt1 = 0;

	while (tree[child1] != child1) {
		child1Parent[parentCnt1++] = child1;
		child1 = tree[child1];
	}

	child1Parent[parentCnt1] = child1;


	//child2 조상 찾기
	int child2Parent[N_MAX] = { 0, };

	int parentCnt2 = 0;

	while (tree[child2] != child2) {
		child2Parent[parentCnt2++] = child2;
		child2 = tree[child2];
	}

	child2Parent[parentCnt2] = child2;

	for (int i = 0; i <= parentCnt1; i++) {
		for (int j = 0; j <= parentCnt2; j++) {
			if (child1Parent[i] == child2Parent[j]) {
				return i + j;
			}
		}
	}

	//공통 조상 없을 경우
	return -1;
}

int main() {

	freopen("input.txt", "r", stdin);

	int m, a, b, n;

	scanf("%d %d %d %d", &n, &a, &b, &m);

	//tree배열 setting
	for (int i = 1; i <= n; i++) {
		tree[i] = i;
	}

	int parent, child;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &parent, &child);

		tree[child] = parent;
	}

	//a 와 b의 가장 가까운 공통조상 찾기

	printf("%d", findParent(a, b));


	return 0;
}