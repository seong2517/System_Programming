#include <stdio.h>
#define MAXLINE 80
/* 텍스트 파일에 줄 번호 붙여 프린트한다. */
int main(int argc, char *argv[])
{
	FILE *fp;
	int line = 0;
	char buffer[MAXLINE];
	if (argc != 2) {
		fprintf(stderr, "사용법:line 파일이름\n");
		return 1;
	}
	if ( (fp = fopen(argv[1],"r")) == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		return 2;
	}
	while (fgets(buffer, MAXLINE, fp) != NULL) { // 한 줄 읽기
		line++;
		printf("%3d %s", line, buffer); // 줄번호와 함께 프린트
	}
	return 0;
}
