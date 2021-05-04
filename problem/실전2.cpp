//https://linksharing.samsungcloud.com/vKgOsdEV3JSN


#include <iostream>
#include <time.h>

using namespace std;

const int N_MAX = 1000000;

const int MOD_NUM = 100000007;

//가로 길이 인덱스 일 때 (빈칸 없이 채우는 경우의 수)
long long dpArrFull[N_MAX + 1][2] = { 0, };

int main() {

	clock_t start, end;
	double result;

	start = clock();
	//freopen("input.txt", "r", stdin);


	dpArrFull[0][0] = 1;
	dpArrFull[2][0] = 3;

	int limit = N_MAX >> 1;

	for (int i = 4; i <= limit; i+=2)
	{
		dpArrFull[i][1] = (dpArrFull[i - 2][1] + (dpArrFull[i - 4][0] * 2) % MOD_NUM) % MOD_NUM;
		dpArrFull[i][0] = ((dpArrFull[i - 2][0] * 3) % MOD_NUM + dpArrFull[i][1]) % MOD_NUM; // 2개짜리 x 나머지


	}

	end = clock();
	





	printf("%d", (double)(end - start));

	return 0;
}
