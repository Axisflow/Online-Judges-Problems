/*
2^31是2的31次方的意思(2147483648)
10^100這個數字意味著1後面有100個0
魔法師小米企鵝因為練功的時候一邊唸咒語一邊打瞌睡
居然莫名其妙召喚了好多個這種可怕的數學題目…
幫幫睡著的小米企鵝好嗎？
*/

#include<stdio.h>

int main() {
	unsigned int base, times, result = 1;
	scanf("%d %d", &base, &times);

	while(times!=0) {
        if(times & 1) {
            result = result*base % 10007;
        }
        base = base*base % 10007;
        times >>= 1;
	}

	printf("%d", result);

	return 0;
}