#include <stdio.h>

int n;
int calMaxPointFromMap(int ans[n + 1][n + 1]);

int main(void) {
    int i, j, Max_point;
    scanf("%d", &n);

    int ans[n + 1][n + 1];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            ans[i][j] = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &ans[i][j]);
    
    Max_point = calMaxPointFromMap(ans);
    printf("%d", Max_point);

    return 0;
}

int calMaxPointFromMap(int ans[n + 1][n + 1]) {
    int i, j;
    int sum = 0, max = 0;
    
    for (i = 1; i < n; i++)
        for (j = 1; j < n; j++) {
            sum = ans[i][j] * 2 + ans[i][j - 1] + ans[i][j + 1] + ans[i - 1][j] + ans[i + 1][j];
            if (sum > max) {
                max = sum;
            }
            sum = 0;
        }
    
    return max;
}