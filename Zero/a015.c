/*
已知一(m x n)矩陣A，我們常常需要用到另一個將A中之行與列調換的矩陣。這個動作叫做矩陣的翻轉。舉例來說，若

A =	[	3	1	2	]
8	5	4
則

AT =	[	3	8	]
1	5
2	4
 

現在 請您針對所讀取到的矩陣進行翻轉。
*/

#include<stdio.h>

int main() {
    int row, col;
    while(scanf("%d %d", &row, &col) != EOF) {
        int num[row][col];
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                scanf("%d", &num[i][j]);
            }
        }

        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                printf("%d ", num[j][i]);
            }

            printf("\n");
        }
    }

	return 0;
}