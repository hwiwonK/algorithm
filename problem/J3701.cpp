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

struct Queue {
	Node*head, *tail;
	int cnt;
}que;

Queue* newQueue() {
	que.cnt = 0;
	que.head = &buf[0]; //head가 제일 앞 가리키게
	que.tail = &buf[0];
	bcnt = 0;
	return &que;
}

void delQueue(Queue*que) {
	//que 삭제
	que->head = nullptr;
	que->tail = nullptr;
	que->cnt = 0;
}

bool empty(Queue*que) {
	if (que->cnt == 0) {
		return true;
	}
	else {
		return false;
	}
}

int size(Queue*que) {
	return que->cnt;
}

int front(Queue*que) {

	return que->head->next->num;
}

int back(Queue*que) {

	return que->tail->num;
}

//buf[++cnt]에 정의 해주기, 이전 원소와 연결, tail 조정
void push(Queue*que, int num) {
	//buf[++que->cnt].num = num;
	//buf[que->cnt].next = &buf[que->cnt + 1];
	//buf[que->cnt - 1].next = &buf[que->cnt];
	//que->tail = &buf[que->cnt];

	bcnt++;
	buf[bcnt].num = num;
	buf[bcnt].next = nullptr;
	que->tail->next = &buf[bcnt];
	que->tail = &buf[bcnt];
	que->cnt++;
	
}

//head->next 가 가리키는 애 pop, head 조정
void pop(Queue*que) {
	//원소 없다면
	if (empty(que)) {
		return;
	}
	else {
		que->head = (que->head)->next;
		que->cnt--;
	}
}


