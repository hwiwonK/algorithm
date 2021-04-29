//좌표평면에 여러개의 점들이 주어져 있다.
//이 점들을 모두 포함하면서 넓이가 최소인 볼록다각형을 그리려고 할 때 볼록다각형의 넓이를 구하는 프로그램을 작성하시오.

//tmp = startX*startX + startY*startY + loc[i][0] * loc[i][0] + startY * loc[i][1];
		//tmp_b = sqrt(pow(loc[i][0] - startX, 2)) + sqrt(pow((loc[i][0] - startX), 2) + pow((loc[i][1] - startY), 2));
		//result = RAD2DEG(acos(tmp / tmp_b));
		////result = acos(tmp);
		//angle[i] = result;
//#define RAD2DEG(Rad) ( Rad * DEGREE )

#include <iostream>
#include <math.h>

#define PI 3.141592
#define DEGREE (180.0 / PI)

using namespace std;

const int N_MAX = 100;

int stack[N_MAX] = { 0, };
int cnt = 1; //stack원소 수
int head = 1; //스택 맨 앞 인덱스

double getAngleSort(int x1, int y1, int x2, int y2) {
	double xdf = x2 - x1;
	double ydf = y2 - y1;

	double radian = atan2(ydf, xdf);
	double degree = radian * DEGREE;

	return degree;
}

void sort(int loc[][2], int sortLoc[], int N) {
	//시작점 찾기
	int minVal = 99999;
	int idx = -1; //이렇게 하면 런타임에러 날 수도 있을듯
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
	double angle[N_MAX] = { 0, };
	double result;

	for (int i = 1; i <= N; i++) {
		//if (i == idx) continue;

		result = getAngleSort(startX, startY, loc[i][0], loc[i][1]);
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
	stack[cnt++] = a;
}

void pop() {
	stack[cnt--] = 0;
}

int ccw(int loc[][2], int dotA, int dotB, int dotCurrent) {
	int x1 = loc[dotA][0];
	int y1 = loc[dotA][1];
	int x2 = loc[dotB][0];
	int y2 = loc[dotB][1];
	int x3 = loc[dotCurrent][0];
	int y3 = loc[dotCurrent][0];

	long long tmp1 = x1 * y2 + x2 * y3 + x3 * y1;
	long long tmp2 = y1 * x2 + y2 * x3 + y3 * x1;

	return (int)(tmp1 - tmp2);
}

int polygon(int loc[][2], int sortLoc[], int N) {
	int currentX, currentY;
	int ccwVal;
	//첫번째, 두번째 점 push
	push(sortLoc[1]);
	push(sortLoc[2]);
	push(sortLoc[3]);

	//3 ~ N번째 점 모두 고려하기
	for (int i = 4; i <= N; i++) {
		while (ccw(loc, stack[cnt-2], stack[cnt-1], sortLoc[i]) <= 0) {
			pop();
		}
		
		//i번째 점을 넣는다
		push(sortLoc[i]);
	}

	//마지막 점 체크
	while (ccw(loc, stack[cnt - 2], stack[cnt - 1], sortLoc[1]) <= 0) {
		pop();
	}

	return cnt - head;
}

double getArea(int loc[][2], int sortLoc[], int lineCnt) {
	double areaVal = 0;
	double ccwVal = 0;

	for (int i = 1; i < cnt - 2; i++) {
		ccwVal = ccw(loc, stack[1], stack[1 + i], stack[2 + i]);
		areaVal += (double)ccwVal/2.0;
	}

	return areaVal;
}

double getArea2(int loc[][2], int sortLoc[], int lineCnt) {
	long long tmp1 = 0;
	for (int i = 1; i <= lineCnt - 1; i++) {
		tmp1 += loc[sortLoc[i]][0] * loc[sortLoc[i + 1]][1];
	}
	tmp1 += loc[sortLoc[lineCnt]][0] * loc[sortLoc[1]][1];

	long long tmp2 = 0;
	for (int i = 1; i <= lineCnt - 1; i++) {
		tmp2 += loc[sortLoc[i]][1] * loc[sortLoc[i + 1]][0];
	}
	tmp2 += loc[sortLoc[lineCnt]][1] * loc[sortLoc[1]][0];

	long long result = tmp1 - tmp2;

	return (double)result / 2.0;
}

int main() {

	freopen("input.txt", "r", stdin);

	int loc[N_MAX + 1][2] = { 0, };
	int sortLoc[N_MAX + 1] = { 0, };

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> loc[i][0] >> loc[i][1];
	}


	//음수 값 없애기
	//x음수 값 없애기
	int minVal = loc[1][0];
	for (int i = 2; i <= N; i++) {
		if (loc[i][0] < minVal) {
			minVal = loc[i][0];
		}
	}

	if (minVal < 0) {
		minVal = minVal * (-1);
		for (int i = 1; i <= N; i++) {
			loc[i][0] += minVal;
		}
	}
	//y음수 값 없애기
	minVal = loc[1][1];
	for (int i = 2; i <= N; i++) {
		if (loc[i][1] < minVal) {
			minVal = loc[i][1];
		}
	}

	if (minVal < 0) {
		minVal = minVal * (-1);
		for (int i = 1; i <= N; i++) {
			loc[i][1] += minVal;
		}
	}

	//좌표 정렬하기
	sort(loc, sortLoc, N);

	//for (int i = 1; i <= N; i++) {
	//	cout << sortLoc[i] << " ";
	//}

	//cout << endl << endl;

	//다각형 만들기(stack에 있는 점들이 다각형 점)
	int lineCnt = polygon(loc, sortLoc, N);

	//면적 구하기
	double areaResult = getArea2(loc, sortLoc, lineCnt);
	
	printf("%.f", areaResult);
	//cout << areaResult << endl;

	return 0;
}

