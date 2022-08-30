#include<iostream>

using namespace std;

int main() {
    int T, N;
    char tmp;
    int cont[256];

    cin >> T;
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < 256; i++) {
            cont[i] = 0;
        }

        cin >> N;
        if(N != 5) {
            cout << "NO" << endl;
            for(int i = 0; i < N; i++) cin >> tmp;
        }
        else {
            for(int i = 0; i < N; i++) {
                cin >> tmp;
                cont[tmp]++;
            }

            if(cont['T'] == 1 && cont['i'] == 1 && cont['m'] == 1 && cont['u'] == 1 && cont['r'] == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}