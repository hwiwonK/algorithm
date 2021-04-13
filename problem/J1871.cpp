#include <iostream>

using namespace std;

const int N_MAX = 201;

int getLIS(int child[], int N) {
	int LIS[N_MAX] = { 0, };
	int valLIS = 0;

	for (int i = 1; i <= N; i++) {
		int low = 1; 
		int high = valLIS;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (child[i] > LIS[mid]) low = mid + 1;
			else high = mid-1;
		}

		LIS[low] = child[i];
		valLIS = low > valLIS ? low : valLIS;
	}

	return valLIS;

}

int main() {
	freopen("input2.txt", "r", stdin);

	int child[N_MAX] = { 0, };
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> child[i];
	}

	cout << N - getLIS(child, N) << endl;

	return 0;
}
