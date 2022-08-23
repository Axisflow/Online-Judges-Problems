/*
對任意正整數n，平面上的n 個圓最多可將平面切成幾個區域？
*/

#include<iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) cout << (n*n - n + 2) << endl;

    return 0;
}