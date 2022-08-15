#include<iostream>
#include<map>

using namespace std;

int main() {
    int n;
    string name;
    map<string, int> p;
    map<int, string> order;

    cin >> n;
    for(int i= 0; i<n; i++) {
        cin >> name;
        p[name] = 0;
        order[i] = name;
    }

    int m, pn, distribute;
    for(int i= 0; i<n; i++) {
        cin >> name >> m >> pn;

        if(pn == 0) {
            continue;
        } else {
            p[name] += m%pn - m;
            distribute = m/pn;
        }

        for(int j = 0; j<pn; j++) {
            cin >> name;
            p[name] += distribute;
        }
    }

    for(int i=0; i<n; i++) {
        cout << order[i] << " " << p[order[i]] << endl;
    }

    return 0;
}