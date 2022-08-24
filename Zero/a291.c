/*
我們常用數字密碼鎖來保護重要的東西，但要是不小心忘了密碼麻煩就大了！
以四位數字的密碼鎖為例，我們最多要嘗試10^4=10000次才能解鎖。這時候要是
有辦法知道目前嘗試的密碼錯了幾個字，那解鎖的速度就快多了。請寫一個程式，
可以判斷每組數字跟正確答案差了幾個字。
*/

#include<stdio.h>

int main() {
    short pwd[4], test[4], p, q;
    int cases;

    while(scanf("%hd %hd %hd %hd %d", &pwd[0], &pwd[1], &pwd[2], &pwd[3], &cases) != EOF) {
        for(int ca = 0; ca < cases; ca++) {
            p = 0;
            q = 0;
            short pwdstat[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for(int i = 0; i < 4; i++) {
                pwdstat[pwd[i]]++;
            }
            
            for(int i = 0; i < 4; i++) {
                scanf("%hd", &test[i]);

                if(test[i] == pwd[i]) {
                    p++;
                    pwdstat[test[i]]--;
                }
            }

            for(int i = 0; i < 4; i++) {
                if(test[i] != pwd[i] && pwdstat[test[i]] > 0) {
                    q++;
                    pwdstat[test[i]]--;
                }
            }

            printf("%dA%dB\n", p, q);
        }
    }
    
    return 0;
}