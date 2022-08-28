#include<iostream>
#include<vector>

using namespace std;

int main() {
    short T, M, N, Q, r, c, w, target, next;
    vector<vector<char>> map;

    cin >> T;
    while(T--) {
        cin >> M >> N >> Q;
        cout << M << ' ' << N << ' ' << Q << endl;

        map.clear();
        map.resize(M, vector<char>(N));
        for(short m = 0; m < M; m++) for(short n = 0; n < N; n++) cin >> map[m][n];

        for(short q = 0; q < Q; q++) {
            cin >> r >> c;

            target = map[r][c];
            w = 0;
            next = true;
            for(; (0 < r - w) && (r + w < M - 1) && (0 < c - w) && (c + w < N - 1); ) {
                w++;

                for(int i = r - w; i <= r + w; i++) {
                    if(map[i][c - w] != target) {
                        next = false;
                        w--;
                        break;
                    }
                }
                if(next) for(int i = r - w; i <= r + w; i++) {
                    if(map[i][c + w] != target) {
                        next = false;
                        w--;
                        break;
                    }
                }
                if(next) for(int i = c - w; i <= c + w; i++) {
                    if(map[r - w][i] != target) {
                        next = false;
                        w--;
                        break;
                    }
                }
                if(next) for(int i = c - w; i <= c + w; i++) {
                    if(map[r + w][i] != target) {
                        next = false;
                        w--;
                        break;
                    }
                }

                if(!next) break;
            }

            cout << w*2 + 1 << endl;
        }
    }

    return 0;
}