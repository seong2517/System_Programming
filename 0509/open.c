#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char line[255];
    FILE *file = fopen(argv[1], "r");
    int linecount = 0;

    while(fgets(line, sizeof(line), file) != NULL) {
        linecount++;
        if(linecount == 2) {
            char *line2;
            char *ptr = strtok_r(line, " ", &line2);
            ptr = strtok_r(NULL, " ", &line2);
            printf("%s", line2);
            break;
        }
    }
    fclose(file);
    return 0;
}
