/*
你的好朋友質數先生又來找你囉，給你兩個數字，請算出這兩個數字包含的範圍內有幾個質數。
*/

#include<iostream>
#include<vector>

using namespace std;

vector<bool> processedList = {true}, primeList = {false};

bool isPrime(int n) {
    if(processedList.size() < n) {
        processedList.resize(n, false);
        primeList.resize(n);
    }

    if(!processedList[n-1]) {
        processedList[n-1] = true;
        primeList[n-1] = true;
        for(int i = 2; i*i <= n; i++) {
            if(!(n%i)) {
                primeList[n-1] = false;
                break;
            }
        }
    }

    return primeList[n-1];
}

int main() {
    int a, b, amount;
    while(cin >> a >> b) {
        if(processedList.size() < b) {
            processedList.resize(b, false);
            primeList.resize(b);
        }

        amount = 0;
        for(int i = a; i <= b; i++) if(isPrime(i)) amount++;

        cout << amount << endl;
    }

    return 0;
}