// https://www.acmicpc.net/problem/1516 : 게임 개발

// 예외 생각해보기
//   q에 넣는 순간에도 이전의 어떤 건물(ex 5)이 이미 짓고있는 중일 수 있다 => 어떤 node 방문 할 때마다 이전 시간값의 최댓값 지속적 갱신이 필요하다
//   건물 번호   1  2  3  4  5
//   indegree  0  2  1  2  0
//   다음 건물  2,3 4  2     4

#include <stdio.h>
#include <queue>

using namespace std;

const int N_MAX = 500;

queue<int> q;
int indegree[N_MAX + 10] = {0, };
vector<int> inputs[N_MAX + 1];
int minTime[N_MAX + 10] = {0, };
int inputTime[N_MAX + 10] = {0, };


int main(){
    freopen("input.txt", "r", stdin);
    
    int N;
    scanf("%d", &N);
    
    for (int i=1; i<=N; i++){
        
        int time;
        scanf("%d", &time);
        inputTime[i] = time;
        
        while(true){
            int tmp;
            scanf("%d", &tmp);
            
            if (tmp == -1) break;
            
            inputs[tmp].push_back(i);
            indegree[i]++;
        }
    }
    
    //시작점 모두 넣기
    for (int i=1; i<=N; i++){
        if (!indegree[i]) {
            q.push(i);
            //시간 저장
            minTime[i] = inputTime[i];
        }
    }
    
    
    //위상정렬 시작
    while(!q.empty()){
        //첫번째 지점 방문
        int visit = q.front();
        q.pop();
        int curTime = minTime[visit]; //지금까지 진행 시간
        
        int limit = inputs[visit].size();
        
        for (int i=0; i<limit; i++) {
            int next = inputs[visit][i];
            indegree[next]--;
            minTime[next] = minTime[next] > curTime ? minTime[next] : curTime;
            if (!indegree[next]) {
                q.push(next);
                //시간 저장
                minTime[next] = minTime[next] > curTime ? minTime[next] : curTime;
                minTime[next] += inputTime[next];
            }
        }
        
    }
    
    //시간 출력
    for (int i=1; i<=N; i++){
        printf("%d\n", minTime[i]);
    }
    
    return 0;
}


