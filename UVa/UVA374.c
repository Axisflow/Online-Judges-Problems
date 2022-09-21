#include<stdio.h>

typedef unsigned long long int ll;

ll mod(ll *B, ll P, ll *M) {
    if(P == 0) return 1 % *M;
    if(P == 1) return *B % *M;

    if(P & 1) return *B * mod(B, P - 1, M) % *M;
    else {
        ll tmp = mod(B, P / 2, M);
        return tmp * tmp % *M;
    }
}

int main(void) {
    ll B, P, M;

    while(scanf("%llu %llu %llu", &B, &P, &M) != EOF) {
        B %= M;
        printf("%llu\n", mod(&B, P, &M));
    }

    return 0;
}