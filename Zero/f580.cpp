/*
給定 n 個骰子排成一列，一開始都是點數 1 朝上，點數 4 朝前，點數 2 朝右 (如下左圖所示)，另外骰子的展開圖如下右圖所示。



接下來有 m 次修改操作，每個操作包含兩個整數 , 

若 a, b 都是正整數，交換編號 a 與編號 b 的骰子的位置。
若 b 為 -1，將編號 a 的骰子向前旋轉。
若 b 為 -2，將編號 a 的骰子向右旋轉。
在 m 次操作結束之後，依序輸出編號 1 到編號 n 的骰子朝上的點數。
*/

#include<iostream>
#include<vector>

using namespace std;

typedef struct dice {
    char _0 = 0;
    char _1 = 1;
    char _2 = 2;
    char _3 = 3;
    char _4 = 4;
    char _5 = 5;
} Dice;

int main(void) {
    int n, m, a;
    char tmp;
    short b;
    vector<Dice> dice;
    Dice swaptmp;

    while(cin >> n >> m) {
        dice.clear();
        
        for(int i = 0; i < n; i++) dice.push_back(Dice());

        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            if(b == -2) {
                tmp = dice[a - 1]._4;
                dice[a - 1]._4 = dice[a - 1]._5;
                dice[a - 1]._5 = dice[a - 1]._1;
                dice[a - 1]._1 = dice[a - 1]._0;
                dice[a - 1]._0 = tmp;
            } else if(b == -1) {
                tmp = dice[a - 1]._0;
                dice[a - 1]._0 = dice[a - 1]._2;
                dice[a - 1]._2 = dice[a - 1]._5;
                dice[a - 1]._5 = dice[a - 1]._3;
                dice[a - 1]._3 = tmp;
            } else {
                swap(dice[a - 1], dice[b - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            cout << (1 + dice[i]._0);
            if(i < n - 1) cout << ' ';
        }
        cout << endl;
    }
    
    return 0;
}