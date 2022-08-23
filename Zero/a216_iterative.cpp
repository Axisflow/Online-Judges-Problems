#include<iostream>

using namespace std;

long long f(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; sum += i, i++);

    return sum;
}

long long g(int n) {
    long long sum = 0;
    for(int i = 1; i <= n; sum += f(i), i++);

    return sum;
}

int main() {
    int n;
    while(cin >> n) cout << f(n) << ' ' << g(n) << endl;

    return 0;
}