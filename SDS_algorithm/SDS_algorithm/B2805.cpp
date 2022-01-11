//
//  B2805.cpp
//  SDS_algorithm
//
//  Created by Kimhwiwon on 2022/01/04.
// binary search 이용, 결정 함수가 중요



#include <stdio.h>
#include <algorithm>

using namespace std;

const int N_MAX = 1000000;
//const int M_MAX = 2000000000;

int trees[N_MAX + 10] = {0, };
//long long sumArr[N_MAX + 10] = {0, };

int main(){
    
    int N;
    int M;
//    int result = M_MAX;
    int maxLen = -1;
    
    scanf("%d %d", &N, &M);
    
    for (int i=0; i<N; i++){
        int inputV;
        scanf(" %d", &inputV);
        maxLen = max(inputV, maxLen);
        trees[i] = inputV;
    }

// 정렬써서 합 구하기 더 쉬운 방법 생각해보기
//    //정렬
//    sort(trees, trees + N, greater<int>());
//
////  현재 위치까지 합 구하기
//    sumArr[0] = trees[0];
//    for (int i=1; i<N; i++){
//        sumArr[i] = sumArr[i-1] + trees[i];
//    }
    
    //이진 탐색
    int left = 0, right = maxLen;
    
    
    while (left <= right){
        long long tmp = 0;
        
        int mid = (left + right) / 2;
    
        //현재 절단기 길이 = mid 기준 결과 계산
//        for (int i = N-1; i>=0; i--){
//            if (trees[i] > mid) {
//                tmp += sumArr[i] - mid * (i + 1);
//                break;
//            }
//        }
        
        for (int i = 0; i < N; i++){
            if (trees[i] > mid) tmp += trees[i] - mid;
//            tmp += max(0, trees[i] - mid);
        }
        
//        if (tmp == M) {
//            left = mid;
//            break;
//        }
//
        //가능한 경우
        if (tmp >= M){
            left = mid + 1;
//            result = max(mid, result);
        } else {
            right = mid - 1;
        }
        
    }
    
    printf("%d", right);
    
}
