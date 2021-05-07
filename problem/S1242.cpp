
#include <iostream>

using namespace std;

const int ROW_MAX = 2000;
const int COL_MAX = 500;

char input[ROW_MAX + 1][COL_MAX + 1] = { 0, };
int password[8][8][8][8] = { 0, };

//col에 있는 16진수를 2진수로 변환하여, 배열의 idx 부터 저장
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
	int code[9] = { 0, }; //8자리 코드

	int tmp[5] = { 0, };
	//int codeLen = thick * 8;
	//int codeIdx = 1;

	for (int codeIdx = 1; codeIdx <= 8; codeIdx++) {
		
		int idx = (codeIdx - 1) * thick;
		int limit = idx + thick;
		//1세기
		while (binaryArr[idx] == 1 && idx < limit) {
			tmp[1]++;
			idx++;
		}

		//0세기
		while (binaryArr[idx] == 0 && idx < limit) {
			tmp[2]++;
			idx++;
		}

		//1세기
		while (binaryArr[idx] == 1 && idx < limit) {
			tmp[3]++;
			idx++;
		}

		//0세기
		while (binaryArr[idx] == 0 && idx < limit) {
			tmp[4]++;
			idx++;
		}

		//if (idx != i + thick) return false; //숫자 만들기 불가

		//숫자 만들기 가능하다면 숫자 찾기
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

	//코드 다 추출했다면 검증하기
	int check = (code[1] + code[3] + code[5] + code[7]) * 3 + code[2] + code[4] + code[6] + code[8];
	if (check % 10 == 0) {
		int sumCode = code[1] + code[3] + code[5] + code[7] + code[2] + code[4] + code[6] + code[8];
		printf("%d", sumCode);
	}

	//배열 초기화

	return true;

}

void getCode(int row, int col) {
	int binaryArr[(COL_MAX + 1) << 2 + 1] = { 0, }; //2진수 저장 : x4 만큼 크기 늘려줘야
	int idx = 1;
	int curCol = col;
	//16진수 -> 2진수
	while (curCol != 0) {
		hexaToBinary(binaryArr, idx, row, curCol);
		idx += 4;
		curCol--;
	}

	//코드 확인하기

	//시작점 찾기 : 무조건 1로 시작
	int start = 1;
	while (true) {
		if (binaryArr[start] == 1) break;
	}

	//선의 굵기 (7, 14, 21 ... 늘려가면서)

	//최대 굵기 = (col - 0) / 8
	int maxThick = (col - 0) / 8;

	for (int thick = 7; thick <= maxThick; thick++) {
		getCode(binaryArr, thick);

	}

}

int main() {

	freopen("input.txt", "r", stdin);

	//암호 숫자 세팅
	//없는 부분은 -1로

	password[3][2][1][1] = -1; //숫자 없는 부분과 구분하기 위해
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