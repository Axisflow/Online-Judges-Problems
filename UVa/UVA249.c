#include<stdio.h>

int main(void) {
    int cases, min, max, maxNum, maxDivisors, divisors;

    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d", &min, &max);
        maxDivisors = 0;

        for(int m = min; m <= max; m++) {
            divisors = 0;
            for(int f = 1; f*f <= m; f++) {
                if(m % f == 0) {
                    if(m/f == f) divisors++;
                    else divisors += 2;
                }
            }

            if(divisors > maxDivisors) {
                maxDivisors = divisors;
                maxNum = m;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", min, max, maxNum, maxDivisors);
    }

    return 0;
}