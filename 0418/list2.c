#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

/* 디렉터리 내용을 자세히 리스트한다. */
int main(int argc, char **argv)
{
	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[BUFSIZ+1];
	if (argc == 1)
		dir = ".";
	else dir = argv[1];
	if ((dp = opendir(dir)) == NULL) // 디렉터리 열기
		perror(dir);
	while ((d = readdir(dp)) != NULL) { // 디렉터리의 각 파일에 대해
		sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
		if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
			perror(path);
		printStat(path, d->d_name, &st); // 상태 정보 출력
		putchar('\n');
	}
	closedir(dp);
	exit(0);
}
/* 파일 상태 정보를 출력 */
