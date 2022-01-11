//https://www.acmicpc.net/problem/2252 : 줄세우기


#include <stdio.h>
#include <queue>

using namespace std;

const int N_MAX = 32000;


queue<int> q;
int indegree[N_MAX + 10] = {0, };
//bool inputArr[N_MAX + 1][N_MAX + 1] = {0, };
vector<int> inputs[N_MAX + 1];

int main(){
    
    freopen("input.txt", "r", stdin);
    
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        inputs[a].push_back(b);
        indegree[b]++;
        
    }
    
    //시작점 모두 넣기
    for (int i=1; i<=N; i++){
        if (!indegree[i]) q.push(i);
    }
    
    
    //위상정렬 시작
    while(!q.empty()){
        //첫번째 지점 방문
        int visit = q.front();
        q.pop();
        printf("%d ", visit);
        
        int limit = inputs[visit].size();
        
        for (int i=0; i<limit; i++) {
            int next = inputs[visit][i];
            indegree[next]--;
            if (!indegree[next]) q.push(next);
        }
        
    }
    
    return 0;
    
}

