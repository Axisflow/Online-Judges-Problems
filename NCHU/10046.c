#include<stdio.h>

int main(void) {
    short flag = 0, record[10] = {0};
    int n;

    scanf("%d", &n);
    while(n) {
        record[n % 10]++;
        n /= 10;
    }

    for(int i = 0; i < 10; i++) {
        if(record[i] > 1) {
            flag = 1;
            break;
        }
    }

    printf("%s\n", (flag ? "Repeated digits" : "No repeated digits"));

    return 0;
}