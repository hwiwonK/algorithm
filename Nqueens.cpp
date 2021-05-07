//#include <iostream>
////#include <cmath>
//using namespace std;
//
//const int QUEEN_MAX = 14;
//int queen[QUEEN_MAX] = { 0, };
//bool cols[QUEEN_MAX] = { false, }; //���ݱ��� ���õ� �� ǥ��, �ε����� COLS
//int ways = 0;
////�ε����� row ��
//
//int Promising(int queen[], int cnt) {
//	for (int i = 1; i < cnt; i++) {
//		if ((queen[i] - queen[cnt]) == (i - cnt)) return 0;
//		if ((queen[i] - queen[cnt]) == (-1* (i - cnt))) return 0;
//	}
//
//	return 1;
//}
//
//int getCandi(bool cols[], int N, int candi[]) {
//	int idx = 1;
//	int candiN = 0;
//	for (int i = 1; i <= N; i++) {
//		if (cols[i] == false) {
//			candi[idx++] = i;
//			candiN++;
//		}
//	}
//	return candiN;
//}
//
//void NQueen(int queen[], int cnt, int N) {
//
//	int candidates[QUEEN_MAX] = { 0, };
//
//	if (Promising(queen, cnt) == 0) return;
//	if (cnt == N) {
//		ways += 1;
//		return;
//	}
//
//	cnt++; //�� 1 �߰�
//
//	int candiN = getCandi(cols, N, candidates);
//
//	for (int i = 1; i <= candiN; i++) { //��� �ؿ� ���� ��� ȣ�� (���߿� �����ϱ�)
//		queen[cnt] = candidates[i];
//		cols[candidates[i]] = true;
//		NQueen(queen, cnt, N);
//		cols[candidates[i]] = false;
//	}
//
//}
//
//
//int main() {
//	int N;
//	cin >> N;
//
//	NQueen(queen, 0, N);
//
//	cout << ways << endl;
//
//	return 0;
//}