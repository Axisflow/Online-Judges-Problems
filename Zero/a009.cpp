/*
　　在密碼學裡面有一種很簡單的加密方式，就是把明碼的每個字元加上某一個整數K而得到密碼的字元（明碼及密碼字元一定都在ASCII碼中可列印的範圍內）。例如若K=2，那麼apple經過加密後就變成crrng了。解密則是反過來做。這個問題是給你一個密碼字串，請你依照上述的解密方式輸出明碼。

至於在本任務中K到底是多少，請自行參照Sample Input及Sample Output推出來吧！相當簡單的。
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        string c;

        for(int i = 0; i < str.length(); i++) {
            char c = str[i] - 7;
            cout << c;
        }

        cout << endl;
    }

    return 0;
}