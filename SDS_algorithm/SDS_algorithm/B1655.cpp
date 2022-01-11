//https://www.acmicpc.net/problem/1655 : 가운데를 말해요
//가운데 있는 수 return (2개라면 앞에 있는 수)
//2개의 priority queue 사용 (minheap, maxheap) / index tree로도 풀기 가능할듯(B2243 사탕상자)
//=========================================
//ㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅣㅣㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅢ
//      max heap            min heap
// 주의 : priority queue size 반환 값은 unsigned long 이다
// TIP : minHeap 만들 때 굳이 greater 기준 안넣고, -num 값을 활용하여 heap 만들어도 오름차순 정렬 가능

#include <stdio.h>
//#include <iostream>
#include <queue>

using namespace std;

const int N_MAX = 100000;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int answer[N_MAX + 10] = {0, };

// 일단 크기 작은 쪽에 넣은 후에 값 비교하기 (logN + 4*logN) : 시간 조금 더 걸릴 것, 코드가 훨씬 간단
// 내 코드 : 값 비교를 먼저 한다면? (logN + 2*logN) : 시간 조금 덜 걸릴 것, 코드가 다소 복잡
void modelAnswer(){
    priority_queue<int> maxheap, minheap;

    int N;
    scanf("%d", &N);

    for(int i=0, num; i<N; i++)
    {
        scanf("%d", &num);
        if(maxheap.size() > minheap.size()) minheap.push(-num);
        else maxheap.push(num);

        if(maxheap.size()>0 && minheap.size()>0)
        {
            //maxheap이 더 큰 경우 minheap과 교환
            if(maxheap.top() > -minheap.top())
            {
                int maxtop = maxheap.top();
                int mintop = -minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(-maxtop);
            }
        }
        printf("%d\n", maxheap.top());
    }
}


void balance(){
    //균형 맞추기
//    cout << (maxHeap.size() < (minHeap.size() - 1));
    int maxSize = (int)maxHeap.size();
    int minSize = (int)minHeap.size();
    
    
    if (maxSize < minSize){
        int val = minHeap.top();
        minHeap.pop();
        maxHeap.push(val);
    } else if (minSize < (maxSize - 1)){
        int val = maxHeap.top();
        maxHeap.pop();
        minHeap.push(val);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    
    int N, idx = 0;
    
    scanf("%d", &N);
    
    int tmp;
    scanf("%d", &tmp);
    maxHeap.push(tmp);
    answer[idx++] = maxHeap.top();
    
    for (int i=2; i<=N; i++){
        scanf("%d", &tmp);
        
        //값 Push 하기
        //첫번째 or 두번째 원소
        if (minHeap.empty()){
            maxHeap.push(tmp);
            balance();
        } else {
            if (tmp < maxHeap.top()){
                maxHeap.push(tmp);
                balance();
                
            } else if (tmp > minHeap.top()){
                minHeap.push(tmp);
                balance();
                
            } else {
                if (maxHeap.size() <= minHeap.size()){
                    maxHeap.push(tmp);
                    
                } else {
                    minHeap.push(tmp);
                }
            }
            
        }
        
        answer[idx++] = maxHeap.top();
    }
    
    for (int i=0; i<N; i++){
//        cout << answer[i] << '\n';
        printf("%d\n", answer[i]);
    }
    
    return 0;
}
