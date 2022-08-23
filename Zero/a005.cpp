/*
　　Eva的家庭作業裏有很多數列填空練習。填空練習的要求是：已知數列的前四項，填出第五項。因 為已經知道這些數列只可能是等差或等比數列，她決定寫一個程式來完成這些練習。
*/

#include <iostream>

using namespace std;

int main() {
    int t;
    int a, b, c, d, e;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;

        if(b - a == d - c)
            e = d + (b - a);
        else
            e = d * (b / a);

        cout << a << " " << b << " " << c << " " << d << " " << e << " " << endl;
    }

    return 0;
}