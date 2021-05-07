#include <iostream>
#include <queue>

using namespace std;


const int N_MAX = 1000000;

int setInfo[N_MAX + 1] = { 0, }; //부모 정보
//int levelCnt[N_MAX + 1] = { 0, }; //각 level 별 node count
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

		//N-1개 정보 받기
		for (int i = 1; i < N; i++) {
			scanf("%d %d", &parent, &child);
			setInfo[child] = parent;
			//setInfo[parent][1] = child;
		}

		// leaf node 찾기
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

		//leaf node grouping 하기

		//모든 leaf node에 대해서 root까지 올라가며 heap 만들기

		for (int leaf = 1; leaf <= leafCnt; leaf++) {

			priority_queue<int, vector<int>, greater<int>> q;

			//root 에 도달할 때까지 heap에 현재 node 넣고, 부모 노드와 비교
			for (int curNode = leafNode[leaf]; curNode != topNode; curNode) {
				//현재 노드 push
				q.push(curNode);

				//부모 노드와 비교
				int parentNode = setInfo[curNode];

				priority_queue<int, vector<int>, greater<int>> tmp = q;
				while (!tmp.empty() && (tmp.top() < parentNode)) {
					tmp.pop();
					resultCnt++;
				}

				//현재 노드 부모 노드로 옮겨주기
				curNode = parentNode;

			}
		
		}

		printf("#%d %d\n", tc, resultCnt);


	}


	return 0;


}
