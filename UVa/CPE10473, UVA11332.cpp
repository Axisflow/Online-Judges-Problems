#include<iostream>

using namespace std;

int g(int n) {
    if(n / 10 == 0) return n;
    else {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return g(sum);
    }
}

int f(string n) {
    int sum = 0;
    for(int i = 0; i < n.length(); i++) sum += n[i] - '0';

    return g(sum);
}

int main() {
    string n;
    while(cin >> n) {
        if(n == "0") break;

        cout << f(n) << endl;
    }

    return 0;
}