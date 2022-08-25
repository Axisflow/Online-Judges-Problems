#include<iostream>
#include<vector>

using namespace std;

int main() {
    char c;
    bool now = true;
    vector<int> a, b;

    a.resize(26, 0);
    b.resize(26, 0);
    while((c = cin.get()) != EOF) {
        if(c == '\n') {
            if(now) {
                now = false;
            } else {
                for(int i = 0; i < 26; i++) {
                    for(int j = 0; j < min(a[i], b[i]); j++) cout << (char)('a' + i);
                }
                cout << endl;
                now = true;

                a.clear();
                a.resize(26, 0);
                b.clear();
                b.resize(26, 0);
            }
        } else {
            if(now) a[c - 'a']++; 
            else b[c - 'a']++;
        }
    }

    return 0;
}