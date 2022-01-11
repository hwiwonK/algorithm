// https://www.acmicpc.net/problem/1275 : 커피숍2
// index tree 활용
// fenwick tree 활용하는 방법도 있음

#include <stdio.h>

using namespace std;

const int K_MAX = 18;

long long indexT[(1<<K_MAX) + 10] = {0, };

//밑에서부터 올라가면서
void init(int base){
    for (int i=base-1; i>0; i--){
        indexT[i] = indexT[i<<1] + indexT[(i<<1)| 1];
    }
    
}

//x-y 구간합 구하기
long long lgSum(int x, int y, int base){
    int xb = x + base - 1;
    int yb = y + base - 1;
    
    int l = xb < yb ? xb : yb;
    int g = xb > yb ? xb : yb;
    
    long long sum = 0;
    
    while (l <= g){
        if ((l & 1) == 1) sum += indexT[l];
        if ((g & 1) == 0) sum += indexT[g];
        
        l = (l + 1) >> 1;
        g = (g - 1) >> 1;
    }
    
    return sum;
}

void update(int a, int b, int base){
    int ab = a + base - 1;
    indexT[ab] = b;
    
    while(ab >>=1){ //루트까지 가고 끝남
        indexT[ab] = indexT[ab<<1] + indexT[(ab<<1)|1];
    }
    
}

int main(){
    freopen("input.txt", "r", stdin);
    
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    int base;
    
    for (base = 1; base < N; base<<=1);
    
    int limit = base + N;
    for (int i=base; i<limit; i++){
        scanf("%lld", &indexT[i]);
    }
    
    init(base);
    
    for (int i=0; i<Q; i++){
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        printf("%lld\n", lgSum(x, y, base));
        update(a, b, base);
        
    }
}
