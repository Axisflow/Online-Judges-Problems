/*
20XX年，pascal语言有多了一种新的整型 int128。它能够运算10000位的超大数据。

今天我们的任务就是：输入一个类型为　int128　的数字　ｎ　（-10^10001<=n<=10^10001）。

判断它是否为3的倍数。
*/

#include<stdio.h>

int main() {
    int i = 0;

    while(i != 10) {
        int sum = 0;
        char c;

        while(1) {
            c = getchar();
            if (c == '\n')
            {
                break;
            }
            sum += c - 48;
        } if((sum - 48) % 3 == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        i++;
    }
}