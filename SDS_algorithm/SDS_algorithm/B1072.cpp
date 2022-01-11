//
//  B1072.cpp
//  SDS_algorithm
//
//  Created by Kimhwiwon on 2022/01/04.
// 이진 탐색 이용하기, upper bound = 10억
// 이진 탐색 이용하지 않는 방법도 있을 것 같음

#include <stdio.h>
#include <cmath>

int main(){
    long long X, Y;
    int Z;
    
    scanf("%lld %lld", &X, &Y);
    
    
    Z = Y * 100 / X;
    
//    printf("%d", Z);
    
    if (Z == 99) {
        printf("-1");
        return 0;
    }
    
    double n = (double)(X*Z + X - 100*Y)/ (double)(99-Z);
    
    long long finalN = ceil(n);
    
    
    if (finalN < 0){
        printf("-1");
    } else {
        printf("%lld", finalN);
    }
    
    return 0;
}
