// 다익스트라
// 우선순위 큐 (최단거리 탐색 과정 이용)
// 방문 배열 (최단거리 탐색 과정 이용)
// 노드간 인접 정보, 가중치 정보는 struct 벡터 배열로 저장
// 최단거리 정보는 dist 배열에 저장

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int N_MAX = 1000;
const int INFINITI = 99999;

int N, M; //N : 노드의 수, M : 간선의 수

//n : 노드 번호, w : 가중치
struct Data {
    int n, w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};
    bool operator<(const Data d) const {
        return w > d.w;
    }
};


vector<Data> v[N_MAX + 1];
bool visitArr[N_MAX + 1] = {0, };
priority_queue<Data> pq;
int dist[N_MAX + 1] = {0, }; //최종 최단거리 저장 배열


int main(){
    
    //N, M 입력 받기
    
    //tc 반복시 pq clear 필요
    //초기화
    for (int i=0; i<N; i++){
        v[i].clear();
        dist[i] = INFINITI;
    }
    
    
    //간선 정보 입력 받기(a와 b, weight)
    for (int i=0; i<M; i++){
        int a = 0 , b = 0, weight = 0;
        
        //입력 받기
        
        v[a].push_back(Data(b, weight));
    }
    
    int count = 0;
    
    //시작 노드 넣기
    int start = 0;
    pq.push(Data(start, 0));
    
    //ver1. count 체크 안하고 pq 빌 때까지 진행해도 됨
    while (count < N){
        //가장 우선순위 높고 아직 방문하지 않은 노드 방문
        Data now;
        while (true){
            now = pq.top();
            if (!visitArr[now.n]) break; //찾음
            pq.pop(); //이미 방문한 것은 넘기기
        }
        
        //방문 시작
        visitArr[now.n] = true;
        count++;
        pq.pop();
        
        //인접 노드 최단거리 갱신 (갱신될 때만 pq에 넣기)
        for (int i=0; i<v[now.n].size(); i++){
            Data next = v[now.n][i];
            if (dist[next.n] > dist[now.n] + next.w){
                dist[next.n] = dist[now.n] + next.w;
                pq.push(Data(next.n, dist[next.n]));
            }
        }
        
        
    }
    
    //ver2. pq 빌 때까지 진행
    while (!pq.empty()){
        Data now;
        now = pq.top();
        pq.pop();
        
        if (visitArr[now.n]) continue;
        
        visitArr[now.n] = true;
        
        //인접 노드 최단거리 갱신 (갱신될 때만 pq에 넣기)
        for (int i=0; i<v[now.n].size(); i++){
            Data next = v[now.n][i];
            if (dist[next.n] > dist[now.n] + next.w){
                dist[next.n] = dist[now.n] + next.w;
                pq.push(Data(next.n, dist[next.n]));
            }
        }
        
    }
    
    
}
