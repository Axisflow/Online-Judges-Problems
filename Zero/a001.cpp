/*
學習所有程式語言的第一個練習題 
請寫一個程式，可以讀入指定的字串，並且輸出指定的字串。

比如：輸入字串 "world", 則請輸出 "hello, world"
*/

#include <iostream>

using namespace std;

int main()
{
    string word;
    while(cin >> word)
        cout << "hello, " << word << endl;
    return 0;
}