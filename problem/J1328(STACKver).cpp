//아이디어 어려움 - stack으로 품
//dp로도 풀어보기

#include <iostream>

using namespace std;

const int N_MAX = 100000;

int height[N_MAX + 1] = { 0, };
int result[N_MAX + 1] = { 0, };

struct building {
	int idx;
	int height;
};

struct building stack[N_MAX + 1] = { 0, };

int front = -1;
int rear = -1;

void push(int i, int h) {
	stack[++rear] = { i, h };
}


int main() {
	freopen("input.txt", "r", stdin);

	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &height[i]);
	}

	push(1, height[1]);

	for (int i = 2; i <= N; i++) {
		while (stack[rear].height < height[i] && front!=rear) {
			result[stack[rear].idx] = i;
			rear--;
		}

		//현재 push하기
		push(i, height[i]);
	}

	//stack에 남은 것들 0으로
	while (front != rear) {
		result[stack[rear].idx] = 0;
		rear--;
	}


	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}
