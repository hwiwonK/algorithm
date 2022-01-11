// 처음 생각 : dp 이용하려고 함 <br>
// 1500번 수가 억단위라서 억 단위의 배열 필요 => heap을 이용해야 한다 (1500x3 크기)

#include <iostream>

using namespace std;

const int N_MAX = 1500;
const int HEAP_SIZE = N_MAX * 3 + 1;

long long uglyN[N_MAX + 1] = { 0, };
long long heap[HEAP_SIZE] = { 0, };
int heapcount = 0;
int V;
int E;

long long pop() {
	int parent = 1;
	long long ret = heap[parent];
	heap[parent] = heap[heapcount];
	heap[heapcount--] = 0; //마지막 노드 끌어올리기

	int child = 2 * parent; //left child
	if (child + 1 <= heapcount) {//오른쪽 자식 존재한다면
		child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}

	while (child <= heapcount && heap[parent] > heap[child]) {
		long long tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		parent = child;
		child = parent << 1;
		if (child + 1 <= heapcount) {//오른쪽 자식 존재한다면
			child = (heap[child] < heap[child + 1]) ? child : child + 1;
		}
	}

	return ret;
}

void push(long long value) {
	heap[++heapcount] = value;

	int child = heapcount;
	int parent = child >> 1;

	while (parent > 0 && heap[parent] > heap[child]) {
		long long tmp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = tmp;

		child = parent;
		parent = child >> 1;
	}
}


int main() {

	freopen("input.txt.", "r", stdin);

	int cnt = 0;
	push(1);

	while (cnt < 1500) {

		long long tmp = pop();
		if (tmp != uglyN[cnt]) {
			cnt++;
			uglyN[cnt] = tmp;
			push(tmp * 2);
			push(tmp * 3);
			push(tmp * 5);
		}

	}
	
	while (true) {
		int idx;
		scanf("%d", &idx);

		if (idx == 0) break;

		printf("%d\n", uglyN[idx]);

	}


	return 0;
}
