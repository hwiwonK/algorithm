// 첫줄에 N(3≤N≤100), M(1≤M≤N)을 입력 받는다. 
// N은 지하철역의 수, M은 원하는 목적역의 번호를 입력받는다. 
// 둘째 줄부터 N개의 줄이 나오고, 각 줄에는 N개의 수 S가 입력된다. 
// i번째 줄에서 j번째 수 Sij는 i번역에서 j번 역까지 가는데 걸리는 시간이다. 
// 1번 역이 숙소가 있는 역이고, Sij에서 i = j 일 때는 항상 0 이다. (0≤S≤100)
// 목적 역까지 가는데 걸리는 최소 시간과 최소시간으로 가는 최단경로를 출력한다.

#include <iostream>
 
using namespace std;
 
const int N_MAX = 100;
const int INFINITI = 999;
 
int subway[N_MAX + 1][N_MAX + 1] = { 0, };
int dist[N_MAX + 1] = { 0, };
bool visit[N_MAX + 1] = { false, };
int path[N_MAX + 1] = { 0, }; //첫번째에는 경로의 수
 
//아직 방문 안한 것 중에
int extractMin(int N) {
    int minVal = 999;
    int minIdx = -1;
    for (int i = 1; i <= N; i++) {
        if ((!visit[i]) && minVal > dist[i]) {
            minVal = dist[i];
            minIdx = i;
        }
    }
 
    return minIdx;
}
 
//M 방문 순간 멈추기
void dijkstra(int N, int M) {
    int goal;
     
    //dist 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = INFINITI;
    }
 
    //방문하기
    dist[1] = 0;
    //visit[1] = true;
 
    while (visit[M] == false) {
        goal = extractMin(N);
        visit[goal] = true;
 
        //goal과 인접한 곳 거리 갱신
        for (int candi = 1; candi <= N; candi++) {
            if (goal == candi) continue;
            if ((dist[candi] > dist[goal] + subway[goal][candi]) && (!visit[candi])) {
                dist[candi] = dist[goal] + subway[goal][candi];
 
                //경로 추가
                path[candi] = goal;
            }
 
        }
    }
}
 
int main() {
 
    int N, M;
 
    scanf("%d %d", &N, &M);
 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &subway[i][j]);
            if (subway[i][j] == 0) subway[i][j] = INFINITI;
        }
    }
 
    dijkstra(N, M);
 
    printf("%d\n", dist[M]);
 
    //경로 출력
 
    int pathPrint[N_MAX + 1] = { 0, };
    int pathCnt = -1;
 
    pathPrint[++pathCnt] = M;
    int tmp = path[M];
 
    while (tmp != 1) {
        pathCnt++;
        pathPrint[pathCnt] = tmp;
        tmp = path[tmp];
    }
 
    pathCnt++;
    pathPrint[pathCnt] = 1;
 
    for (int i = pathCnt; i >= 0; i--) {
        printf("%d ", pathPrint[i]);
    }
 
    return 0;
}
