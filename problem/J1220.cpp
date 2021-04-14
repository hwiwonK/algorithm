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

	int len1, len2, result;
	char code1[N_MAX + 1] = { 0, };
	char code2[N_MAX + 1] = { 0, };

	cin >> code1;
	cin >> code2;

	len1 = strLen(code1);
	len2 = strLen(code2);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (code1[i - 1] == code2[j - 1]) match[i][j] = match[i - 1][j - 1] + 1;
			else {
				match[i][j] = match[i - 1][j] > match[i][j - 1] ? match[i - 1][j] : match[i][j - 1];
			}

		}
	}

	result = match[len1][len2];
	cout << result << endl;


	return 0;

}
