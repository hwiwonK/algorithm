#include <iostream>
using namespace std;

const int SUDOKU_MAX = 10;
int sudoku[SUDOKU_MAX][SUDOKU_MAX] = { 0, };
int blank[SUDOKU_MAX*SUDOKU_MAX][2] = { 0, };


int getCandi(int sudoku[][SUDOKU_MAX], int row, int col, int candi[]) {
	int idx = 1;
	int candiN = 0;
	bool check[10] = { false, };

	//가로줄 체크
	for (int j = 1; j <= 9; j++) {
		check[sudoku[row][j]] = true;
	}
	//세로줄 체크
	for (int i = 1; i <= 9; i++) {
		check[sudoku[i][col]] = true;
	}

	int rowMod = row % 3;
	int colMod = col % 3;
	if (rowMod == 0) rowMod = 3;
	if (colMod == 0) colMod = 3;
		
	int rowBox = row - rowMod + 1;
	int colBox = col - colMod + 1;

	//박스 체크
	for (int i = rowBox; i <= rowBox+2; i++) {
		for (int j = colBox; j <= colBox + 2; j++)
			check[sudoku[i][j]] = true;
	}

	//후보 배열 구하기
	for (int i = 1; i <= 9; i++) {
		if (check[i] == false) {
			candi[idx++] = i;
			candiN++;
		}
	}

	return candiN;
}

int sudokuPlay(int sudoku[][SUDOKU_MAX], int cnt, int blankN) {

	int candi[SUDOKU_MAX] = { 0, };

	if (cnt == blankN) return 1;

	cnt++; //다음 blank로
	int row = blank[cnt][0];
	int col = blank[cnt][1];
	int result = 0;

	int candiN = getCandi(sudoku, row, col, candi);

	for (int i = 1; i <= candiN; i++) { //모든 해에 대해 재귀 호출 (나중에 수정하기)
		sudoku[row][col] = candi[i];
		result = sudokuPlay(sudoku, cnt, blankN);
		if (result == 1) {
			return 1;
			//break;
		}
	}

	return 0;
}


int main() {

	freopen("input.txt", "r", stdin);

	//입력받기
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> sudoku[i][j];
		}
	}

	int blankN = 0;
	//빈공간 찾기- 확인완료
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (sudoku[i][j] == 0) {
				blank[++blankN][0] = i;
				blank[blankN][1] = j;
			}
		}
	}


	sudokuPlay(sudoku, 0, blankN);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}