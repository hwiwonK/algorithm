//완전탐색 해도 시간초과 안걸림

#include <iostream>

using namespace std;

const int N_MAX = 100;

char num[N_MAX + 1][3] = { 0, }; //숫자 - strike - 볼
int strike[N_MAX + 1] = { 0, };
int ball[N_MAX + 1] = { 0, };
int sortIdx[N_MAX + 1] = { 0, };

//sort
void sort(int N) {
	int maxIdx = -1;
	int maxVal = -1;
	int tmp = -1;

	for (int i = 1; i <= N; i++) {
		sortIdx[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		maxIdx = i;
		maxVal = strike[sortIdx[maxIdx]];

		for (int j = i + 1; j <= N; j++) {
			if (strike[sortIdx[j]] >= maxVal) {
				if (strike[sortIdx[j]] == maxVal) {
					if (ball[sortIdx[maxIdx]] < ball[sortIdx[j]]) {
						maxIdx = j;
						maxVal = strike[sortIdx[maxIdx]];
					}

				}
				else {
					maxIdx = j;
					maxVal = strike[sortIdx[maxIdx]];
				}
			}
		}

		//idx swap하기
		tmp = sortIdx[i];
		sortIdx[i] = sortIdx[maxIdx];
		sortIdx[maxIdx] = tmp;
	}

}


int check(int first, int second, int third, int N) {

	int strikeT = 0;
	int ballT = 0;
	int q;

	for (int i = 1; i <= N; i++) {

		q = sortIdx[i];
		strikeT = 0;
		ballT = 0;

		//strike 체크하기
		if (num[q][0] - '0' == first) strikeT++;
		if (num[q][1] - '0' == second) strikeT++;
		if (num[q][2] - '0' == third) strikeT++;

		if (strikeT != strike[q]) return -1;

		//ball 체크하기
		if (num[q][0] - '0' == second || num[q][0] - '0' == third) ballT++;
		if (num[q][1] - '0' == first || num[q][1] - '0' == third) ballT++;
		if (num[q][2] - '0' == first || num[q][2] - '0' == second) ballT++;

		if (ballT != ball[q]) return -1;

	}

	return 1;
}

int main() {

	freopen("input.txt", "r", stdin);

	int N;

	//int first = 99, second = 99, third = 99; //아직 안 정해졌으면 99
	//int temp[3] = { 0, };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i] >> strike[i] >> ball[i];
	}

	//strike - ball 기준 내림차순 정렬
	sort(N);

	/*for (int i = 1; i <= N; i++) {
		cout << sortIdx[i] << " ";
	}*/

	//strike 3 있을 경우 바로 종료
	if (strike[sortIdx[1]] == 3) {
		cout << 1 << endl;
		return 0;
	}

	//for (int i = 1; i <= N; i++) {
	//	first[i] = second[i] = third[i] = true;
	//}

	int tmp, result, candiCnt = 0;
	int first, second, third;

	for (int candi = 123; candi <= 987; candi++) {
		tmp = candi;
		third = (tmp % 10);
		tmp /= 10;
		second = (tmp % 10);
		tmp /= 10;
		first = (tmp % 10);

		if (first == second || first == third || second == third) continue;
		if (first == 0 || second == 0 || third == 0) continue;

		result = check(first, second, third, N);
		if (result == 1) {
			candiCnt++;
			//cout << candi << endl;
		}
	}

	cout << candiCnt << endl;

	return 0;
}
