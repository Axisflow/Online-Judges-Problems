/*
John是一個赫赫有名的藝術品投資專家，每個月都會計算藝術品投資的盈虧，以審視其獲利。John每個月月底，即開始計算其每一件藝術品的獲利狀況。由於藝術品的種類繁多，John每個月總是要花費許多時間，計算其獲利狀況，以決定是否要將藝術品出脫。因此，他想麻煩你撰寫一支程式，計算每一件藝術品的盈虧狀況。
*/

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    float m, p, result;
    scanf("%d", &n);
    for(int t = 0; t < n; t++) {
        scanf("%d %d", &m, &p);
        result = (p - m) * 100 / m;

        if(-7.00 < result && result < 10.00) printf("%.2f%% keep\n", round((p - m) * 10000 / m) / 100);
        else printf("%.2f%% dispose\n", round((p - m) * 10000 / m) / 100);
    }
    return 0;
}