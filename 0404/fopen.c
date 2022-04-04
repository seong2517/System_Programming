#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd, i;
	if ((fd = open(argv[1], O_RDWR)) == -1)
		printf("파일 열기 오류\n");
	else printf("파일 %s 열기 성공 : %d\n", argv[1], fd);
	printf("\n\n인자의 개수 : %d\n", argc);
	for(i = 0; i < argc; i++)
		printf("%d 번째 인자 = %s\n", (i+1), argv[i]);
	close(fd);
	exit(0);
}
