#include <stdio.h>

int main() {

    char s[200];
    scanf("%s", s);

    char* el = s;
    while(*el != '|') {
        printf("%c", *el);
        el++;
    }
    el++;
    while(*el != '|') {
        el++;
    }
    el++;
    while(*el) {
        printf("%c", *el);
        el++;   
    }

    fflush(stdout);
    return 0;
}
