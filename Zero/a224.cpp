/*
一看題名，你就該知道，這次跟迴文脫不了關係！
若你不確定什麼是「迴文」，請看 Google 字典的解釋：

迴文 huíwén

一種修辭方式。
通過詞語反復迴環使用，表達二者互相依存或彼此制約的關係，
如“人人為我，我為人人”、“饒人不癡漢，癡漢不饒人”。
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> amount;
    bool notP, P;
    char c;
    while (c = cin.get()) {
        if(c == '\n' || c == EOF) {
            notP = false;
            P = true;
            for(unordered_map<char, int>::iterator it = amount.begin(); it != amount.end(); it++) {
                if(it->second%2 == 1) {
                    if(notP) {
                        P = false;
                        break;
                    } else notP = true;
                }
            }

            cout << (P ? "yes !" : "no...") << endl;

            if(c == EOF) break;

            amount.clear();
        } else if(c >= 'A' && c <= 'Z') {
            if(amount.count(c + 'a' - 'A')) amount[c + 'a' - 'A']++;
            else amount[c + 'a' - 'A'] = 1;
        } else if(c >= 'a' && c <= 'z') {
            if(amount.count(c)) amount[c]++;
            else amount[c] = 1;
        }
    }
    
    return 0;
}