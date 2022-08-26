#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int max = 0;
    string s;
    vector<string> chars;

    while(getline(cin, s)) {
        if (s.empty())
            break;
        chars.push_back(s);
        if(s.length() > max) max = s.length();
    }

    for(int i = 0; i < max; i++) {
        for(int j = chars.size() - 1; j >= 0; j--) {
            if(chars[j].size() > i) cout << chars[j][i];
            else cout << ' ';
        }
        cout << endl;
    }

    return 0;
}