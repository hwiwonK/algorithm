//
//  B3020.cpp
//  SDS_algorithm
//
//  https://www.acmicpc.net/problem/3020 : 개똥벌레
//

#include <stdio.h>

const int H_MAX = 500000;
int inputArr[H_MAX + 10] = {0, };

int main(){
    
    freopen("input.txt", "r", stdin);
    
    int N, H;
    scanf("%d %d", &N, &H);
    
    N >>= 1;
    
    for (int i= 0; i<N; i++){
        int h;
        scanf("%d", &h);
        
        //석순
        for (int j = 1; j<=h; j++){
            inputArr[j] += 1;
        }

        //종유석
        scanf("%d", &h);
        int limit = H - h + 1;
        for (int j = H; j >= limit; j--){
            inputArr[j] += 1;
        }
        
    }
    
    //min 구하기
    int minVal = 999999;
    int minCnt = 0;
    
    for (int i=1; i<=H; i++){
        if (minVal > inputArr[i]){
            minCnt = 1;
            minVal = inputArr[i];
        } else if (minVal == inputArr[i]){
            minCnt += 1;
        }
        
    }
    
    printf("%d %d", minVal, minCnt);
    
    return 0;
}
