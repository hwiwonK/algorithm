#include <iostream>

using namespace std;

const int N_MAX = 50000;
int parent[N_MAX + 1] = { 0, };
int rankS[N_MAX + 1] = { 0, };
bool check[N_MAX + 1] = { 0, };

void makeSet(int a) {
	parent[a] = a;
	rankS[a] = 1;
}

int findSet(int a) {
	if (parent[a] != a) {
		parent[a] = findSet(parent[a]);
	}
	
	return parent[a];
}

void unionSet(int a, int b, int aRoot, int bRoot) {

	if (rankS[aRoot] >= rankS[bRoot]) { //b를 a에 붙이기
		if (rankS[aRoot] == rankS[bRoot]) {
			rankS[aRoot]++;
			parent[bRoot] = aRoot;
		}
		else {
			parent[bRoot] = aRoot;
		}
	}
	else
	{
		parent[aRoot] = bRoot;
	}

}

int main() {
	freopen("input.txt", "r", stdin);

	int N, M;
	int a, b;
	int aRoot, bRoot;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		makeSet(i);
	}

	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		aRoot = findSet(a);
		bRoot = findSet(b);
		
		unionSet(a, b, aRoot, bRoot);
		
	}

	int regionCnt = 0;

	for (int i = 1; i <= N; i++) {
		if (check[findSet(i)] == false) {
			regionCnt++;
			check[findSet(i)] = true;
		}
	}

	cout << regionCnt << endl;

	return 0;
}

//if (aRoot == bRoot) {
//	if (aRoot == 0) {
//		makeSet(a);
//		makeSet(b);
//		parent[b] = a;
//		rankS[a] = 2;
//	}
//}
//else { //a와 b의 root가 다를 때
//	if (aRoot == 0) { //a를 만들고 b에 붙인다
//		makeSet(a);
//		unionSet(a, b, a, bRoot);
//		//rankS[bRoot]++;
//		//parent[a] = bRoot;
//	}
//	else if (bRoot == 0) {
//		makeSet(b);
//		unionSet(a, b, aRoot, b);
//	}
//	else {
//		unionSet(a, b, aRoot, bRoot);
//	}
