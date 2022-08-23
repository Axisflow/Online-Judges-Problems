/*
你拿到一個整數，卻忍不住想把每個位數都乘在一起。例如看到 356 就會想要知道 3 * 5 * 6 的值為何。快寫個程式幫幫為了乘數字而快發瘋的自己吧！
*/

#include<stdio.h>

int main() {
	int T, num, result;

	scanf("%d", &T);
	for(int a = 0; a < T; a++) {
		scanf("%d", &num);

		if(num) {
			result = 1;
			while(num){
				result *= num % 10;
				num /= 10;
			}
		} else {
			result = 0;
		}

		printf("%d\n", result);
	}

	return 0;
}