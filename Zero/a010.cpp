/*
各位在國小時都學過因數分解，都瞭解怎麼樣用紙筆計算出結果，現在由你來敎電腦做因數分解。

因數分解就是把一個數字，切分為數個質數的乘積，如 12=2^2 * 3

其中, 次方的符號以 ^ 來表示
*/

#include<iostream>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;

    bool prime = true;
    for(int i = 2; i*i <= n; i++) {
        if(!(n%i)) {
            prime = false;
            break;
        }
    }

    return prime;
}

int main() {
    int N, e;
    bool first;
    while(cin >> N) {
        first = true;
        for(int i=2; i<=N; i++) {
            e = 0;
            if(isPrime(i)) {
                for(;;) {
                    if(!(N%i)) {
                        N /= i;
                        e++;
                    } else break;
                }
            }

            if(e == 1) {
                cout << (first ? "" : " * ") << i;
                first = false;
            }
            else if(e > 1) {
                cout << (first ? "" : " * ") << i << '^' << e;
                first = false;
            }
        }

        cout << endl;
    }
    
    return 0;
}