/*
迴文的定義為正向，反向讀到的字串均相同

如：abba , abcba ... 等就是迴文

 請判斷一個字串是否是一個迴文？
*/

#include<iostream>

using namespace std;

int main() {
    int size;
    bool isP;
    string s;

    while(cin >> s) {
        size = s.length();
        isP = true;
        for(int i=0; i*2 < size; i++) {
            if(s[i] != s[size - i - 1]) isP = false;
        }

        cout << (isP?"yes":"no") << endl;
    }
    
    return 0;
}