// 새로운 minCorner 선언 안하고, 기존 input 배열 이용해도 됨


#include <iostream>
#include <math.h>

using namespace std;

const int N_MAX = 10000;
const int LEN_MAX = 20;

char hashTable[N_MAX][LEN_MAX+1] = { 0, };
int hashIdx[N_MAX] = { 0, }; //해쉬 테이블에 저장된 문자열의 인덱스 저장
char inputStr[N_MAX+1][LEN_MAX + 1] = { 0, };
int resultCnt[N_MAX+1][N_MAX+1] = { 0, }; //index 0에는 겹치는 문자열의 수 저장

int strLen(char *a) {
	int i = 0;
	while (a[i]) i++;

	return i;
}


int strCmp(char *a, char *b) { //b가 table에 있는 문자열
	int i = 0;
	int aLen = strLen(a);
	int bLen= strLen(b);
	
	if (aLen != bLen) return -1;

	for (i = 0; i < aLen; i++) {
		if (a[i] != b[i]) return -1;
	}

	return 0;
	
}

//word를 hashing해서 hashTable에 넣기
//hash(s) = (s[0] + s[1]* p + s[2] * p2+ … + s[n-1] * pn-1) mod m
int hashing(char *word, int tableSize) {
	int i = 0;
	int hashVal = 0;
	int p = 31;
	while (word[i] != 0) {
		hashVal += word[i] * pow(p, i);
		i++;
	}

	if (hashVal >= tableSize) {
		hashVal %= tableSize;
	}

	return hashVal;

}

void searching(int hashVal, int N, char *str, int i) {
	while (hashTable[hashVal][0] != 0) {
		if (strCmp(hashTable[hashVal], str) == 0) {//같다면
			int idx = hashIdx[hashVal];
			resultCnt[idx][resultCnt[idx][0] + 1] = i;
			resultCnt[idx][0] ++;
			return;
		}
		hashVal++;
		if (hashVal >= N) hashVal %= N;
	}

	for (int i = 0; i <= LEN_MAX; i++) {
		hashTable[hashVal][i] = str[i];
		hashIdx[hashVal] = i;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int N, hashVal;
	//char tmp[LEN_MAX + 1] = { 0, };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> inputStr[i];
	}

	for (int number = 1; number <= N; number++) {
		//for (int i=0; i<)
		char * tmp = inputStr[number];

		//char tmp[LEN_MAX + 1] = { 0, };

		for (int i = 0; i < strLen(inputStr[number]); i++) {
			tmp[i] = inputStr[number][i];
		}

		//해쉬값 찾기
		hashVal = hashing(tmp, N);

		//중복시 탐사
		if (hashTable[hashVal][0] != 0) {
			searching(hashVal, N, tmp, number); //성공 했으면 결과 저장, 실패시 빈 인덱스에 문자열 입력
		}
		else {
			//테이블에 문자열 넣기
			int lenTmp = strLen(tmp);
			for (int i = 0; i < lenTmp; i++) {
				hashTable[hashVal][i] = tmp[i];
			}
			hashIdx[hashVal] = number;
		}

	}

	//결과 출력

	for (int i = 1; i <= N; i++) {
		if (resultCnt[i][0] != 0) {
			cout << inputStr[i] << " " << i << " ";
			for (int j = 1; j <= resultCnt[i][0]; j++) {
				cout << resultCnt[i][j] << " ";
			}
			cout << endl;
		}
	}

	//delete resultCnt;
	//delete inputStr;
	//delete hashTable;
	//delete hashIdx;

	return 0;
}
