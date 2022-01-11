// 아이디어 혼자 생각 못함 <br>
// 흔한 dp 접근법! 현재의 것 선택한다고 가정할 때의 최적의 값을 기록하는 아이디어!<br>
// 다른 접근법 : 현재 위치 까지의 거리가 최대거리를 초과하는 순간에 값 비교해서 업데이트 하기(?)

#include <iostream>

//현재 정비소를 마지막으로 점검하게 될 때의 최솟값
//아이디어 어려움

using namespace std;

const int N_MAX = 100;
int dist[N_MAX + 1] = { 0, };
int timeArr[N_MAX + 1] = { 0, };
int dpArr[N_MAX + 2][2] = { 0, }; //시간, 이전 방문 정비소 저장
int visit[N_MAX] = { 0, };

void DP(int N, int maxDist) {
	
	//1번에서 도착지 까지
	for (int i = 1; i <= N + 1; i++) {

		int distTmp = 0;
		int candi = i - 1;
		int minIdx = candi;
		int minTime = dpArr[minIdx][0];

		//maxDist 반경 안에 있는 정비소 검사
		while (candi >= 0) {
			distTmp += dist[candi];

			if (distTmp > maxDist) break;

			if (minTime > dpArr[candi][0]) {
				minTime = dpArr[candi][0];
				minIdx = candi;
			}
			
			candi--;
		}

		//반경 내 최솟값 + 현재 정비소 시간 더하기 & 이전 방문한 정비소 인덱스 저장
		dpArr[i][0] = minTime + timeArr[i];
		dpArr[i][1] = minIdx;

	}


}

int main() {
	freopen("input.txt", "r", stdin);

	int maxDist, N;

	scanf("%d %d", &maxDist, &N);

	for (int i = 0; i <= N; i++) {
		scanf("%d", &dist[i]);
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &timeArr[i]);
	}

	//dp
	DP(N, maxDist);

	//방문하는 정비소 구하기
	int visitCnt = 0;
	int current = N + 1;

	while (current != 0) {
		visit[visitCnt++] = dpArr[current][1];
		current = dpArr[current][1];
	}

	if (visitCnt - 1 == 0) {
		printf("0");
		return 0;
	}

	printf("%d\n%d\n", dpArr[N + 1][0], visitCnt - 1);

	for (int i = visitCnt - 2; i >= 0; i--) {
		printf("%d ", visit[i]);
	}


	return 0;
}
