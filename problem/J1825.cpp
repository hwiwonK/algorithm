#include <iostream>
 
using namespace std;
 
const int MONEY_MAX = 300;
const int COMPANY_MAX = 20;
 
int money[MONEY_MAX + 1][COMPANY_MAX + 1] = { 0, };
int dpArr[MONEY_MAX + 1][COMPANY_MAX + 1] = { 0, };
int path[MONEY_MAX + 1][COMPANY_MAX + 1] = { 0, };
 
int main() {
 
 
    //입력 받기(M : 투자 금액, N : 기업의 수)
    int M, N;
 
    scanf("%d", &M);
    scanf("%d", &N);
 
    int idx;
 
    for (int i = 1; i <= M; i++) {
        scanf("%d", &idx);
        for (int j = 1; j <= N; j++) {
            scanf("%d", &money[i][j]);
        }
    }
 
    //i만큼의 투자금액, j번째 기업까지 고려
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            int maxVal = -1;
 
            //j번째 기업에게 k만원 투자
            for (int k = 0; k <= i; k++) {
                int tmp = dpArr[i - k][j - 1] + money[k][j];
                if (tmp > maxVal) {
                    maxVal = tmp;
                    path[i][j] = k;
                }
            }
 
            dpArr[i][j] = maxVal;
        }
     
    }
 
    printf("%d\n", dpArr[M][N]);
 
    //경로 출력
    int row = M, col = N;
    int result[COMPANY_MAX + 1] = { 0, };
    for (int i = N; i >= 1; i--) {
        int curRow = row, curCol = col;
        result[i] = path[row][col];
 
        row = curRow - path[row][col];
        col = curCol - 1;
 
    }
 
    for (int i = 1; i <= N; i++) printf("%d ", result[i]);
 
    return 0;
}
