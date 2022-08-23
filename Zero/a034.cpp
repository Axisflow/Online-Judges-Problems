/*
還記得計算機概論嗎？還記得二進位嗎？

現在我們來計算一下將一個10進位的數字換成二進位數字
*/

#include<iostream>

using namespace std;

int main() {
    int n, mask = 0x1;
    string result;
    while(cin >> n) {
        result = "";

        while(n != 0) {
            result = (char)((mask & n) + '0') + result;
            n >>= 1;
        }

        cout << result << endl;
    }

    return 0;
}