// 플로이드 워샬 : 모든 쌍 최단거리 구하기

#include <stdio.h>

using namespace std;

const int N_MAX = 1000;
const int INFINITI = 99999999;

int N, M; //노드의 수, 간선의 수

int dist[N_MAX + 1][N_MAX + 1] = {0, };


int main(){
    
    //N, M 입력받기
    
    
    //dist 배열 초기화하기
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            dist[i][j] = INFINITI;
        }
    }
    
    //노드 간 가중치 정보 입력 받기
    for (int i=0; i<M; i++){
        int a = 0, b = 0, weight = 0; //입력받기
        
        dist[a][b] = weight;
        dist[b][a] = weight;
        
    }
    
    //3중 for문 시작
    for (int mid=0; mid<N; mid++){ //모든 경유지에 대해
        for (int start=0; start<N; start++){ //모든 시작점에 대해
            for (int end=0; end<N; end++){ //모든 종착점에 대해
                if (start == end) continue;
                if (dist[start][end] > dist[start][mid] + dist[mid][end]){
                    dist[start][end] = dist[start][mid] + dist[mid][end];
                }
            }
        }
        
    }
    
    
    
    
    
}
