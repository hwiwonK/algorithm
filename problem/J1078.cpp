//dfs�� Ǯ ���� : �ð��� �����ϴ� ��쿡�� dfs ��� ����Ǵ� ������� - �����ִ� ���۸� üũ�ϱ� ���ŷӴ�
//����ü ��� ���ص� �� -> queue �� ������ �迭�� �����ϰ� ���� �׸��� ���ÿ� �־��� ���� ����� �� �����

#include <iostream>

using namespace std;

const int N_MAX = 100;

struct  juggling
{
	int y;
	int x;
	int second;
};

int map[N_MAX + 1][N_MAX + 1] = { 0, };
struct juggling queue[N_MAX * N_MAX] = { 0, };
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int front = -1;
int rear = -1;
int juggCnt = 0;

void enqueue(int y, int x, int second) {
	rear++;
	queue[rear].y = y;
	queue[rear].x = x;
	queue[rear].second = second;
}

int bfs(int N, int M) {
	while (front != rear) {

		//�湮�ϱ�
		front++;
		int visitX = queue[front].x;
		int visitY = queue[front].y;
		int visitLevel = queue[front].second;


		//��-��-��-�� üũ
		for (int a = 0; a < 4; a++) {
			int xpos = visitX + d[a][1];
			int ypos = visitY + d[a][0];

			//��輱 üũ
			if (ypos > N || xpos > M || xpos < 1 || ypos < 1) continue;

			if (map[ypos][xpos] == 1) {
				enqueue(ypos, xpos, visitLevel + 1);
				map[ypos][xpos] = 0;
				juggCnt--;

				if (juggCnt == 0) return queue[rear].second;
			}
		}
	}

	return queue[rear].second;
}

int main() {

	freopen("input.txt", "r", stdin);

	int N, M;

	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1) {
				juggCnt++;			
			}
		}
	}

	int a, b;

	cin >> b >> a;

	enqueue(a, b, 3);
	map[a][b] = 0;
	juggCnt--;

	int lastJugg = bfs(N, M);

	printf("%d\n", lastJugg);

	printf("%d\n", juggCnt);

	return 0;
}