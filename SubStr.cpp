#include <iostream>
using namespace std;

const int MAX_STR = 401; //마지막 \0 포함
int suffixArr[MAX_STR] = { 0, };
char str[MAX_STR] = { 0, };
int LCP[MAX_STR] = { 0, };

int getLen(char * str) {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

//문자열 비교하기
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

//공통된 부분 구하기
int commonStr(char *str, int a, int b, int len) {
	int cnt = 0;
	while (str[a] == str[b]) { //문자 같다면
		cnt++;
		a++;
		b++;
		if ((str[a] == '\0') || (str[b] == '\0')) break; //하나라도 범위 벗어나면 break
	}

	return cnt;
}

//suffixArr 만들기
void sortStr(char * str, int * suffixArr, int len) {
	int result = 0;
	int tmpIdx = 0;
	int tmp = 0;
	for (int i = 0; i <= len - 2; i++) {
		tmpIdx = i;
		for (int j = i + 1; j <= len - 1; j++) {
			result = compareStr(str, suffixArr[tmpIdx], suffixArr[j], len);
			if (result > 0) tmpIdx = j;
		}
		tmp = suffixArr[i];
		suffixArr[i] = suffixArr[tmpIdx];
		suffixArr[tmpIdx] = tmp;
	}
}

//LCP 만들기
void getLCP(char * str, int * suffixArr, int len) {
	int LCPval = 0;
	LCP[0] = 0;
	for (int i = 1; i <= len - 1; i++) {
		LCPval = commonStr(str, suffixArr[i - 1], suffixArr[i], len);
		LCP[i] = LCPval;
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


		//cout << str << " : " << len;
		for (int i = 0; i < len; i++) {
			suffixArr[i] = i;
		}

		//suffixArr 만들기
		sortStr(str, suffixArr, len);

		//LCP 만들기 - 확인함
		getLCP(str, suffixArr, len);
		
		//K번째 부분 문자열 구하기
		int substrN = 0;
		int i = 0;

		while (substrN < K && i <= len) {
			substrN += (len - suffixArr[i]) - LCP[i];
			i++;
		}

		if (i > len) {
			cout << "none" << endl;
			continue;
		}

		i = i - 1;
		//suffixArr[i]에 정답 있음
		int startIdx = suffixArr[i];
		int finalIdx = startIdx + len - suffixArr[i] - (substrN - K) - 1;

		cout << "#" << tc << " ";
		for (int j = startIdx; j <= finalIdx; j++) {
			cout << str[j];
		}

		cout << endl;



		//초기화

	}



	return 0;
}
