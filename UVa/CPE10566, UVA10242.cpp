#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

bool cmp(pair<double, double> x, pair<double, double> y) {
    if((x.first == y.first) && (x.second == y.second)) return true;
    else return false;
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    pair<double, double> record[4], tmp;
    bool breakflag;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        record[0] = pair<double, double>(x1, y1);
        record[1] = pair<double, double>(x2, y2);
        record[2] = pair<double, double>(x3, y3);
        record[3] = pair<double, double>(x4, y4);

        breakflag = false;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(i == j) continue;
                else {
                    if(record[i].first == record[j].first && record[i].second == record[j].second) {
                        tmp = record[0];
                        record[0] = record[i];
                        record[i] = tmp;
                        tmp = record[1];
                        record[1] = record[j];
                        record[j] = tmp;
                        breakflag = true;
                        break;
                    }
                }
            }

            if(breakflag) break;
        }

        cout << fixed << setprecision(3)
             << record[2].first - record[0].first + record[3].first << ' '
             << record[2].second - record[0].second + record[3].second << endl;
    }

    return 0;
}