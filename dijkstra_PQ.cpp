#include <iostream>

using namespace std;

const int VERTEX = 10;
const int INFINITI = 999;
int A[VERTEX][VERTEX] = { 0, }; //인접 행렬
int D[VERTEX] = { 0, }; //거리 갱신
bool U[VERTEX] = { false, }; //visit 배열 같은 것, 선택 정점 집합
int V; //정점의 총 수


//힙 정의했던 것 붙여넣기
//push할 때 indexing 이용하는 방법으로 코드 수정하기
//child = D[heap[child]] < D[heap[child+1]] -> child: child+1;
//선택 되지 않은 정점 중에서 거리 최소인 정점 고르기

void printDistance() {
	for (int i = 0; i < V; i++) {
		printf("%3c", 'A' + i);
	}
	printf("\n");

	for (int i = 1; i <= V; i++) {
		printf("%3d", D[i]);
	}
	printf("\n");
}

int dijkstra_pq(int s) {
	//U[s] = true;

	//for (int v = 1; v <= V; v++) {
	//	D[v] = A[s][v];
	//}

	D[s] = 0; // 출발지 가중치가 0으로 안되어있는 경우도 있음. 반드시 해주기

	push(s);

	while (heapCount>0) {
		int w = pop(); //우선순위 큐 필요 (but 뒤에서 계속 갱신 일어남)

		if (U[w] == false) {//이거 없어도 됨
			U[w] = true;

			for (int v = 1; v <= V; v++) {
				if (A[w][v] != INFINITI && D[v] > A[w][v] + D[w]) {
					D[v] = A[w][v] + D[w];
					push(v);
				}
			}
		}
	}
}

int main() {
	freopen("dijkstra_input.txt", "r", stdin);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cin >> A[i][j];
			if (i != j && A[i][j] == 0) {
				A[i][j] = INFINITI;
			}

		}
	}

	int distance = dijkstra_pq(1);

	cout << "최단거리 : " << distance << endl;


	return 0;
}
