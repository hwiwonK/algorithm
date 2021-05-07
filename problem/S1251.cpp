#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
const double INFINITI = 9999999;
const int N_MAX = 1001;

//pq.push(), pq.pop(), 
int location[N_MAX][2] = { 0, }; //��ǥ ����
double distanceArr[N_MAX][N_MAX] = { 0, }; //�� �� �Ÿ� ����
//int disjoint[N_MAX][2] = { 0, }; //�θ�� ���� �Ÿ� ���� (�θ� ���� �ʿ�����..)

struct Island {
	int n; //�� ��ȣ
	double distance; //�Ÿ� �������� ����
	int parent; //���� �ʿ�����..
};

struct cmp {
	bool operator()(Island a, Island b) {
		return a.distance < b.distance;
	}
};

void prim(int N, int v, struct Island* disjoint) {
	priority_queue<Island, vector<Island>, cmp> pq;
	struct Island u;
	//disjoint �迭 �ʱ�ȭ�ϱ�
	for (int i = 1; i <= N; i++) {
		disjoint[i].n = i;
		disjoint[i].distance = INFINITI;
		disjoint[i].parent = NULL;
	}

	//ù��° ��� �湮�ϱ�
	disjoint[v].distance = 0;
	pq.push(disjoint[v]);

	while (!pq.empty()) {
		//���� �Ÿ� ���� �� �̱�
		u = pq.top();
		pq.pop();
		
		//�Ÿ� ����
		for (int i = 1; i <= N; i++) {
			if (i == u.n) continue;
			if (disjoint[i].distance > distanceArr[u.n][i]) {
				disjoint[i].distance = distanceArr[u.n][i];
				disjoint[i].parent = u.n;
				pq.push(disjoint[i]);
			}
		}
	}
}

int main() {
	int T, tc, N;
	double result, E;
	struct Island disjoint[N_MAX];
	freopen("input.txt", "r", stdin);
	
	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		int Xpos, Ypos;
		cin >> N; //���� ����

		for (int i = 1; i <= N; i++) {
			cin >> location[i][0];
		}

		for (int i = 1; i <= N; i++) {
			cin >> location[i][1];
		}

		cin >> E; //ȯ�� �δ� ����

		//�Ÿ� ���ϱ�
		double subX, subY, distTmp;
		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				subX = (double)(location[i][0] - location[j][0]);
				subY = (double)(location[i][1] - location[j][1]);
				distTmp = sqrt(subX * subX + subY * subY);
				distanceArr[i][j] = distTmp;
				distanceArr[j][i] = distTmp;
			}
		}

		prim(N, 1, disjoint); //���� 1���� ����
		result = 0;
		for (int i = 1; i <= N; i++) {
			result += (disjoint[i].distance) * (disjoint[i].distance) * E;
		}

		printf("#%d %.f\n", tc, result);
		//cout << result << endl;
	}


	return 0;
}