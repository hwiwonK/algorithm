#include <iostream>

using namespace std;

const int N_MAX = 1000;
bool input[N_MAX + 1][N_MAX + 1] = { 0, };
pair <int, int>	result[N_MAX + 1][N_MAX + 1]; //�˾Ƽ� 0���� �ʱ�ȭ
int dc[4] = { 0, 0, -1, 1 };
int dr[4] = { -1, 1, 0, 0 };

pair <int, int> queue[N_MAX * N_MAX];
int front = -1;
int rear = -1;

void printList(bool arr[][N_MAX + 1], int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

//dfs - ��ͷ� ����
void findPath(int N, int row, int col, int i, int j) {
	//input[row][col]���� �� �� �ִ� ���� ��� üũ

	//���� �� �湮 üũ & ���
	input[i][j] = true;
	result[i][j] = make_pair(row, col);

	//��-��-��-�� �湮 ���ɽ� �湮
	for (int dir = 0; dir < 4; dir++) {
		int rPos = i + dr[dir];
		int cPos = j + dc[dir];

		if (rPos < 1 || rPos > N || cPos < 1 || cPos > N) continue;

		if (!input[rPos][cPos]) findPath(N, row, col, rPos, cPos);

	}

}

void findPathBfs(int N, int row, int col, int i, int j) {
	//input[row][col]���� �� �� �ִ� ���� ��� üũ

	//���� �� push �ϱ�
	queue[++rear] = make_pair(i, j);
	input[row][col] = true;
	result[row][col] = make_pair(row, col);

	while (front != rear) {
		//pop �ؼ� �湮�ϱ�
		pair <int, int> tmp = queue[++front];

		for (int dir = 0; dir < 4; dir++) {
			int rPos = tmp.first + dr[dir];
			int cPos = tmp.second + dc[dir];

			if (rPos < 1 || rPos > N || cPos < 1 || cPos > N) continue;

			if (!input[rPos][cPos]) {
				input[rPos][cPos] = true;
				result[tmp.first][tmp.second] = make_pair(row, col);
				queue[++rear] = make_pair(rPos, cPos);
			}

		}
	}

	front = -1;
	rear = -1;
}


int main() {

	freopen("input.txt", "r", stdin);

	int T, N, M;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {

		//�Է� �ޱ�
		scanf("%d %d", &N, &M);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &input[i][j]);
			}
		}

		//printList(input, N);

		/*for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				printf("%d %d || ", result[i][j].first, result[i][j].second);
			}
			printf("\n");
		}*/

		//0�߰��ϸ�, �� �������� �� �� �ִ� ��� �� Ž��
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!input[i][j]) {
					findPathBfs(N, i, j, i, j);
				}
			}
		}

		//M input �ް� ��� ���

		printf("#%d ", tc);

		for (int q = 1; q <= M; q++) {
			int startR, startC, endR, endC;
			scanf("%d %d %d %d", &startR, &startC, &endR, &endC);

			if (result[startR][startC] == result[endR][endC]) printf("1 ");
			else printf("0 ");
		}

		printf("\n");
	}



	return 0;
}