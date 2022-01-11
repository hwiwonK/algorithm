//https://www.acmicpc.net/problem/1922 : 네트워크 연결
// Kruskal 알고리즘 이용
// Prim 알고리즘 이용

#include <stdio.h>
#include <queue>

using namespace std;

const int N_MAX = 1000;



struct Data {
    int node1, node2, weight;
    Data() {};
    Data(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight){};

    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

priority_queue<Data> pq;

int parents[N_MAX + 10] = {0, };

int find(int v){
    if (parents[v] == v) return v;
    return parents[v] = find(parents[v]);
}


void unionSet(int a, int b){
    parents[find(a)] = find(b);
}

int main(){
    
    freopen("input.txt", "r", stdin);
    
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<M; i++){
        int a, b, dist;
        
        scanf("%d %d %d", &a, &b, &dist);
        
        pq.push(Data(a, b, dist));
//        Data tmp;
//        tmp = {a, b, dist};
//        pq.push(tmp);
        
    }
    
    //parent배열 초기화
    for (int i=1; i<=N; i++){
        parents[i] = i;
    }
    
    int count = 0, answer = 0;
    
    while (true){
        if (count == N - 1) break;
        
        Data tmp = pq.top();
        pq.pop();
        
        if (find(tmp.node1) != find(tmp.node2)){
            answer += tmp.weight;
            unionSet(tmp.node1, tmp.node2);
            count += 1;
        }
        
    }
    
    printf("%d", answer);
    
}
