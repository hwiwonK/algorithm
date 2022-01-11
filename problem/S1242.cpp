// 비트 패턴보다 비율을 활용해서 하는게 훨씬 빠르다 -> 나중에 최대공약수 이용해서 두께 1 짜리 데이터로 만들기

#include <iostream>

using namespace std;

const int ROW_MAX = 2000;
const int COL_MAX = 500;

char input[ROW_MAX + 1][COL_MAX + 1] = { 0, };
int password[8][8][8][8] = { 0, };

//col�� �ִ� 16������ 2������ ��ȯ�Ͽ�, �迭�� idx ���� ����
void hexaToBinary(int * binaryArr, int idx, int row, int col) {
	int num;
	if (input[row][col] - 65 < 0) {
		num = input[row][col] - 48;
	}
	else {
		num = input[row][col] - 65 + 10;
	}

	for (int i = idx; i < idx + 4; i++) {
		binaryArr[i] = num % 2;
		num /= 2;
	}
}

bool getCode(int * binaryArr, int thick) {
	int code[9] = { 0, }; //8�ڸ� �ڵ�

	int tmp[5] = { 0, };
	//int codeLen = thick * 8;
	//int codeIdx = 1;

	for (int codeIdx = 1; codeIdx <= 8; codeIdx++) {
		
		int idx = (codeIdx - 1) * thick;
		int limit = idx + thick;
		//1����
		while (binaryArr[idx] == 1 && idx < limit) {
			tmp[1]++;
			idx++;
		}

		//0����
		while (binaryArr[idx] == 0 && idx < limit) {
			tmp[2]++;
			idx++;
		}

		//1����
		while (binaryArr[idx] == 1 && idx < limit) {
			tmp[3]++;
			idx++;
		}

		//0����
		while (binaryArr[idx] == 0 && idx < limit) {
			tmp[4]++;
			idx++;
		}

		//if (idx != i + thick) return false; //���� ����� �Ұ�

		//���� ����� �����ϴٸ� ���� ã��
		int num = password[tmp[4]][tmp[3]][tmp[2]][tmp[1]];
		if (num != 0) {
			code[codeIdx] = num;
			if (num == -1) code[codeIdx] = 0;
			codeIdx++;
		}
		else {
			return false;
		}

	}

	//�ڵ� �� �����ߴٸ� �����ϱ�
	int check = (code[1] + code[3] + code[5] + code[7]) * 3 + code[2] + code[4] + code[6] + code[8];
	if (check % 10 == 0) {
		int sumCode = code[1] + code[3] + code[5] + code[7] + code[2] + code[4] + code[6] + code[8];
		printf("%d", sumCode);
	}

	//�迭 �ʱ�ȭ

	return true;

}

void getCode(int row, int col) {
	int binaryArr[(COL_MAX + 1) << 2 + 1] = { 0, }; //2���� ���� : x4 ��ŭ ũ�� �÷����
	int idx = 1;
	int curCol = col;
	//16���� -> 2����
	while (curCol != 0) {
		hexaToBinary(binaryArr, idx, row, curCol);
		idx += 4;
		curCol--;
	}

	//�ڵ� Ȯ���ϱ�

	//������ ã�� : ������ 1�� ����
	int start = 1;
	while (true) {
		if (binaryArr[start] == 1) break;
	}

	//���� ���� (7, 14, 21 ... �÷����鼭)

	//�ִ� ���� = (col - 0) / 8
	int maxThick = (col - 0) / 8;

	for (int thick = 7; thick <= maxThick; thick++) {
		getCode(binaryArr, thick);

	}

}

int main() {

	freopen("input.txt", "r", stdin);

	//��ȣ ���� ����
	//���� �κ��� -1��

	password[3][2][1][1] = -1; //���� ���� �κа� �����ϱ� ����
	password[2][2][2][1] = 1;
	password[2][1][2][2] = 2;
	password[1][4][1][1] = 3;
	password[1][1][3][2] = 4;
	password[1][2][3][1] = 5;
	password[1][1][1][4] = 6;
	password[1][3][1][2] = 7;
	password[1][2][1][3] = 8;
	password[3][1][1][2] = 9;

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int R, C;

		scanf("%d %d", &R, &C);

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf("%c", &input[i][j]);
			}
		}


		for (int i = 1; i <= R; i++) {
			for (int j = C; j >= 1; j--) {
				if (input[i][j] != '0') {
					getCode(i, j);

				}

			}
		}


	}
	




	return 0;
}