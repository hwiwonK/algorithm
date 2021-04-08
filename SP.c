#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//문자열 자르기
int getWord(char* pattern, char words[][50], int i, int N) { //i는 현재 인덱스
	int j = 0;
	if (pattern[i + j] == '*') return -1; //case 4번인 경우
	while (pattern[i + j] != ' ' && pattern[i + j] != '\0') {
		words[N][j] = pattern[i + j];
		j++;
	}
	//if (pattern[i + j] == "\0") return 0; //단어 더 이상 없을 때

	return j; //단어 길이 return
}

int getWordText(int fd, char* buf, char wordsTxt[][50], int nbytes, int* startIdx) {

	//줄넘김이나 \0나오면 break
	int j = 0;
	int i = 0;
	int cnt = 0; //단어 개수
	int flag = 1;
	if (buf[j] == '\0' || buf[j] == '\n') flag = 0; j = 1;
	while (flag) {
		startIdx[cnt] = j; //이게여기있음안됨
		while (buf[j] != ' ' && buf[j] != '\0' && buf[j] != '\n') {
			wordsTxt[cnt][i++] = buf[j++];
		}
		if (buf[j] == '\0' || buf[j] == '\n') flag = 0;
		j++;
		cnt++;
	}
	//wordsTxt 변경

	//lseek 하기 - \n 다음이나, \0 다음 위치로
	int pos = (nbytes - j)*(-1);
	//printf("nbytes is %d\n", nbytes);
	//printf("move pos is %d\n", pos);
	pos = lseek(fd, pos, SEEK_CUR);
	//printf("pos is %d\n", pos);
	//j위치로! (만약 \0 이면 어차피 종료됨, \n이면 다음 turn으로)
	//current - (nbytes-j) 부터 다시 시작
	//단어 총 몇개인지 반환
	return cnt;
}

//len bytes 만큼 검사하기, \n만나면 line++ & index 0으로
int case1(int fd, char* pattern, char words[][50]) {
	char wordsTxt[50][50] = { 0, }; //여기에 txt파일의 단어 담기, 0번 인덱스에는 문자열 길이 담기
	char buf[200];
	int startIdx[50] = { 0, };
	//int len = 1, wordIdx = 0;
	int nbytes;
	int cnt = 0;
	int line = 0;

	//      char* Patternword[50] = words[0]; //이렇게 되나... 패턴 문자

			//word나누는 함수 구현

	while ((nbytes = read(fd, buf, sizeof(buf))) > 0) {
		line++;
		cnt = getWordText(fd, buf, wordsTxt, nbytes, startIdx); //한 줄
		printf("%d %d\n", line, cnt);
		//비교하기
		//compareWord(words[0], wordsTxt, cnt);
	}
}

int main(int argc, char* argv[]) {
	int fd;
	char pattern[100] = { 0, };
	char words[50][50] = { 0, };

	int size = read(0, pattern, 100);
	int caseN = -1;
	int wordCnt = 0;
	int j;

	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		exit(1);
	}

	if (pattern[0] == '\"') caseN = 3; //words배열 필요 없음

	else {
		for (int i = 0; i < size; i += (j + 1)) {
			j = getWord(pattern, words, i, wordCnt);
			wordCnt++;
			if (j == -1) { //case4이면 나머지 단어 받고 break;
				caseN = 4;
				getWord(pattern, words, i + 2, wordCnt);
				break;
			}
		}
	}

	if (wordCnt == 1) caseN = 1;
	if (wordCnt > 1 && caseN != 4) caseN = 2;

	printf("%d %d\n", caseN, wordCnt);


	switch (caseN) {
	case 1:
		case1(fd, pattern, words);

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	}

	//write(1,pattern,5)
	close(fd);

	return 0;
	//case1
	//한단어만 찾는다

	//case2

	//case3

	//case4

}
