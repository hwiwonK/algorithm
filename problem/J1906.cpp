// 공통 조상을 구하느 방법 <br>
// visit 배열 이용하는 방법 -> 이 문제에서는 count 를 저장하면 됨 (촌수 계산 위해) <br>
// level 이용하는 방법 -> 메모리 사용 안해도 됨
// ***부모 정보 저장할 때 굳이 따로 초기화 과정 거칠 필요 없다. 그냥 0으로 해도 됨*

#include <iostream>

using namespace std;

const int N_MAX = 100;

//�θ� ���� ����
int tree[N_MAX + 1] = { 0, };

int findParent(int child1, int child2) {

	int child1Parent[N_MAX] = { 0, };

	//child1 ���� ã��
	int parentCnt1 = 0;

	while (tree[child1] != child1) {
		child1Parent[parentCnt1++] = child1;
		child1 = tree[child1];
	}

	child1Parent[parentCnt1] = child1;


	//child2 ���� ã��
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

	//���� ���� ���� ���
	return -1;
}

int main() {

	freopen("input.txt", "r", stdin);

	int m, a, b, n;

	scanf("%d %d %d %d", &n, &a, &b, &m);

	//tree�迭 setting
	for (int i = 1; i <= n; i++) {
		tree[i] = i;
	}

	int parent, child;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &parent, &child);

		tree[child] = parent;
	}

	//a �� b�� ���� ����� �������� ã��

	printf("%d", findParent(a, b));


	return 0;
}