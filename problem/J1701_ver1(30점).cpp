//좀 더 간단하게 생각하기!, 왜 이 방법은 안될까, 놓친부분 찾아보기
//tcgatagggatttctccgcacagtag 여기서 놓친 부분 찾아보기 (답은 16, 출력은 14)

#include <iostream>

using namespace std;

const int N_MAX = 500;

char DNA[N_MAX + 2] = { 0, };
//int KOI[N_MAX + 2] = { 0, };
int KOI_A[N_MAX + 2] = { 0, };
int KOI_B[N_MAX + 2] = { 0, };

int dpArr[N_MAX + 2][N_MAX + 2] = { 0, }; //경계선부분 0으로

int strLen(char * str) {
	int len = 0;
	
	while (str[len]) {
		len++;
	}

	return len;
}

//bool KOI(int i, int j) {
//	if ((DNA[i] == 'a' && DNA[j] == 't') || (DNA[i] == 'g' && DNA[j] == 'c'))
//
//
//}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%s", &DNA);

	int N = strLen(DNA);


	//가장 가까운 a와 b의 위치 마킹하기
	//int aLoc = 1, bLoc = 1;
	//for (int i = 0; i < N; i++) {
	//	if (DNA[i] == 'a') aLoc = i;

	//	else if (DNA[i] == 'g') bLoc = i;
	//	
	//	else if (DNA[i] == 't') KOI[i] = aLoc;

	//	else KOI[i] = bLoc;
	//}

	int aCnt = 0, gCnt = 0;

	for (int i = 0; i < N; i++) {
		if (DNA[i] == 'a') KOI_A[aCnt++] = i;

		else if (DNA[i] == 'g') KOI_B[gCnt++] = i;

	}


	/*for (int i = 0; i < aCnt; i++) {
		printf("%d ", KOI_A[i]);
	}

	cout << endl;

	for (int i = 0; i < gCnt; i++) {
		printf("%d ", KOI_B[i]);
	}

	cout << endl;*/

	for (int i = N - 1; i >= 0; i--) {
		if (DNA[i] == 'c' || DNA[i] == 't') {
			for (int j = i; j < N; j++) {
				dpArr[i][j] = dpArr[i + 1][j];
			}
		}
		else {
			for (int j = i + 1; j < N; j++) {
				//dpArr[i][j]채우기
				if (DNA[j] == 'a' || DNA[j] == 'g') dpArr[i][j] = dpArr[i][j - 1];
				else {
					int maxLen = dpArr[i + 1][j] > dpArr[i][j-1] ? dpArr[i + 1][j] : dpArr[i][j - 1];

					//i와 j가 짝이 맞을 때(aXb)
					if ((DNA[i] == 'a' && DNA[j] == 't') || (DNA[i] == 'g' && DNA[j] == 'c')) {
						int tmp = dpArr[i + 1][j - 1] + 2;
						//maxLen 갱신하기
						maxLen = maxLen > tmp ? maxLen : tmp;
					}

					//뒤에 붙는 경우(ab)
					if (DNA[i] == 't') {
						for (int k = 0; k < aCnt; k++) {
							int tmp = dpArr[i][KOI_A[k] - 1] + dpArr[KOI_A[k]][j];
							maxLen = maxLen > tmp ? maxLen : tmp;
						}

					}
					else {
						for (int k = 0; k < gCnt; k++) {
							int tmp = dpArr[i][KOI_B[k] - 1] + dpArr[KOI_B[k]][j];
							maxLen = maxLen > tmp ? maxLen : tmp;
						}

					}

					//셋 중 제일 긴 값 붙이기
					dpArr[i][j] = maxLen;

				}

			}

		}
	}
	//printf("%d\n", dpArr[6][9]);
	printf("%d\n", dpArr[0][N-1]);

	//printf("   ");
	//for (int i = 0; i < N; i++) { printf("%d ", i); };
	//printf("\n");
	//printf("==============================\n");

	//for (int i = 0; i < N; i++) {
	//	printf("%d||", i);
	//	for (int j = 0; j < N; j++) {
	//		printf("%d ", dpArr[i][j]);
	//	}
	//	printf("\n");
	//}

	return 0;
}
