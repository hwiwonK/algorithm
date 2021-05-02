#include <iostream>
 
using namespace std;
 
const int N_MAX = 1000;
const int W_MAX = 1000;
 
int dpArr[W_MAX+1][W_MAX+1] = { 0, }; //경찰차 A가 i에, B가 j에 있을 때 남은 최단 거리
 
struct choiceData {
    int policeN;
    int nextRow;
    int nextCol;
} choiceData;
 
struct choiceData choice[W_MAX + 1][W_MAX + 1] = { 0, };
 
struct missionPos {
    int row;
    int col;
} missionPos;
 
struct missionPos mission[W_MAX+1] = { 0, }; //사건들의 위치, 인덱스는 사건 번호
 
int abs(int a, int b) {
    if (a > b) {
        return a - b;
    }
    else {
 
        return b - a;
    }
}
 
int main() {
 
 
    //입력 받기
    int N, W;
 
    scanf("%d", &N);
    scanf("%d", &W);
 
    for (int i = 1; i <= W; i++) {
        scanf("%d %d", &mission[i].row, &mission[i].col);
    }
 
 
    //i = 경찰차 A 현재 mission, j = 경찰차 B 현재 mission
    for (int i = W - 1; i >= 0; i--) {
        for (int j = W - 1; j >= 0; j--) {
            if (i == j && i != 0 && j != 0) continue;
 
            //다음 사건 구하기
            int nextMission = i > j ? i : j;
            nextMission++;
 
            //다음 사건 A가 해결
            //i ~ 다음 사건 거리
            int distA = abs(mission[nextMission].row, mission[i].row) + abs(mission[nextMission].col, mission[i].col);
            if (i == 0) distA = (mission[nextMission].row - 1) + (mission[nextMission].col - 1);
             
            int caseA = dpArr[nextMission][j]+ distA;
 
            //다음 사건 B가 해결
            int distB = abs(mission[nextMission].row, mission[j].row) + abs(mission[nextMission].col, mission[j].col);
            if (j == 0) distB = (N - mission[nextMission].row) + (N - mission[nextMission].col);
            int caseB = dpArr[i][nextMission] + distB;
 
            dpArr[i][j] = caseA < caseB ? caseA : caseB;
            if (dpArr[i][j] == caseA) {
                choice[i][j] = { 1, nextMission, j };
            }
            else {
                choice[i][j] = { 2, i, nextMission };
            }
        }
    }
 
    printf("%d\n", dpArr[0][0]);
 
    //경로 구하기
    int row = 0;
    int col = 0;
    for (int i = 1; i <= W; i++) {
        int curRow = row;
        int curCol = col;
         
        printf("%d\n", choice[curRow][curCol].policeN);
 
        row = choice[curRow][curCol].nextRow;
        col = choice[curRow][curCol].nextCol;
    }
 
    return 0;
}
