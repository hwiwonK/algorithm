#include <iostream>

using namespace std;

const int TREE_SIZE = 50;

int tree[TREE_SIZE] = { 0, };
int V;
int E;

int findNode(int v) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == v) return i;
	}
	return 1; //못찾으면 root index 반환
}

void preorder(int i) {
	//i는 방문중인 인덱스
	if (i < 1 || i >= TREE_SIZE) return;
	if (tree[i] == 0) return;

	//visit
	cout << tree[i] << " ";

	preorder(i << 1);
	preorder(i << 1 | 1);

}

void inorder(int i) {
	//i는 방문중인 인덱스
	if (i < 1 || i >= TREE_SIZE) return;
	if (tree[i] == 0) return;

	//visit
	inorder(i << 1);
	cout << tree[i] << " ";
	inorder(i << 1 | 1);

}

void postorder(int i) {
	//i는 방문중인 인덱스
	if (i < 1 || i >= TREE_SIZE) return;
	if (tree[i] == 0) return;

	postorder(i << 1);
	postorder(i << 1 | 1);
	//visit
	cout << tree[i] << " ";
}

void levelorder(int i) {
	int nextLevel = 1;
	if (i == nextLevel) nextLevel *= 2;

	for (int i = 1; i < TREE_SIZE; i++) {
		if (i == nextLevel) {
			nextLevel *= 2;
			cout << endl;
		}
		cout << tree[i] << " "; // 0이 아닐 때!
	}

}


int main() {

	// V, E 받고 parent, child 로 입력받기
	// 데이터 순서대로 들어온다고 가정할 때

	int V, E;
	int parent, child;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> parent >> child;
		//parent 정보를 찾을 수 없을 때 -> 루트

		int pIdx = findNode(parent);
		//parent의 위치 찾기
		
		tree[pIdx] = parent;
		int childLeft = pIdx << 1;

		if (tree[childLeft] == 0) {
			tree[childLeft] = child;
		}
		else {
			tree[childLeft + 1] = child;
		}
	}

	//전위순회
	preorder(1);

	//중위순회


	//후위순회

	return 0;
}
