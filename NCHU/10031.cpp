#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, d, ni, x, y, now_distance, max_distance;
    bool mode, record;
    vector<bool> ns;

    while(cin >> n >> d) {
        ns.clear(); ns.resize(n);
        for(int i=0; i<n; i++) {
            cin >> ni;
            ns[i] = (ni==1 ? true : false);
        }

        x = 0; y = 0;
        now_distance = 0;
        max_distance = 0;
        mode = true;
        record = false;
        for(int i=0; i<n; i++) {
            if(ns[i]) {
                x++;
                if(!mode) {
                    mode = true;
                }

                now_distance++;

                record = true;
            } else {
                y++;
                if(mode) {
                    mode = false;
                    if(now_distance > max_distance) max_distance = now_distance;
                }

                if(x-d <= y && y <= x+d && record) {
                    now_distance++;
                    if(now_distance > max_distance) max_distance = now_distance;
                } else {
                    x = 0;
                    y = 0;
                    record = false;
                    now_distance = 0;
                }
            }
        }

        cout << max_distance << endl;
    }
    return 0;
}