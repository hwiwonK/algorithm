#include <iostream>
#include <math.h>
#include <cmath>

#define PI 3.141592
#define DEGREE (180.0 / PI)

using namespace std;

const int N_MAX = 100;

int stack[N_MAX + 5] = { 0, };
int cnt = 0; //stack원소 수

double getAngle(int x1, int y1, int x2, int y2) {
	double xdf = x2 - x1;
	double ydf = y2 - y1;

	double radian = atan2(ydf, xdf);
	double degree = radian * DEGREE;

	return degree;
}


double getAngle2(int startX, int startY, int endX, int endY) {
	double dy = endY - startY;
	double dx = endX - endX;
	double angle = atan(dy / dx) * (180.0 / PI);

	return angle;
}

void sort(int loc[][2], int sortLoc[], int N) {
	//시작점 찾기 (y -> x 순으로 제일 작은것)
	int minVal = loc[1][1];
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		if (loc[i][1] <= minVal) {
			if (loc[i][1] == minVal && loc[i][0] < loc[idx][0]) idx = i;
			else {
				minVal = loc[i][1];
				idx = i;
			}
		}
	}

	//sortLoc[1] = idx;
	int startX = loc[idx][0];
	int startY = loc[idx][1];

	//x축 기준 각도 저장하기
	double angle[N_MAX + 1] = { 0, };
	double result;

	for (int i = 1; i <= N; i++) {
		//if (i == idx) continue;

		result = getAngle(startX, startY, loc[i][0], loc[i][1]);
		angle[i] = result;
	}

	//테스트
	//for (int i = 1; i <= N; i++) {
	//	cout << angle[i] << " ";
	//}
	//cout << endl;


	int tmp;
	//시작점에서 x축 기준 각도 가까운 순으로 정렬하기
	for (int i = 1; i <= N; i++) {
		sortLoc[i] = i;
	}

	//시작점 처리
	tmp = sortLoc[idx];
	sortLoc[idx] = 1;
	sortLoc[1] = tmp;

	minVal = 99999;
	int minIdx = -1;

	for (int i = 2; i <= N - 1; i++) {
		minIdx = i;
		minVal = angle[sortLoc[minIdx]];
		for (int j = i + 1; j <= N; j++) {
			if (angle[sortLoc[j]] < minVal) {
				minIdx = j;
				minVal = angle[sortLoc[j]];
			}
		}

		//swap하기
		tmp = sortLoc[minIdx];
		sortLoc[minIdx] = sortLoc[i];
		sortLoc[i] = tmp;
	}

}

void push(int a) {
	cnt++;
	stack[cnt] = a;
}

void pop() {
	stack[cnt] = 0;
	cnt--;
}

bool ccw(int loc[][2], int dotA, int dotB, int dotCurrent) {
	long long x1 = loc[dotA][0];
	long long y1 = loc[dotA][1];
	long long x2 = loc[dotB][0];
	long long y2 = loc[dotB][1];
	long long x3 = loc[dotCurrent][0];
	long long y3 = loc[dotCurrent][1];

	/*long long tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	long long tmp2 = y1 * x2 + y2 * x3 + y3 * x1;*/

	if ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) > 0) return true;
	return false;

	//return tmp1 - tmp2;
}

int polygon(int loc[][2], int sortLoc[], int N) {
	int currentX, currentY;
	int ccwVal;
	//첫번째, 두번째 점 push
	push(sortLoc[1]);
	push(sortLoc[2]);

	//3 ~ N번째 점 모두 고려하기
	for (int i = 3; i <= N; i++) {
		while (!ccw(loc, stack[cnt - 1], stack[cnt], sortLoc[i]) &&  cnt >= 2) { //0보다 작으면 오목함
			//if (cnt == 1) break;
			pop();
		}

		//i번째 점을 넣는다
		push(sortLoc[i]);

		/*while (cnt < 2) {
			push(sortLoc[++i]);
		}*/
	}

	//마지막 점 체크
	/*while (ccw(loc, stack[cnt - 1], stack[cnt], sortLoc[1]) <= 0) {
		pop();
	}*/

	return cnt;
}

int main() {

	freopen("input.txt", "r", stdin);

	int loc[N_MAX + 1][2] = { 0, };
	int sortLoc[N_MAX + 1] = { 0, };

	int N;

	cin >> N;

	//0에 x좌표, 1에 y좌표
	for (int i = 1; i <= N; i++) {
		cin >> loc[i][0] >> loc[i][1];
	}


	//좌표 정렬하기
	sort(loc, sortLoc, N);


	/*for (int i = 1; i <= N; i++) {
		printf("%d : %d %d\n", sortLoc[i], loc[sortLoc[i]][0], loc[sortLoc[i]][1]);
	}*/

	//다각형 만들기(stack에 있는 점들이 다각형 점)
	int lineCnt = polygon(loc, sortLoc, N);

	//정점 수 출력
	printf("%d\n", lineCnt);

	//stack에 남은 것들 출력하기
	for (int i = 1; i <= lineCnt; i++) {
		printf("%d %d\n", loc[stack[i]][0], loc[stack[i]][1]);
	}


	return 0;
}
