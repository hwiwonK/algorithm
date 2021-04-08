#include <iostream>

using namespace std;

const int TREE_SIZE = 50;

int tree[TREE_SIZE] = { 0, };
int V;
int E;

int findNode(int node) {
	for (int i = 1; i < TREE_SIZE; i++) {
		if (tree[i] == node)
			return i;
	}
	return -1;
}

void preorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;

	//visit
	cout << tree[node] << " ";

	preorder(node << 1); // L
	preorder(node << 1 | 1); //R
}

void inorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;


	preorder(node << 1); // L
	//visit
	cout << tree[node] << " ";
	preorder(node << 1 | 1); //R
}

void postorder(int node) {
	if (node < 1 || node >= TREE_SIZE) return;
	if (tree[node] == 0) return;


	preorder(node << 1); // L
	preorder(node << 1 | 1); //R
	//visit
	cout << tree[node] << " ";
}

void levelorder(int node) {
	int pow2[] = { 1,2,4,8,16,32,64 };
	int nextLevel = 1;

	for (int i = 1; i < TREE_SIZE; i++) {
		if (i == pow2[nextLevel]) {
			cout << endl;
			nextLevel++;
		}
		if (tree[i]) {
			cout << tree[i] << " ";
		}
	}
}

int main() {
	
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int parent, child;
		cin >> parent >> child;

		int pIdx = findNode(parent);
		if (pIdx < 1) {
			pIdx = 1; //root
			tree[pIdx] = parent;
		}

		if (tree[2 * pIdx] == 0)
			tree[2 * pIdx] = child;
		else
			tree[2 * pIdx + 1] = child;
		
	}


	cout << "전위순회: " << endl;
	preorder(1);

	cout << "중위순회: " << endl;
	preorder(1);

	cout << "후위순회: " << endl;
	preorder(1);



}
