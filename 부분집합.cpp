//#include <iostream>
//
//using namespace std;
//
//const int N = 5;
//const int CANDIDATE = 2;
//
//int src[] = { 6,2,8,4,5,1 };
//
//
//
//int make_candidate(int a[], int k, int n, int c[]) {
//	c[0] = 1; //���ԵǴ� ���
//	c[1] = 0; //���Ե��� �ʴ� ���
//
//	return 2;
//}
//
//void process_solution(int a[], int k, int n) {
//	cout << " {";
//	for (int i = 1; i <= n; i++) {
//		if (a[i] == 1) {
//			//cout << i << " "; //���� �迭�� ���� �ε��� ���� �����ϰ� �ִ�
//			cout << src[i - 1] << " ";
//		}
//	}
//	cout << "} \n";
//}
//
//
////a�� ��������- ������� ���õ� �κ���
////k�� �������տ� ���Ե� ���� ��, backtrack�� ȣ��� ����
////n�� ��� ���� ��, �̾ƾ� �� ����
//void backtrack(int a[], int k, int n) {
//	int c[CANDIDATE] = { 0, }; // �ĺ��� ����
//	int nCands = 0; //�ĺ��� ���տ� ���Ե� ������ ��
//
//	if (k == n) {
//		process_solution(a, k, n);
//	}
//	else {
//		k++;
//
//		nCands = make_candidate(a, k, n, c); //�ĺ��� ����
//		for (int i = 0; i < nCands; i++) {
//			a[k] = c[i]; //�ĺ��� �߿� �ϳ��� �������տ� �߰�
//			backtrack(a, k, n);
//		}
//	}
//
//}
//
//int main() {
//
//	int a[N + 1] = { 0, };
//	backtrack(a, 0, 3);
//
//	return 0;
//}