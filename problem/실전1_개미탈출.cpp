//https://cafe.naver.com/cozal

#include <iostream>
#include <map>

using namespace std;

const int N_MAX = 5000;

//map<int, map<int, int>> antPos;
multimap<int, int> ant;

int antDist[N_MAX + 1][N_MAX + 1] = { 0, };

struct oneAnt {
	int yPos;
	int xPos;
} oneAnt;

//방향 별로 저장
struct oneAnt antPos[4][N_MAX + 1] = { 0, };


struct twoAnt {
	int ant1N;
	int ant2N;
	int dist;
} twoAnt;




int main() {

	freopen("input.txt", "r", stdin);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {

		//입력 받기
		int M, N, K;

		scanf("%d %d %d", &M, &N, &K);

		for (int i = 1; i <= N; i++) {
			int xPos, yPos;
			scanf("%d %d", &xPos, &yPos);
			ant.insert(pair<int, int>(xPos, yPos));
		}


		



	}




	return 0;
}
