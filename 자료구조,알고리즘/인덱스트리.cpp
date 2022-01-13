//지속적인 값 변경이 이루어지는 상황에서 구간합 구할 때 사용

#include <stdio.h>


using namespace std;

//"2 ^ K >= (데이터의 수)" 를 만족하는 K값 중 가장 작은 K값 + 1
const int K_MAX = 18;

//인덱스 트리 배열로 저장
long long indexT[(1<<K_MAX) + 10] = {0, };


//밑에서부터 올라가면서 초기화 시키기 : 처음에 모든 수가 일단 다 주어지는 경우
void init(int base){ //base : leaf 데이터의 시작 인덱스
    for (int i=base-1; i>0; i--){
        indexT[i] = indexT[i<<1] + indexT[(i<<1)| 1];
    }
    
}

//x-y 구간합 구하기 //base : leaf 데이터의 시작 인덱스
long long lgSum(int x, int y, int base){
    int xb = x + base - 1; //실제 데이터 시작 번호를 1로 할 경우
    int yb = y + base - 1;
    
    int l = xb < yb ? xb : yb;
    int g = xb > yb ? xb : yb;
    
    long long sum = 0;
    
    while (l <= g){ //특정 height에서 트리 번호 구조 : 2^height(짝) ~ (2^height + 2^height - 1)(홀)
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
    
    int N, Q;
    scanf("%d %d", &N, &Q); //N&Q 입력 받기
    
    int base;
    
    for (base = 1; base < N; base<<=1); //인덱스 트리 구조에서 시작 데이터의 인덱스 (루트노드 = 1) :
    
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

