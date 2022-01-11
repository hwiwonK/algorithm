// M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수를 나타낸다. 단, 2≤M,N≤1,000 이다.
// 둘째 줄부터 N 개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M 개의 정수로 주어진다.
// 정수 1 은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1 은 토마토가 들어있지 않은 칸을 나타낸다.
// 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.(상, 하, 좌, 우)
// 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
// 최소 날짜 출력/ 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1 을 출력

// BFS 이용해서 풀이하기<br>
// 익은 토마토를 queue에 넣어놓고, 상-하-좌-우 체크하며 안 익은 것 queue에 넣고 level 체크
// queue의 마지막 원소의 level 반환
// 0인 토마토 찾기 -> 1까지 최단거리 찾기 (시간 초과)


#include <iostream>
 
using namespace std;
 
const int N_MAX = 1000;
 
int box[N_MAX + 1][N_MAX + 1] = { 0, };
int d[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int tomatoCnt = 0; //안 익은 토마토의 수
bool visit[N_MAX + 1][N_MAX + 1] = { false, };
 
struct tomatoLoc {
    int x;
    int y;
    int level;
};
 
int front = -1;
int rear = -1;
 
struct tomatoLoc queue[N_MAX * N_MAX];
 
void enqueue(int xpos, int ypos, int level) {
    rear++;
    queue[rear].x = xpos;
    queue[rear].y = ypos;
    queue[rear].level = level;
}
 
 
 
//1까지 최단 거리 구하기
int bfs(int N, int M) {
    //첫번째 점 enqueue하기 - level 0으로
 
    while (front != rear) {
 
        //방문하기
        front++;
        int visitX = queue[front].x;
        int visitY = queue[front].y;
        int visitLevel = queue[front].level;
 
 
        //상-하-좌-우 체크
        for (int a = 0; a < 4; a++) {
            int xpos = visitX + d[a][0];
            int ypos = visitY + d[a][1];
 
            //경계선 체크
            if (xpos > N || ypos > M || xpos < 1 || ypos < 1) continue;
 
            if (box[xpos][ypos] == 0) {
                enqueue(xpos, ypos, visitLevel + 1);
                box[xpos][ypos] = 1;
                tomatoCnt--;
 
                if (tomatoCnt == 0) return queue[rear].level;
            }
        }
    }
 
    return queue[rear].level;
 
}
 
 
int main() {
 
 
    int M, N;
 
    scanf("%d %d", &M, &N);
 
 
    //입력 받기
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1) {
                enqueue(i, j, 0);
            }
            if (box[i][j] == 0) tomatoCnt++;
        }
    }
 
    if (front == rear) {
        cout << "0";
        return 0;
    }
 
    //1토마토 찾으면 주변 익게 하기(bfs)
 
    int result = bfs(N, M);
 
 
    if (tomatoCnt == 0) {
        printf("%d", result);
    }
    else {
        printf("-1");
    }
 
    //printf("%d", result);
 
 
    return 0;
}
