#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    unsigned int n;
    vector<unsigned short> ns;

    while(cin >> n) {
        ns.resize(n);
        for(unsigned int i = 0; i < n; i++) cin >> ns[i];
        sort(ns.begin(), ns.end());
        
        if(n % 2) {
            cout << ns[(n - 1) / 2] << ' ' << upper_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) - lower_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) << ' ' << 1 << endl;
        } else {
            if(ns[(n - 1) / 2] == ns[n / 2]) {
                cout << ns[(n - 1) / 2] << ' ' << upper_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) - lower_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) << ' ' << 1 << endl;
            } else {
                cout << ns[(n - 1) / 2] << ' ' << upper_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) - lower_bound(ns.begin(), ns.end(), ns[(n - 1) / 2]) + upper_bound(ns.begin(), ns.end(), ns[n / 2]) - lower_bound(ns.begin(), ns.end(), ns[n / 2]) << ' ' << ns[n / 2] - ns[(n - 1) / 2] + 1 << endl;
            }
        }

    }

    return 0;
}