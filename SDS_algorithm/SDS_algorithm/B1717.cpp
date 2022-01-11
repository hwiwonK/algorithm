//https://www.acmicpc.net/problem/1717 : 집합의 표현

#include <stdio.h>

using namespace std;

const int N_MAX = 1000000;

int sets[N_MAX + 10] = {0, };
//vector <string> answer;

int find(int v){
    if (sets[v] == v) return v;
    return sets[v] = find(sets[v]);
}


void unionSet(int a, int b){
    sets[find(a)] = find(b);
}



int main(){
    freopen("input.txt", "r", stdin);
    
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i=0; i<=n; i++) {
        sets[i] = i;
    }
    
    for (int i=0; i<m; i++){
        int a, b, c;
        
        scanf("%d %d %d", &a, &b, &c);
        
        
        if (a == 0){
            
            unionSet(b, c);
            
        } else if (a == 1){
            
            if (find(b) == find(c)){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        
    }
    
    
    return 0;
    
}
