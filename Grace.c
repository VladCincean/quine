#include <stdio.h>
#define SRC "#include <stdio.h>%1$c#define SRC %2$c%3$s%2$c%1$c#define KID %2$cGrace_kid.c%2$c%1$c#define FT(X) int main() { FILE *fd = fopen(KID, %2$cw%2$c); fprintf(fd, X, 0x0A, 0x22, X); fclose(fd); return 0; }%1$c/*%1$c    This program will print its own source when run.%1$c*/%1$cFT(SRC)%1$c"
#define KID "Grace_kid.c"
#define FT(X) int main() { FILE *fd = fopen(KID, "w"); fprintf(fd, X, 0x0A, 0x22, X); fclose(fd); return 0; }
/*
    This program will print its own source when run.
*/
FT(SRC)
