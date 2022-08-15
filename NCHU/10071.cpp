#include<iostream>
#include<vector>

using namespace std;

int main() {
    int N, situation;
    vector<vector<char>> x, y;
    while(cin >> N) {
        x.clear(); y.clear();
        x.resize(N); y.resize(N);
        for(int i=0; i<N; i++) {
            x[i].resize(N);
            y[i].resize(N);
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> x[i][j];
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> y[i][j];
            }
        }

        situation = 7;
        /* 1. 90度 */
        {
            situation = 1;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(x[i][j] != y[j][N-i-1]) {
                        situation = 7;
                    }
                }
            }
        }

        /* 2. 180度 */
        if(situation == 7) {
            situation = 2;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(x[i][j] != y[N-i-1][N-j-1]) {
                        situation = 7;
                    }
                }
            }
        }

        /* 3. 270度 */
        if(situation == 7) {
            situation = 3;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(x[i][j] != y[N-j-1][i]) {
                        situation = 7;
                    }
                }
            }
        }

        /* 4. 垂直鏡像 */
        if(situation == 7) {
            situation = 4;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(x[i][j] != y[i][N-j-1]) {
                        situation = 7;
                    }
                }
            }
        }

        /* 5. 鏡像＋旋轉 */
        {
            if(situation == 7) {
                situation = 5;
                for(int i=0; i<N; i++) {
                    for(int j=0; j<N; j++) {
                        if(x[i][j] != y[N-j-1][N-i-1]) {
                            situation = 7;
                        }
                    }
                }
            }

            if(situation == 7) {
                situation = 5;
                for(int i=0; i<N; i++) {
                    for(int j=0; j<N; j++) {
                        if(x[i][j] != y[N-i-1][j]) {
                            situation = 7;
                        }
                    }
                }
            }

            if(situation == 7) {
                situation = 5;
                for(int i=0; i<N; i++) {
                    for(int j=0; j<N; j++) {
                        if(x[i][j] != y[j][i]) {
                            situation = 7;
                        }
                    }
                }
            }
        }

        /* 6. 0度 */
        if(situation == 7) {
            situation = 6;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(x[i][j] != y[i][j]) {
                        situation = 7;
                    }
                }
            }
        }

        cout << situation << endl;
    }
    return 0;
}