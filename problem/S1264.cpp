#include <iostream>

using namespace std;

const int N_MAX = 500;
int match[N_MAX + 1][N_MAX + 1] = { 0, };

int main() {
	freopen("input2.txt", "r", stdin);
	int tc, T;
	cin >> T;

	for (tc = 1; tc <= T; tc++) {
		int N;
		char code1[N_MAX + 2] = { 0, };
		char code2[N_MAX + 2] = { 0, };

		cin >> N;
		cin >> code1;
		cin >> code2;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (code1[i - 1] == code2[j - 1]) match[i][j] = match[i - 1][j - 1] + 1;
				else {
					match[i][j] = match[i - 1][j] > match[i][j - 1] ? match[i - 1][j] : match[i][j - 1];
				}

			}
		}

		double result;
		result = ((double)match[N][N] / N)*100;
		cout << "#" << tc << " ";
		printf("%.2f\n", result);
		
		//초기화
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				match[i][j] = 0;
			}
		}

	}


	return 0;

}
