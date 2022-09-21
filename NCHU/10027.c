#include<stdio.h>
#include<string.h>

int main() {
    char a[9];
    int i, t;

    scanf("%s", a);
    for (i = 0; i < 8 - strlen(a); i++) printf("----");
    for (i = 0; i < strlen(a); i++) {
        if (a[i] >= 'a' && a[i] <= 'f') t = a[i] - 'a' + 10;
        else t = a[i] - '0';

        if(t / 8) printf("*");
        else printf("-");
        t %= 8;

        if(t / 4) printf("*");
        else printf("-");
        t %= 4;

        if(t / 2) printf("*");
        else printf("-");
        t %= 2;

        if(t) printf("*");
        else printf("-");
    }

    return 0;
}