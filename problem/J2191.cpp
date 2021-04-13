#include <iostream>

using namespace std;

const int N_MAX = 1001;

int dist[N_MAX][N_MAX] = { 0, };

int main() {
	freopen("input2.txt", "r", stdin);

	char str1[N_MAX] = { 0, };
	char str2[N_MAX] = { 0, };
	int d[3][2] = { {-1, 0}, {-1, -1}, {0,-1} };
	int len1, len2;

	//입력받기
	cin >> len1 >> str1;
	cin >> len2 >> str2;

	//baseline
	for (int i = 1; i <= len1; i++) {
		dist[0][i] = i;
	}

	for (int j = 1; j <= len2; j++) {
		dist[j][0] = j;
	}

	//edit distance
	int minTmp, minIdx, maintain;
	for (int i = 1; i <= len2; i++) {
		for (int j = 1; j <= len1; j++) {
			minTmp = 9999;
			//위, 왼쪽 위, 왼쪽 중 최솟값
			if (str1[j-1] == str2[i-1]) dist[i][j] = dist[i - 1][j - 1];
			else {
				for (int k = 0; k <= 2; k++) {
					if (dist[i + d[k][0]][j + d[k][1]] < minTmp) {
						minTmp = dist[i + d[k][0]][j + d[k][1]];
					}
				}
				dist[i][j] = minTmp + 1;
			}
		}
	}

	cout << dist[len2][len1] << endl;


	return 0;
}
