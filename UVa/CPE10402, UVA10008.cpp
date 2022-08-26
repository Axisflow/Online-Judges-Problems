#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<char, int> &x, pair<char, int> &y) {
    if(x.second < y.second) return false;
    else if(x.second > y.second) return true;
    else {
        if(x.first > y.first) return false;
        else return true;
    }
}

int main() {
    int lines;
    char c;
    vector<pair<char, int>> amount;
    
    while(cin >> lines) {
        amount.clear();
        for(int i = 0; i < 26; i++) amount.push_back(pair<char, int>('A' + i, 0));

        cin.get();
        for(int i = 0; i < lines; i++) {
            while((c = cin.get()) != '\n') {
                if('a' <= c && c <= 'z') {
                    amount[c - 'a'].second++;
                } else if('A' <= c && c <= 'Z') {
                    amount[c - 'A'].second++;
                }
            }
        }
        sort(amount.begin(), amount.end(), cmp);

        for(int i = 0; i < 26; i++) {
            if(amount[i].second != 0) cout << amount[i].first << ' ' << amount[i].second << endl;
            else break;
        }
    }
    
    
    return 0;
}