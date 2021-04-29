#include <iostream>

using namespace std;

const int N_MAX = 500;

char DNA[N_MAX + 2] = { 0, };

int dpArr[N_MAX + 2][N_MAX + 2] = { 0, }; //경계선부분 0으로

int strLen(char * str) {
	int len = 0;

	while (str[len]) {
		len++;
	}

	return len;
}


int main() {

	freopen("input.txt", "r", stdin);

	scanf("%s", &DNA);

	int N = strLen(DNA);



	int aCnt = 0, gCnt = 0;




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
					int maxLen = dpArr[i + 1][j] > dpArr[i][j - 1] ? dpArr[i + 1][j] : dpArr[i][j - 1];

					//i와 j가 짝이 맞을 때(aXb)
					if ((DNA[i] == 'a' && DNA[j] == 't') || (DNA[i] == 'g' && DNA[j] == 'c')) {
						int tmp = dpArr[i + 1][j - 1] + 2;
						//maxLen 갱신하기
						maxLen = maxLen > tmp ? maxLen : tmp;
					}

					for (int k = 1; k < j - i -1; k++) {
						int tmp = dpArr[i][i+k] + dpArr[i+k+1][j];
						maxLen = maxLen > tmp ? maxLen : tmp;
					}



					//셋 중 제일 긴 값 붙이기
					dpArr[i][j] = maxLen;

				}

			}

		}
	}
	
	printf("%d\n", dpArr[0][N - 1]);



	return 0;
}
