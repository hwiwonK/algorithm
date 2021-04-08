#include <iostream>


using namespace std;

const int STACK_SIZE = 10;
const int QUEUE_SIZE = 10;

int q[QUEUE_SIZE] = { 0, };
int stack[STACK_SIZE] = { 0, };
int top = -1;

int front = -1;
int rear = -1;

bool isQFull() {
	if (rear + 1 >= QUEUE_SIZE)
		return true;
	else
		return false;
}

bool isQEmpty() {
	if (front = rear)
		return true;
	else
		return false;
}

void enQueue(int val) {
	if (isQFull())
		cout << "QUEUE Overflow" << endl;
	else
		q[++rear] = val;
}

int deQueue() {
	if (isQEmpty())
		cout << "QUEUE Underflow !! " << endl;
	else {
		int ret = q[++front];
		q[front] = 0;
		return ret;
	}
}

int QPeeek() {
	if (isQEmpty())
		cout << "QUEUE Underflow !! " << endl;
	else {
		int ret = q[front];
		return ret;
	}
}

bool isFull() {
	if (top >= STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool isEmpty() {
	//if (top < 0)
	//	return true;
	//else
	//	return false;
	return (top < 0);
}

void push(int val) {
	if (isFull())
		cout << "Stack Overflow!!\n" << endl;
	else
		stack[++top] = val;
}


int pop() {
	if (isEmpty())
		cout << "Stack Underflow!!\n" << endl;
	else {
		//디버깅을 편하게 하기 위해서
		int ret = stack[top];
		stack[top--] = 0;
		return ret;
	}
}


int peek() {
	if (isEmpty())
		cout << "Stack Underflow!!\n" << endl;
	else {
		return stack[top--];
	}
}

int main() {

	for (int i = 1; i < 13; i++) {
		push(i);
	}

	while (!isEmpty()) {
		cout << pop() << " ";
	}

	cout << endl;

	return 0;
}
