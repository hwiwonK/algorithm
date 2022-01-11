// https://www.acmicpc.net/problem/15686 : 치킨 배달
// 조합 응용 , bfs 돌릴 이유 없음. 이미 좌표 알고있기 때문

#include <stdio.h>
#include <cmath>

using namespace std;

const int N_MAX = 50;
const int M_MAX = 13;

int homes[N_MAX*2 + 10][2] = {0, };
int chickens[N_MAX*N_MAX + 10][2] = {0, };

int top = 0;
int D[M_MAX + 5] = {0, };


int hn = 0, cn = 0; //집, 치킨집 개수
int minDist = 9999;

//void printD(int N, int M)
//{
//    for(int i=0; i<M; i++) printf("%d ", D[i]);
//    printf("\n");
//}

//동네의 치킨거리 구하기(minDist갱신)
void dist(int M){
    int sumDist = 0;
    
    //모든 집에 대해 loop 돌면서
    for (int i=0; i<hn; i++){
        int homeDist = 999;
        //모든 치킨집에 대해 loop 돌면서
        for (int j=0; j<M; j++){
            int r = chickens[D[j]][0];
            int c = chickens[D[j]][1];
            
            int tmp = abs(homes[i][0] - r) + abs(homes[i][1] - c);
            homeDist = homeDist < tmp ? homeDist : tmp;
        }
        
        sumDist += homeDist;
    }
    
    minDist = minDist < sumDist ? minDist : sumDist;
    
}

void backtracking(int start, int N, int M)
{
    if(top == M)
    {
        dist(M);
        return;
    }

    for(int i=start; i<N; i++)
    {
        //가지치기
        if(N-i < M-top) break;
        D[top++] = i;
        backtracking(i+1, N, M);
        top--;
    }
}


int main(){
    
    freopen("input.txt", "r", stdin);
    
    int NN, MM;
    scanf("%d %d", &NN, &MM);
    
    //좌표 입력 받기
    for (int i=0; i<NN; i++){
        for (int j=0; j<NN; j++){
            int tmp;
            scanf("%d", &tmp);
            
            if (tmp == 1){
                homes[hn][0] = i;
                homes[hn++][1] = j;
            } else if (tmp == 2){
                chickens[cn][0] = i;
                chickens[cn++][1] = j;
            }
        }
        
    }
    
    //조합 구하기
    backtracking(0, cn, MM);
    
    printf("%d", minDist);
    
}


