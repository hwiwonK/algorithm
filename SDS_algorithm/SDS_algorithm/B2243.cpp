// https://www.acmicpc.net/problem/2243 : 사탕상자


#include <stdio.h>

const int N_MAX = 21;

int indexT[(1<<N_MAX) + 10] = {0, };

void update(int p, int v, int base){
    p += (base-1);
    indexT[p] += v;
    while(p >>=1){ //루트까지 가고 끝남
        indexT[p] = indexT[p<<1] + indexT[(p<<1)|1];
    }
}


int getCandy(int n, int base){
    int p = 1;
    while (p<base){
        p <<= 1;
        
        if (indexT[p] < n) { //왼쪽에 없다는 것
            n -= indexT[p];
            p += 1;
        }
    }
    
    return p - base + 1;
}


int main(){
    
    freopen("input.txt", "r", stdin);
    
    int n;
    scanf("%d", &n);
    
    int base = 1, N = 1000000;
    
    for (base=1; base<N; base<<=1);
    
    for (int i=0; i<n; i++){
        int a, b, c;
        scanf("%d %d", &a, &b);
        
        if (a==1){
            int candyN = getCandy(b, base);
            printf("%d\n", candyN);
            update(candyN, -1, base);
            
        } else if (a==2){
            scanf("%d", &c);
            update(b, c, base);
        }
    }
    
    return 0;
    
}
