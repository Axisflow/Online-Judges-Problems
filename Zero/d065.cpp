/*
文文和兩個同學最近喜歡在 ZeroJudge 上解題。有一天他們看到了孔子說的：「三人行必有我師焉。」就吵了起來，因為他們每個人都認為自己是三個人之中的「老師」。後來他們決定要比比看誰在 ZeroJudge 上的 AC 題數最多。
*/

#include <iostream>

using namespace std;

int main() {
    int a, b, c, maxi;
    while (cin >> a >> b >> c) {
        if (a > b) {
            if (a > c) {
                maxi = a;
            } else {
                maxi = c;
            }
        } else {
            if (b > c) {
                maxi = b;
            } else {
                maxi = c;
            }
        }

        cout << maxi << endl;
    }

    return 0;
}