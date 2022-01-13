//N개의 정점으로 이루어진 트리

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int const MAX = 20;

int N, M;
int a, b;
int dp[MAX + 1][100001]; //2^i 번째 부모 노드 저장 / [1]번 노드의 2^[0] 번째 부모 노드
int depth[100001]; //각 노드의 깊이 저장
bool isVisited[100001];
vector<int> v[100001];

void dfs(int n, int d) {

    isVisited[n] = true;
    depth[n] = d;
    int vi;
    for (int i = 0; i < v[n].size(); i++) {
        vi = v[n].at(i);
        if (isVisited[vi]) continue; //중복 방문하는 경우가 생기는지?
        dp[0][vi] = n; //vi의 2^0(1)번째 노드 = n
        dfs(vi, d + 1); //vi 노드를 부모로, 깊이는 늘려준다
    }
}

void setDP() {
    for (int i = 1; i < MAX; i++) { //2^0 ~ 2^MAX 번째 부모에 대해
        for (int j = 1; j <= N; j++) { //모든 노드에 대해
            dp[i][j] = dp[i - 1][dp[i - 1][j]]; //j번 노드의 2^i번째 부모 = j의 2^(i-1) 번째 부모의 2^(i-1)번째 부모
        }
    }
}
int lca(int x, int y) {
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = MAX; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i))
            y = dp[i][y];
    }
    if (x == y) return x;

    for (int i = MAX; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}
int main() {
    scanf("%d", &N);

    for (int i = 1; i < N; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(isVisited, 0, sizeof(isVisited));
    
    //바로 위의 부모와 깊이 체크해주기
    //1번 노드의 깊이는 1로
    dfs(1, 1);
    
    //각 노드에 대해 2^0 ~ 2^MAX 번째 부모 구하기
    setDP();

    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
