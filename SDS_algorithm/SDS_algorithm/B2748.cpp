// dp
// 수의 범위 체크하기

#include <stdio.h>

const int N_MAX = 90;

int main(){
    
    int N;
    long long fibo[N_MAX + 10] = {0, };
    scanf("%d", &N);
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    for (int i = 2; i <= N; i++){
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
    
    printf("%lld\n", fibo[N]);
    
}





