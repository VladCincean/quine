#include <mach-o/dyld.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHILD_NAME_SRC "Sully_%d.c"
#define CHILD_NAME_BIN "Sully_%d"
#define CMD_COMPILE "gcc -Wall -Wextra -Werror %s -o %s"
#define CMD_EXECUTE "./%s"
#define SRC "#include <mach-o/dyld.h>%1$c#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c#define CHILD_NAME_SRC %2$c%4$s%2$c%1$c#define CHILD_NAME_BIN %2$c%5$s%2$c%1$c#define CMD_COMPILE %2$c%6$s%2$c%1$c#define CMD_EXECUTE %2$c%7$s%2$c%1$c#define SRC %2$c%3$s%2$c%1$c%1$cint main() {%1$c    int i = %8$d;%1$c    char executablePath[260];%1$c    uint32_t bufSize = 260;%1$c    char *myName;%1$c    char *childNameSrc;%1$c    char *childNameBin;%1$c    char *cmdCompile;%1$c    char *cmdExecute;%1$c    FILE *fd;%1$c%1$c    _NSGetExecutablePath(executablePath, &bufSize);%1$c    myName = strrchr(executablePath, '/');%1$c    myName++;%1$c%1$c    if (0 >= i) {%1$c        return 0;%1$c    }%1$c%1$c    if (NULL == strchr(myName, '_')) {%1$c        i++;%1$c    }%1$c%1$c    i--;%1$c    asprintf(&childNameSrc, CHILD_NAME_SRC, i);%1$c    asprintf(&childNameBin, CHILD_NAME_BIN, i);%1$c%1$c    fd = fopen(childNameSrc, %2$cw%2$c);%1$c    fprintf(fd, SRC, 0x0A, 0x22, SRC, CHILD_NAME_SRC, CHILD_NAME_BIN, CMD_COMPILE, CMD_EXECUTE, i);%1$c    fclose(fd);%1$c%1$c    asprintf(&cmdCompile, CMD_COMPILE, childNameSrc, childNameBin);%1$c    asprintf(&cmdExecute, CMD_EXECUTE, childNameBin);%1$c%1$c    system(cmdCompile);%1$c    system(cmdExecute);%1$c%1$c    free (childNameSrc); free(childNameBin); free(cmdCompile); free(cmdExecute);%1$c    return 0;%1$c}%1$c"

int main() {
    int i = 5;
    char executablePath[260];
    uint32_t bufSize = 260;
    char *myName;
    char *childNameSrc;
    char *childNameBin;
    char *cmdCompile;
    char *cmdExecute;
    FILE *fd;

    _NSGetExecutablePath(executablePath, &bufSize);
    myName = strrchr(executablePath, '/');
    myName++;

    if (0 >= i) {
        return 0;
    }

    if (NULL == strchr(myName, '_')) {
        i++;
    }

    i--;
    asprintf(&childNameSrc, CHILD_NAME_SRC, i);
    asprintf(&childNameBin, CHILD_NAME_BIN, i);

    fd = fopen(childNameSrc, "w");
    fprintf(fd, SRC, 0x0A, 0x22, SRC, CHILD_NAME_SRC, CHILD_NAME_BIN, CMD_COMPILE, CMD_EXECUTE, i);
    fclose(fd);

    asprintf(&cmdCompile, CMD_COMPILE, childNameSrc, childNameBin);
    asprintf(&cmdExecute, CMD_EXECUTE, childNameBin);

    system(cmdCompile);
    system(cmdExecute);

    free (childNameSrc); free(childNameBin); free(cmdCompile); free(cmdExecute);
    return 0;
}
