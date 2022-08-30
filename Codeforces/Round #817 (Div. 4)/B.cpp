#include<iostream>
#include<vector>

using namespace std;

int main() {
    int t, n;
    char tmp;
    vector<bool> c[2];
    bool print;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;

        c[0].clear(); c[0].resize(n, false);
        c[1].clear(); c[1].resize(n, false);

        for(int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 'R') c[0][j] = true;
        }
        for(int j = 0; j < n; j++) {
            cin >> tmp;
            if(tmp == 'R') c[1][j] = true;
        }

        print = true;
        for(int j = 0; j < n; j++) {
            if((!c[0][j] && c[1][j]) || (c[0][j] && !c[1][j])) {
                print = false;
            } 
        }

        if(print) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    return 0;
}