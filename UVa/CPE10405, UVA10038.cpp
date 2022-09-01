#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n, tmp, now;
    bool isJolly;
    vector<int> diffs;
    while(cin >> n) {
        diffs.resize(n - 1);

        cin >> tmp;
        for(int i = 0; i < n - 1; i++) {
            cin >> now;
            diffs[i] = now - tmp < 0 ? tmp - now : now - tmp;
            tmp = now;
        }
        sort(diffs.begin(), diffs.end());

        isJolly = true;
        for(int i = 1; i < n; i++) {
            if(diffs[i - 1] != i) {
                isJolly = false;
                break;
            }
        }

        cout << (isJolly ? "Jolly" : "Not jolly") << endl;
    }

    return 0;
}