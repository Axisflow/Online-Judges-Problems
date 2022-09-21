#include <stdio.h>

int main(void) {
    int M, Y, C, n;

    scanf("%d %d %d\n", &M, &Y, &C);
    scanf("%d\n", &n);
    char s[n];
    for(int i = 1; i <= n; i++) {
        scanf("%c", &s[i]);

        if (s[i] == 'M') {
            M -= 1;
        } else if (s[i] == 'Y') {
            Y -= 1;
        } else if (s[i] == 'C') {
            C -= 1;
        } else if (s[i] == 'R') {
            M -= 1;
            Y -= 1;
        } else if (s[i] == 'V') {
            M -= 1;
            C -= 1;
        } else if (s[i] == 'G') {
            Y -= 1;
            C -= 1;
        } else if (s[i] == 'B') {
            M -= 1;
            Y -= 1;
            C -= 1;
        }
    }

    if (M >= 0 && Y >= 0 && C >= 0)  printf("YES %d %d %d", M, Y, C); 
    else printf("NO");
    
    return 0;
}