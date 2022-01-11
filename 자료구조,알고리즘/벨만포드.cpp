//벨만포드
//그래프에서 음의 순환 존재 여부를 확인하는 알고리즘

#include <stdio.h>

using namespace std;

const INF 999999999;

struct Data {
    int a, b, c;
    Data() {};
    Data(int a, int b, long long c) : a(a), b(b), c(c) {};
};

int N, M;
long long dist[501];
Data list[6000];

int main() {


    //N, M 입력받기
    
    //간선 정보 입력받기
    for (int i = 0; i < M; i++) {
        int a, b, c; //a->b : weight c
        list[i] = Data(a, b, c);
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[1] = 0;
    
    //총 N-1번 반복
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) { //모든 간선에 대해 경로 검사
            if (dist[list[j].a] == INF) continue;
            if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
                dist[list[j].b] = dist[list[j].a] + list[j].c;
            }
        }
    }
    bool isCycle = false;
    
    //N번째 순환에서 갱신되면 음의 순환 존재함 파악 가능
    for (int j = 0; j < M; j++) {
        if (dist[list[j].a] == INF) continue;
        if (dist[list[j].b] > dist[list[j].a] + list[j].c) {
            isCycle = true;
            break;
        }
    }

    //isCycle이 false라면 : dist 배열에는 각 도착지까지 최단 거리 저장
    //isCycle이 true라면 : 음의 순환 발생 -> 최단 거리 구하는 것 의미 없음

    return 0;
}
