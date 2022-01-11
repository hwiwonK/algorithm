//https://www.acmicpc.net/problem/2042 : 구간 합 구하기
//index tree, segment tree 연습하는 문제
//tree의 길이, 숫자의 범위 잘 파악하기

#include <stdio.h>

using namespace std;

const int N_MAX = 21; //2^(N) N이 20인 순간에 100만 넘어감

long long indexT[(1<<N_MAX) + 10] = {0, };

//원소 하나마다 update 하지 말고 init 하는 함수 추가해서 좀 더 빠르게 만들어보기

void update(long long p, long long v, long long base){
    p += (base-1);
    indexT[p] = v;
    while(p >>=1){ //루트까지 가고 끝남
        indexT[p] = indexT[p<<1] + indexT[(p<<1)|1];
    }
}

long long lgSum(long long l, long long r, long long base){
    l += (base-1); r += (base-1);
    long long sum = 0;
    while (l<=r){
        if ((l&1) == 1) sum += indexT[l]; //left pointer가 오른쪽 부분에
        if ((r&1) == 0) sum += indexT[r]; //right pointer가 왼쪽 부분에

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}


int main(){
    
    freopen("input.txt", "r", stdin);
    
    int N, M, K;
    
    scanf("%d %d %d", &N, &M, &K);
    
    //인덱스 트리에서 leaf node 첫번재 인덱스 구하기
    long long base = 1;
    
    for (base=1; base<N; base<<=1);
    
    for (int i=1; i<=N; i++){
        int num;
        scanf("%d", &num);
        update(i, num, base);
    }
    
    int commandN = -1;
    commandN = M + K;
    
    for (int i=1; i<=commandN; i++){
        int a;
        long long b, c;
        scanf("%d %lld %lld", &a, &b, &c);
        
        if (a == 1) update(b, c, base);
        else if (a == 2) {
            printf("%lld\n", lgSum(b, c, base));
        }
    }
    
    return 0;
    
}
