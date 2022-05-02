#include <stdio.h>
#include "student.h"
/* 학생 정보를 읽어 텍스트 파일에 저장한다. */
int main(int argc, char* argv[])
{
	struct student record;
	FILE *fp;
	if (argc != 2) {
		fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
		return 1;
	}
	fp = fopen(argv[1], "w");
	printf("%-9s %-7s %-4s\n", "학번", "이름", "점수");
	while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3)
		fprintf(fp, "%d %s %d ", record.id, record.name, record.score);
	fclose(fp);
	return 0;
}
