#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m, i, j, temp = 0;

    scanf("%d", &n);
    int s1[n];
    for (i = n - 1; i >= 0; i--) scanf("%d", &s1[i]);

    scanf("%d", &m);
    int s2[m];
    for (i = m - 1; i >= 0; i--) scanf("%d", &s2[i]);

    int s3[n + m - 1];
    for (i = (n - 1) + (m - 1); i >= 0; i--) s3[i] = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            temp = s1[i] * s2[j];
            s3[i + j] += temp;
        }

    for (i = (n - 1) + (m - 1); i >= 0; i--) {
        printf("%d", s3[i]);
        if(i > 0) printf(" ");
    }

    return 0;
}