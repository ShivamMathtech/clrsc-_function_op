#include <stdio.h>

void clrscr() {
    printf("\033[2J\033[1;1H"); // ANSI escape code: clear + move to 1,1
}

int main() {
    clrscr();
    printf("Screen cleared!\n");
    return 0;
}
