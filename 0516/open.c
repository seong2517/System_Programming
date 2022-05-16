#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int read_specific(char* path, int linepos, char*str, char* cpy){
        FILE *fp;
        fp = fopen(path, "r");
        if (fp == 0) {printf("파일 열기 오류\n"); return -1;}

        char buf[1025];
        for(int i=0; i<linepos; i++)
                if (fgets(buf, 1024, fp) == 0) { printf("ERR"); fclose(fp); return -1;}
        char* find_pos=strstr(buf, str);
        if (find_pos == 0) printf("파일 없음\n");
        else strcpy (cpy, find_pos + strlen(str));
        fclose(fp);

        if (find_pos == 0) return -1;
        return 0;
}
void main(int argc, char*argv[]) {
        if (argc<4){printf("usage : file line chr\n"); exit(1);}
        char buf[1025];

        int result=read_specific(argv[1], atoi(argv[2]), argv[3], (char*)&buf);

        if (result == -1) printf("error\n");
        else printf("%s\n", buf);
}

void read_specific_str(char* path, int linepos, char* str) {
        FILE *fp;
        fp=fopen(path, "r");

        char buf[1025];
        for (int i = 0; i<linepos; i++)
                if(fgets(buf, 1024, fp) == 0) return;
        if (strlen(buf)<strlen(str)) return;
        printf("%s", buf+strlen(str));
        fclose(fp);
}
