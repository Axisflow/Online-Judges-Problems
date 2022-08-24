/*
Waterloo大學的新鮮人由於興趣不同，對於課程的選擇不盡相同，而校方希望他們所選的課程盡量一致，所以設立了一個獎項，頒發給 選擇的「課程組合」為「最受歡迎的課程組合」的學生。
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
    int n, max, cont;
    map<vector<short>, int> suits;
    vector<short> x;

    x.resize(5);
    while(cin >> n) {
        if(n == 0) break;

        suits.clear();
        max = 0;
        for(int i = 0; i < n; i++) {
            cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
            sort(x.begin(), x.end());

            if(suits.count(x)) suits[x]++;
            else suits[x] = 1;

            if(suits[x] > max) max = suits[x];
        }

        cont = 0;
        for(map<vector<short>, int>::iterator it = suits.begin(); it != suits.end(); it++) {
            if(it->second == max) cont += max;
        }

        cout << cont << endl;
    }
    
    return 0;
}