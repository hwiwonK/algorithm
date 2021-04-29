/// === user.cpp ===

#ifndef NULL
#define NULL 0
#endif
const int SIZE = 100010;
struct Node {
	int num;
	Node* next;
}buf[SIZE];
int bcnt;

struct Stack {
	Node*head;
	int cnt;
}stkObject;

Stack* newStack() {
	stkObject.cnt = 0;
	stkObject.head = &buf[1]; //head가 제일 앞 가리키게
	bcnt = 0;
	return &stkObject;
}

void delStack(Stack*stk) {
	stk->head = nullptr;
	stk->cnt = 0;
}

bool empty(Stack*stk) {
	if (stk->cnt == 0) {
		return true;
	}
	else {
		return false;
	}
}

int size(Stack*stk) {
	return stk->cnt;
}

int top(Stack*stk) {
	return stk->head->num;
}

//현재 노드를 head에 연결, head 위치 조정
void push(Stack*stk, int num) {
	bcnt++;
	buf[bcnt].num = num;
	buf[bcnt].next = stk->head;

	stk->head = &buf[bcnt];
	stk->cnt++;
}

void pop(Stack*stk) {
	if (empty(stk)) {
		return;
	}
	stk->head = stk->head->next;
	stk->cnt--;
}
