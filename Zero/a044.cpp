/*
對任意正整數n，空間中的n 個平面最多可將空間切成幾個區域？
*/

#include<iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) cout << (n*(n*n + 5) / 6 + 1) << endl;

    return 0;
}