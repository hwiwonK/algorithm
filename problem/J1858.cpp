//1. 같은 위치에 공백이 아닌 같은 문자가 있으면 3을 더한다.
//
//2. 같은 위치에 서로 다른 문자가 있거나 둘 중 하나의 위치에 공백이 있으면 2를 뺀다.
//LCS 구하기 lcs값 * 3 - 2*(큰 길이 - lcs값)

#include <iostream>

using namespace std;

const int N_MAX = 1000;
int match[N_MAX + 1][N_MAX + 1] = { 0, };

int strLen(char *str) {
	char * tmp = str;
	int cnt = 0;
	while (*tmp) {
		cnt++;
		tmp++;
	}
	return cnt;
}

int main() {

	freopen("input2.txt", "r", stdin);

	int len1, len2, lcsVal, biggerLen, smallerLen, result;
	char code1[N_MAX + 1] = { 0, };
	char code2[N_MAX + 1] = { 0, };
	char * bigger;
	char * smaller;

	cin >> len1;
	cin >> code1;
	cin >> len2;
	cin >> code2;

	//len1 = strLen(code1);
	//len2 = strLen(code2);

	biggerLen = len1 > len2 ? len1 : len2;
	if (len1 < len2) {
		biggerLen = len2;
		smallerLen = len1;
		bigger = code2;
		smaller = code1;

	}
	else {
		biggerLen = len1;
		smallerLen = len2;
		bigger = code1;
		smaller = code2;
	}

	cout << bigger << endl;
	cout << smaller << endl;

	for (int i = 1; i <= biggerLen; i++) {
		for (int j = 1; j <= smallerLen; j++) {
			if (bigger[i - 1] == smaller[j - 1]) match[i][j] = match[i - 1][j - 1] + 1;
			else {
				match[i][j] = match[i - 1][j] > match[i][j - 1] ? match[i - 1][j] : match[i][j - 1];
			}

		}
	}

	for (int i = 1; i <= biggerLen-1; i++) {
		if (match[smallerLen][i] != match[smallerLen][i + 1]) {

		}
	}

	lcsVal = match[biggerLen][smallerLen];
	
	result = lcsVal * 3 - (biggerLen - lcsVal) * 2;

	cout << result << endl;

	return 0;

}
