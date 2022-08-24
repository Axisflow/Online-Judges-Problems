/*
好餓歐歐歐歐

有 n 個食物在你面前排成一排

每個食物有它的飽足度

你想知道把其中一段通通吃掉會獲得多少飽足度
*/

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m, s, l, r;
    vector<int> partial_sum;
    while(cin >> n >> m) {
        partial_sum.clear();
        partial_sum.resize(n + 1);

        partial_sum[0] = 0;
        for(int i = 0; i < n; i++) {
            cin >> s;
            partial_sum[i + 1] = partial_sum[i] + s;
        }

        for(int i = 0; i < m; i++) {
            cin >> l >> r;
            cout << partial_sum[r] - partial_sum[l - 1] << endl;
        }
        
    }

    return 0;
}