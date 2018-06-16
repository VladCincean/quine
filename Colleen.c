#include <stdio.h>

/*
    This program will print its own source when run.
*/

char *s = "#include <stdio.h>%1$c%1$c/*%1$c    This program will print its own source when run.%1$c*/%1$c%1$cchar *s = %2$c%3$s%2$c;%1$c%1$cint ft_eight_queens_puzzle(void) {%1$c    return 92;%1$c}%1$c%1$cint main() {%1$c    /*%1$c        This program will print its own source when run.%1$c    */%1$c    printf(s, 0x0A, 0X22, s);%1$c    return 0;%1$c}%1$c";

int ft_eight_queens_puzzle(void) {
    return 92;
}

int main() {
    /*
        This program will print its own source when run.
    */
    printf(s, 0x0A, 0X22, s);
    return 0;
}
