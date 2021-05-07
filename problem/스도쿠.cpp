#include <iostream>
using namespace std;

const int SUDOKU_MAX = 10;
int sudoku[SUDOKU_MAX][SUDOKU_MAX] = { 0, };
int blank[SUDOKU_MAX*SUDOKU_MAX][2] = { 0, };


int getCandi(int sudoku[][SUDOKU_MAX], int row, int col, int candi[]) {
	int idx = 1;
	int candiN = 0;
	bool check[10] = { false, };

	//������ üũ
	for (int j = 1; j <= 9; j++) {
		check[sudoku[row][j]] = true;
	}
	//������ üũ
	for (int i = 1; i <= 9; i++) {
		check[sudoku[i][col]] = true;
	}

	int rowMod = row % 3;
	int colMod = col % 3;
	if (rowMod == 0) rowMod = 3;
	if (colMod == 0) colMod = 3;
		
	int rowBox = row - rowMod + 1;
	int colBox = col - colMod + 1;

	//�ڽ� üũ
	for (int i = rowBox; i <= rowBox+2; i++) {
		for (int j = colBox; j <= colBox + 2; j++)
			check[sudoku[i][j]] = true;
	}

	//�ĺ� �迭 ���ϱ�
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

	cnt++; //���� blank��
	int row = blank[cnt][0];
	int col = blank[cnt][1];
	int result = 0;

	int candiN = getCandi(sudoku, row, col, candi);

	for (int i = 1; i <= candiN; i++) { //��� �ؿ� ���� ��� ȣ�� (���߿� �����ϱ�)
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

	//�Է¹ޱ�
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> sudoku[i][j];
		}
	}

	int blankN = 0;
	//����� ã��- Ȯ�οϷ�
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