#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct student record;
	if (argc < 2) {
		fprintf(stderr, "사용법 : %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("수정할 학생의 학번 입력: ");
		if (scanf("%d", &id) == 1) {
			lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
			if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
				printf("학번:%8d\t 이름:%4s\t 점수:%4d\n", record.id, record.name, record.score);
				printf("새로운 점수: ");
				scanf("%d", &record.score);
				lseek(fd, (long) -sizeof(record), SEEK_CUR);
				write(fd, (char *) &record, sizeof(record));
			}
			else printf("레코드 %d 없음\n", id);
		}
		else printf("입력오류\n");
		printf("계속하겠습니까?(Y/N)");
		scanf(" %c",&c);
	}
	while (c == 'Y');
	close(fd);
	exit(0);
}
