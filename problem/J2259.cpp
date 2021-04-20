#include <iostream>

using namespace std;


int main() {

	freopen("input.txt", "r", stdin);

	int box[5][2] = { 0, };
	int pattern[6] = { 0, };
	int patternLen[6] = { 0, };
	int tmp1, tmp2;

	int K, direct, len;

	cin >> K;

	for (int i = 0; i < 6; i++) {
		cin >> direct >> len;
		pattern[i] = direct;
		patternLen[i] = len;
		if (box[direct][0] == 0) {
			box[direct][0] = len;
		}
		else {
			box[direct][1] = len;
		}
	}


	//가로 세로 구하기
	int width, height, fullArea;

	width = box[1][0] + box[1][1];
	height = box[3][0] + box[3][1];

	fullArea = width * height;

	//오목 부분 구하기
	for (int i = 1; i <= 2; i++) {
		if (box[i][1] != 0) tmp1 = i;
		if (box[i+2][1] != 0) tmp2 = i+2;
	}

	//tmp1, tmp2 중 앞에 것 고르기
	int start = 0;
	for (int i = 0; i < 6; i++) {
		if (pattern[i] != tmp1 && pattern[i] != tmp2 && (pattern[(i+1)%6] == tmp1 || pattern[(i+1)%6] == tmp2)) {
			start = i;
		}
	}


	//if (start == 6) {
	//	start = 0;
	//}

	//int smallArea = box[smallA][1] * box[smallB][0];
	int smallArea = patternLen[(start + 2) % 6] * patternLen[(start + 3) % 6];

	int finalArea = fullArea - smallArea;

	cout << K * finalArea << endl;

	return 0;
}
