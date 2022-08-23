/*
求一元二次方程式 ax2+bx+c=0 的根
*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, b, c, D, x, x1, x2;
    while (cin >> a >> b >> c) {
        D = pow(b, 2) - 4 * a * c;
        if (D > 0) {
            x1 = (-b + pow(D, 0.5)) / 2 * a;
            x2 = (-b - pow(D, 0.5)) / 2 * a;
            cout << "Two different roots x1=" << x1 << " , x2=" << x2 << endl;
        } else if (D == 0) {
            x = b / (-2 * a);
            cout << "Two same roots x=" << x << endl;
        } else {
            cout << "No real root" << endl;
        }
    }

    return 0;
}