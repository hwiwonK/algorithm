//https://ioinformatics.org/files/ioi2007solutions.pdf - 

// 좌표평면 상에서 N개의 점과 W개의 벽으로 표현된다.
// 0이라는 시각에 홍수가 시작되어 벽으로 사방이 둘러싸이지 않은 모든 외곽이 물로 뒤덮인다. 
// 그로부터 정확히 1시간 후에는 물과 육지의 양면 경계를 이루고 있던 벽이 수압을 견디지 못하고 모두 무너진다.
// 무너진 벽의 내부에 있던 다른 벽이 육지와 물의 경계가 된다.
// 이 과정이 되풀이됨으로써 결국 무너질 벽은 다 무너지고 모든 영역에 물이 차게 된다.
// N개의 점의 좌표와 이들 점을 연결하는 W개의 벽에 대한 정보를 입력 받아 
// 이 들 중 홍수 후에도 무너지지 않고 남아 있는 벽이 몇 개인지 찾는 프로그램을 작성하시오.

//첫째 줄에는 정수 N(2≤N≤100, 000)의 값이 들어있다.좌표평면에 있는 점의 개수이다.
//다음 N개의 줄에는 1부터 N째까지 각 점의 X Y 좌표가 하나씩 들어있다.범위는 0 이상 1, 000, 000 이하이다.
//점들의 위치는 모두 다르며 두 점이 같은 지점에 겹치는 경우는 없다.다음 줄에는 벽의 개수 W(1≤W≤2N)의 값이 들어있다.
//그리고 다음 W개의 줄에는 서로 다른 정수 A B(1≤A≤N, 1≤B≤N)

//================================================================================================================

// x좌표
// y좌표
// map을 이용
// 시작과 끝이 연결 됐는가 연결 됐다면 제거

#include <iostream>

using namespace std;

const int N_MAX = 25;



int main() {

	freopen("input.txt", "r", stdin);

	


	return 0;
}
