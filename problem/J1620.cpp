#include <iostream>

using namespace std;

const int N_MAX = 101;
char phone[N_MAX] = { 0, };
char dummis[N_MAX][5] = { 0, };

int strLen(char * str) {
	char * tmp = str;
	int len = 0;

	while (*tmp) {
		len++;
		tmp++;
	}

	return len;
}

int getDummi(char *phone) {
	char * tmp = phone;
	int len = 0;
	int dummiN = 0;

	//각 dummi dummis에 저장
	while (*tmp) {
		dummiN++;
		while (tmp[len] != '-' && tmp[len] != '\0' && len <= 4) {
			dummis[dummiN][len] = tmp[len];
			len++;
		}

		if (len > 4) return -1; //input error

		tmp += len + 1;
		len = 0;
	}


	return dummiN;
}

int getPassword(int plus, int dummi) {
	char * tmp = dummis[dummi];
	int number = 0;
	int tmpNum = 0;
	int len = strLen(tmp);

	for (int i = 0; i < len; i++) {
		tmpNum = (dummis[dummi][i] - 48) + plus;
		if (tmpNum >= 10) tmpNum = tmpNum % 10;
		number = number * 10 + tmpNum;
	}

	//앞에 0 부분 채우기
	int limit = 4 - len;
	tmpNum = 0;
	for (int i = 0; i < limit; i++) {
		tmpNum = tmpNum * 10 + plus;
	}

	for (int i = 0; i < len; i++) {
		tmpNum *= 10;
	}

	return number + tmpNum;

}

int main() {
	freopen("input.txt", "r", stdin);

	int plus, dummi, dummiN, password = 0;
	cin >> phone >> plus >> dummi;

	//phone number '-' 기준으로 나누기
	dummiN = getDummi(phone);

	/*for (int i = 1; i <= 5; i++) {
		cout << dummis[i] << endl;
	}*/

	//처리 오류
	if (dummiN == -1) {
		cout << "INPUT ERROR!" << endl;
		return 0;
	}

	//dummi번째에 plus 더하기
	if (dummiN >= dummi) {
		password = getPassword(plus, dummi);
	}
	else {
		for (int i = 0; i < 4; i++) {
			password = password * 10 + plus;
		}
	}

	cout << password;

	return 0;
}
