//제출시 오류 해결================================================
//==========================================================


#include <iostream>

using namespace std;

const int N_MAX = 100; //배열 크기
const int MATRIX_MAX = 20; //행렬 최대 수
const long long INFINITI = 999999999999;
int input[N_MAX][N_MAX] = { 0, };
long long mcmMatrix[MATRIX_MAX + 1][MATRIX_MAX + 1] = { 0, }; //mcm수행시 사용
int getMatrix[MATRIX_MAX][2] = { 0, };
int d[MATRIX_MAX + 1] = { 0, };

int findMatrix(int getMatrix[][2], int N) {
	int idx = 0;
	int colCnt = 0;
	int rowCnt = 0;
	int iTmp = 0;
	int jTmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j+= colCnt) {
			if (input[i][j] != 0) { //input[iTmp][jTmp] 에서 숫자 찾음
				colCnt = 0;
				rowCnt = 0;

				iTmp = i;
				jTmp = j;
			
				//행 수, 열 수 구하기
				while (input[iTmp][jTmp] != 0) {
					colCnt++;
					jTmp++;
				}
				jTmp--;
				while (input[iTmp][jTmp] != 0) {
					rowCnt++;
					iTmp++;
				}

				//getMatrix에 저장하기
				getMatrix[idx][0] = rowCnt;
				getMatrix[idx][1] = colCnt;
				idx++;

				//찾은 행렬 0으로 바꾸기
				for (int k = i; k < i + rowCnt; k++) {
					for (int p = j; p < j + colCnt; p++) {
						input[k][p] = 0;
					}
				}

				//다음 인덱스 부터 다시 검사 시작
			}
			else {
				colCnt = 1;
			}
		}

	}

	//총 행렬의 갯수 return
	return idx;
}

void matrixSort(int getMatrix[][2], int d[], int matrixN) {
	int flag = 1;
	int startIdx = 0;

	//d배열 초기화
	for (int i = 0; i <= matrixN; i++) {
		d[i] = i;
	}

	//시작점 찾기
	for (int i = 0; i < matrixN && flag; i++) {
		flag = 0;
		for (int j = 0; j < matrixN; j++) {
			if (i != j) {
				if (getMatrix[i][0] == getMatrix[j][1]) flag = 1;
			}
		}

		if (flag == 0) {
			startIdx = i;
			break;
		}
	}

	//시작점 setting
	//i + 1 번째 행렬이 시작점이다
	d[0] = getMatrix[startIdx][0];
	d[1] = getMatrix[startIdx][1];
	if (startIdx!=0) d[startIdx+1] = 1; //인덱스 바꿔주기

	//나머지 행렬로 d 배열 만들기
	int toFind = 0;
	int tmp = 0;
	for (int i = 2; i <= matrixN-1; i++) { //i번째에 넣을 값 찾기
		toFind = d[i-1];
		for (int j = i; j <= matrixN; j++) {
			if (toFind == getMatrix[d[j]-1][0]) { //값 찾음
				tmp = getMatrix[d[j]-1][1]; //열의 값 넣기
//================================================오류=======================================================
//d[j] = i => 바꿔왔던 인덱스가 반영이 안됨
				d[j] = d[i];
				d[i] = tmp; //인덱스 바꿔주기
				break;
			}
		}
	}

	//마지막 값 setting
	d[matrixN] = getMatrix[d[matrixN]-1][1];

}

void mcm(int d[], int matrixN) {
	//mcmMatrix 사용하기
	long long tmp=0;
	for (int r= 1; r <= matrixN-1; r++) {
		for (int i = 1; i <= matrixN - r; i++) {
			int j = i + r;
			mcmMatrix[i][j] = INFINITI;
			for (int k = i; k <= j - 1; k++) {
				tmp = mcmMatrix[i][k] + mcmMatrix[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (tmp < mcmMatrix[i][j]) mcmMatrix[i][j] = tmp;
			}
		}
	}

}

int main() {
	freopen("input2.txt", "r", stdin);
	int tc = 0;
	int T = 0;
	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		int N = 0;
		int matrixN = 0;

		cin >> N;

		//입력 받기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
			}
		}

		matrixN = findMatrix(getMatrix, N); // input에서 행렬 찾기 - 확인 완료


		matrixSort(getMatrix, d, matrixN); //d 배열 만들기 - 확인 완료


		//MCM start
		mcm(d, matrixN);

		cout << "#" << tc << " " << mcmMatrix[1][matrixN] << endl;

		//초기화
		for (int i = 0; i < N_MAX; i++) {
			for (int j = 0; j < N_MAX; j++) {
				input[i][j] = 0;
			}
		}

		for (int i = 0; i <= MATRIX_MAX; i++) {
			d[i] = 0;
			for (int j = 0; j <= MATRIX_MAX; j++) {
				mcmMatrix[i][j] = 0;
			}
		}

		for (int i = 0; i < MATRIX_MAX; i++) {
			getMatrix[i][0] = 0;
			getMatrix[i][1] = 0;
		}


	}


	return 0;

}
