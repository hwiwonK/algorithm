//
// two point 사용하기
// left - right



#include <stdio.h>

const int N_MAX = 100000;

int arr[N_MAX + 10] = {0, };

int main(){
    
    int N, S;
    
    int result = 999999;
    int curSum = 0;
    
    scanf("%d %d", &N, &S);
    
    for (int i=0; i<N; i++){
        scanf(" %d", &arr[i]);
    }
    
    int left = 0, right = 0;
    
    curSum = arr[0];
    
    while (right < N){
        
        if (left > right) break; //이 부분 없어도 됨
        
        if (curSum >= S){
            //result 갱신
            result = result < right - left + 1 ? result : right - left + 1;
            curSum -= arr[left++];
            
        } else {
            curSum += arr[++right];
        }
    }
    
    if (result == 999999) result = 0;
    
    printf("%d", result);
    
}
