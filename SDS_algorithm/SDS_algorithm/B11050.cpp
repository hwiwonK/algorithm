//https://www.acmicpc.net/problem/11050 : 이항계수 1
#include <stdio.h>

using namespace std;

const int N_MAX = 10;

int pascal[(N_MAX + 1)][(N_MAX + 1)];

int main(){
    
//    freopen("input.txt", "r", stdin);
    
    int N, K;
    
    scanf("%d %d", &N, &K);
    
    pascal[0][0] = 1;
    
    //N이 1일 때부터 N일 때까지
    for (int i=1; i<=N; i++){
        pascal[i][0] = 1;
        
        for (int j = 1; j<=i; j++){
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
        
    }
    
    printf("%d", pascal[N][K]);
}
