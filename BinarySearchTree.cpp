#include <iostream>
using namespace std;

struct Node {
	int data;
	Node * left;
	Node * right;
};

Node *root = nullptr;

Node *makeNode(int value) {
	Node *newNode = new Node;
	if (newNode != nullptr) { //newNode 할당 됐다면
		newNode->data = value;
		newNode->left = nullptr;
		newNode->right = nullptr;
	}

	return newNode;
}

Node *searchBST(Node *node, int key) {
	if (node == nullptr) return nullptr;
	if (node->data == key)
		return node;
	else if (node->data > key)
		return searchBST(node->left, key);
	else
		return searchBST(node->right, key);

	return node; // 코드의 안정성을 위해
}


Node *insertBST(Node *node, int value) {
	//삽입하고자 하는 노드로 탐색하고 탐색 실패 위치에 추가한다.
	if (node == nullptr) {
		Node *newNode = makeNode(value);
		return newNode;
	}
	if (node->data < value)
		node->right = insertBST(node->right, value);
	else if (node->data > value)
		node->left = insertBST(node->left, value);
	else {
		//중복되는 경우 ---> 중복 허용하지 않는다
		cout << "Duplicate Key!!\n";
	}

	return node; //나 자신을 return 안하면 nullptr이 return되어서 위쪽 연결 다 끊겨버림
}

void printTree(Node* node, int level, int depth) {
	if (node == nullptr) return;
	if (level < depth) return;

	if (level == depth) {
		printf("%d ", node->data);
	}

	printTree(node->left, level, depth + 1);
	printTree(node->right, level, depth + 1);

}

void printBST(Node *node) {
	const int depth = 5;

	for (int i = 0; i < depth; i++) {
		printTree(node, i, 0);
		cout << endl;
	}
	cout << endl;
}

Node* findMostBiggestNode(Node * node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

Node *deleteBST(Node* node, int value) {
	if (node == nullptr) return nullptr;

	if (node->data < value)
		node->right = deleteBST(node->right, value);
	else if (node->data > value)
		node->left = deleteBST(node->left, value);
	else {
		//삭제 대상 노드를 찾은 경우
		if (node->left != nullptr && node->right != nullptr) {
			//degree 2
			Node *replaceNode = findMostBiggestNode(node->left);
			node->data = replaceNode->data;
			node->left = deleteBST(node->left, replaceNode->data);
		}
		else {
			//degree 1 0
			Node *delNode = node;
			node = node->left;
			if (node == nullptr) { //여기 확인해보기
				node = delNode->right;
			}
			delete delNode;
		}
	}

	return node;
}

int main() {
	//root에 꼭 반환 받아야함
	root = insertBST(root, 9);
	root = insertBST(root, 4);
	root = insertBST(root, 12);
	root = insertBST(root, 15);
	root = insertBST(root, 6);
	root = insertBST(root, 3);
	root = insertBST(root, 13);
	root = insertBST(root, 17);

	//insertBST(root, 9);
	//insertBST(root, 4);
	//insertBST(root, 12);
	//insertBST(root, 15);
	//insertBST(root, 6);
	//insertBST(root, 3);
	//insertBST(root, 13);
	//insertBST(root, 17);

	Node *node = searchBST(root, 6);
	if (node != nullptr) {
		printf("0x%p = %d\n", node, node->data);
	}
	else {
		printf("Not found!!\n");
	}

	printBST(root);

	root = insertBST(root, 5);

	printBST(root);

	root = deleteBST(root, 13);
	printBST(root);

	root = deleteBST(root, 12);
	printBST(root);

	root = deleteBST(root, 9);
	printBST(root);

	return 0;
}
