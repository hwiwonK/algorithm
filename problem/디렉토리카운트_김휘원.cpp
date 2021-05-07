#include <iostream>
#include <queue>

using namespace std;


const int N_MAX = 1000000;

int setInfo[N_MAX + 1] = { 0, }; //�θ� ����
//int levelCnt[N_MAX + 1] = { 0, }; //�� level �� node count
int leafNode[N_MAX + 1] = { 0, };
int leafCnt = 0;

int resultCnt = 0;

//priority_queue<int, vector<int>, greater<int>> q;

int main() {
	freopen("input.txt", "r", stdin);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {

		leafCnt = 0;
		resultCnt = 0;

		int N, topNode;
		int parent, child;

		scanf("%d %d", &N, &topNode);

		//N-1�� ���� �ޱ�
		for (int i = 1; i < N; i++) {
			scanf("%d %d", &parent, &child);
			setInfo[child] = parent;
			//setInfo[parent][1] = child;
		}

		// leaf node ã��
		int flag = 1;
		for (int i = 1; i <= N; i++) {
			for (int node = 1; node <= N; node++) {
				if (setInfo[node] == i) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				leafNode[++leafCnt] = i;
			}

			flag = 1;
		}

		//leaf node grouping �ϱ�

		//��� leaf node�� ���ؼ� root���� �ö󰡸� heap �����

		for (int leaf = 1; leaf <= leafCnt; leaf++) {

			priority_queue<int, vector<int>, greater<int>> q;

			//root �� ������ ������ heap�� ���� node �ְ�, �θ� ���� ��
			for (int curNode = leafNode[leaf]; curNode != topNode; curNode) {
				//���� ��� push
				q.push(curNode);

				//�θ� ���� ��
				int parentNode = setInfo[curNode];

				priority_queue<int, vector<int>, greater<int>> tmp = q;
				while (!tmp.empty() && (tmp.top() < parentNode)) {
					tmp.pop();
					resultCnt++;
				}

				//���� ��� �θ� ���� �Ű��ֱ�
				curNode = parentNode;

			}
		
		}

		printf("#%d %d\n", tc, resultCnt);


	}


	return 0;


}