#include <iostream>
 
using namespace std;
 
const int N_MAX = 100;
 
bool paper[N_MAX][N_MAX] = { false, };
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int countSort[N_MAX * N_MAX + 1] = { 0, };
 
 
int dfs(int M, int N, int y, int x, int cnt) {
    //i, j 방문
    paper[y][x] = true;
    cnt++;
 
    for (int i = 0; i < 4; i++) {
        int xpos = x + d[i][0];
        int ypos = y + d[i][1];
 
        //경계선 체크
        if (xpos >= N || ypos >= M || xpos < 0 || ypos < 0) continue;
 
        if (!paper[ypos][xpos]) cnt = dfs(M, N, ypos, xpos, cnt);
    }
 
    return cnt;
 
}
 
int main() {
 
    //입력 받기
    int M, N, K;
 
    scanf("%d %d %d", &M, &N, &K);
 
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
 
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 
        //직사각형 true로 마킹하기
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                paper[i][j] = true;
            }
        }
    }
 
    //for (int i = 0; i < M; i++) {
    //  for (int j = 0; j < N; j++) {
    //      cout << paper[i][j] << " ";
    //  }
    //  cout << endl;
    //}
 
    //빈 공간 찾으면 dfs
 
    int blockCnt = 0;
    int eachBlock = 0;
 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!paper[i][j]) {
                eachBlock = dfs(M, N, i, j, 0);
                blockCnt++;
                countSort[eachBlock]++;
            }
        }
    }
 
    //결과 출력
 
    printf("%d\n", blockCnt);
 
    int limit = N * M; //총 모눈의 수, 최대 넓이
    int tmp = 0;
 
    for (int i = 1; i <= limit; i++) {
        tmp = countSort[i];
        for (int j = 0; j < tmp; j++) {
            printf("%d ", i);
        }
        //if (tmp > 0) {
        //  printf("%d ", i);
        //}
    }
 
 
 
 
    return 0;
}
