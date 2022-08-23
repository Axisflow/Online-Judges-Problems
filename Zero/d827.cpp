/*
鉛筆一支 5 元，一打 50 元。小明需要幫班上每位同學買一枝鉛筆，請問要多少錢？由於小明很注重環保，他絕不會為了省錢而多買任何不需要的東西。也就是說，小明買的鉛筆數量一定等於班上的人數。
*/

#include <iostream>

using namespace std;

int main() {
    int i, da, leave;

    while (cin >> i) {
        da = i / 12;
        leave = i % 12;

        cout << da * 50 + leave * 5 << endl;
    }

    return 0;
}