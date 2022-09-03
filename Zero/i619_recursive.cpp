#include<iostream>

using namespace std;
typedef unsigned long long int ll;

ll exp(ll &x, ll N, ll &mod) {
    if(N == 0) return 1;

    if(N & 1) return x * exp(x, N - 1, mod) % mod;
    else {
        ll result = exp(x, N / 2, mod);
        return result * result % mod;
    }
}

ll S(ll &x, ll N, ll &mod) {
    if(N == 1) return x % mod;

    if(N & 1) return (S(x, N - 1, mod) + exp(x, N, mod)) % mod;
    else return S(x, N / 2, mod) * (1 + exp(x, N / 2, mod)) % mod;
}

int main() {
    unsigned int t;
    ll x, y, p;

    cin >> t;
    while(t--) {
        cin >> x >> y >> p;
        cout << (1 + S(x, y, p)) % p << endl;
    }
    
    return 0;
}