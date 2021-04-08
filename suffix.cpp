#include <iostream>
using namespace std;

const int MAX_STR = 401; //마지막 $ 포함
int suffixArr[MAX_STR] = { 0, };
char str[MAX_STR] = { 0, };

int getLen(char * str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

int compareStr(char *str, int a, int b, int len) { //suffixArr 값
	//a가 크면 1, 같으면 0, 작으면 -1
	while ((str[a] != '\0') && (str[b] != '\0')) {
		if (str[a] > str[b]) return 1;
		else if (str[a] < str[b]) return -1;
		a++;
		b++;
	}
	if (a == b) return 0;
	else {
		if (a == len) return -1;
		if (b == len) return 1;
	}

}

void sortStr(char * str, int * suffixArr, int len) {
	int result = 0;
	int tmpIdx = 0;
	int tmp = 0;
	for (int i = 0; i <=len-2; i++) {
		tmpIdx = i;
		for (int j = i+1; j <= len-1; j++) {
			result = compareStr(str, suffixArr[tmpIdx], suffixArr[j], len);
			if (result > 0) tmpIdx = j;
		}
		tmp = suffixArr[i];
		suffixArr[i] = suffixArr[tmpIdx];
		suffixArr[tmpIdx] = tmp;
	}
}


int main() {

	int tc;
	int T;

	freopen("input.txt", "r", stdin);

	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		int K;
		cin >> K;
		cin >> str;
		int len = getLen(str);
		//str[len] = '$';

		if (K > len) {
			cout << "none" << endl;
			continue;
		}

		//cout << str << " : " << len;
		for (int i = 0; i < len; i++) {
			suffixArr[i] = i;
		}

		sortStr(str, suffixArr, len);

		int startIdx = suffixArr[K-1];

		cout << "#" << tc << " ";
		for (int i = startIdx; i < len; i++) {
			cout << str[i];
		}
		cout << endl;

		//초기화

	}

	

	return 0;
}
