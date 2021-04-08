#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

const int WORD_MAX = 51;
const int SIZE = 100000;

char hashTable[SIZE][WORD_MAX] = { 0, };

bool getPrime(int a) {
	int last = a >> 1;
	if (a <= 1) return false;

	for (int i = 2; i <= last; i++) {
		if (a % i == 0) return false;
	}

	return true;
}

//선형 탐사
int probing(char hashTable[][WORD_MAX], int tableSize, int hashVal) {
	while (hashTable[hashVal] != 0) {
		hashVal++;
		/*if (hashVal >= tableSize) hashVal %= tableSize;*/
		hashVal %= tableSize;
	}

	return hashVal;
}

//word를 hashing해서 hashTable에 넣기
//hash(s) = (s[0] + s[1]* p + s[2] * p2+ … + s[n-1] * pn-1) mod m
int hashing(char hashTable[][WORD_MAX], char *word, int tableSize) {
	int i = 0;
	int hashVal = 0;
	int p = 31;
	while (word[i] != '\0') {
		hashVal += word[i] * pow(p, i);
		i++;
	}

	hashVal %= tableSize;

	return hashVal;

}

//찾으면 true 반환
bool search(char hashTable[][WORD_MAX], char *word, int hashVal, int tableSize) {
	int j = 0;
	while (hashTable[hashVal] != 0 && j < tableSize) {
		if (strcmp(hashTable[hashVal], word) == 0) return true;
		j++;
		hashVal = (hashVal + 1) % tableSize;
	}


	return false;
}

int main() {
	int T, tc, tableSize;
	bool prime;

	freopen("input.txt", "r", stdin);
	char tmp[WORD_MAX] = { 0, };
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		int N, M;

		cin >> N >> M;

		//prime = false;

		////N보다 큰 가장 작은 소수를 테이블 크기로 정하기
		//int a = N;
		//while (!prime) {
		//	prime = getPrime(a);
		//	a++;
		//}

		//tableSize = a - 1;

		//cout << tableSize;

		//char ** hashTable = new char*[tableSize];
		//for (int i = 0; i < tableSize; i++) {
		//	hashTable[i] = new char[WORD_MAX] {0, };
		//	//hashTable[i] = { 0, };
		//}


		tableSize = N;

		//입력 받으면서 hashing 하기
		int hashVal = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s", &tmp);
			//cin >> tmp;
			hashVal = hashing(hashTable, tmp, tableSize);
			if (hashTable[hashVal] != 0) {
				hashVal = probing(hashTable, tableSize, hashVal);
			}
			int j = 0;
			while (tmp[j] != 0) {
				hashTable[hashVal][j] = tmp[j];
				j++;
			}
			hashTable[hashVal][j] = '\0';
		}

		//for (int i = 0; i < N; i++) {
		//	cout << hashTable[i] << endl;
		//}

		//cout << endl << endl;

		//두번째 문자열 입력 받으면서 중복 체크하기
		int cnt = 0; //중복 단어 수
		for (int i = 0; i < M; i++) {
			scanf("%s", &tmp);
			//cin >> tmp;
			hashVal = hashing(hashTable, tmp, tableSize);
			if (search(hashTable, tmp, hashVal, tableSize)) cnt++;
		}

		//결과 출력 (cnt 출력)

		cout << "#" << tc << " " << cnt << endl;

		//메모리 해제
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < WORD_MAX; j++) {
				hashTable[i][j] = '\0';
				tmp[j] = '\0';
			}
		}
	}



	return 0;
}
