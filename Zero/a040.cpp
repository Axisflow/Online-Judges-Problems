/*
所謂 Armstrong number 指的是一個 n 位數的整數，它的所有位數的 n 次方和恰好等於自己。

如；1634 = 1^4 + 6^4 + 3^4 + 4^4

請依題目需求在一定範圍內找出該範圍內的所有 armstrong numbers.
*/

#include<iostream>
#include<vector>

using namespace std;

int getExp(int x, int y, vector<vector<int>>& list) {
    if(x >= list.size()) list.resize(x + 1);
    if(y >= list[x].size()) {
        list[x].resize(y + 1, -1);
        list[x][0] = 1;
    }

    for(int i = 1; i <= y; i++)
        if(list[x][i] == -1) list[x][i] = list[x][i - 1] * x;

    return list[x][y];
}

int main() {
    int n, m, e, sum;
    bool not_flag;
    vector<vector<int>> explist;

    while(cin >> n >> m) {
        not_flag = false;
        for(int t = n; t <= m; t++) {
            e = 0;
            for(int i = t; i != 0; i /= 10) e++;

            sum = 0;
            for(int i = t; i != 0; i /= 10) sum += getExp(i % 10, e, explist);

            if(t == sum) {
                cout << t << ' ';
                not_flag = true;
            }
        }

        if(!not_flag) cout << "none";
        cout << endl;
    }
    
    return 0;
}