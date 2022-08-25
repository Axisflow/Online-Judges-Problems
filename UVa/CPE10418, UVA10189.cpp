#include<iostream>
#include<vector>

using namespace std;

int main() {
    int w, h, cases = 1;
    vector<vector<char>> map, tmp;
    vector<vector<vector<char>>> results;

    while(cin >> h >> w) {
        if(w == 0 && h == 0)
            break;
        else {
            map.clear();
            tmp.clear();

            map.resize(h);
            tmp.resize(h);
            for(int i = 0; i < h; i++) {
                map[i].resize(w);
                tmp[i].resize(w);
                for(int j = 0; j < w; j++) {
                    cin >> map[i][j];
                }
            }

            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(map[i][j] == '*') {
                        tmp[i][j] = '*';
                    } else {
                        int count = 0;
                        if(i > 0 && j > 0 && map[i-1][j-1] == '*')
                            count++;
                        if(i > 0 && map[i-1][j] == '*')
                            count++;
                        if(i > 0 && j < w-1 && map[i-1][j+1] == '*')
                            count++;
                        if(j > 0 && map[i][j-1] == '*')
                            count++;
                        if(j < w-1 && map[i][j+1] == '*')
                            count++;
                        if(i < h-1 && j > 0 && map[i+1][j-1] == '*')
                            count++;
                        if(i < h-1 && map[i+1][j] == '*')
                            count++;
                        if(i < h-1 && j < w-1 && map[i+1][j+1] == '*')
                            count++;
                        tmp[i][j] = '0' + count;
                    }
                }
            }
            results.push_back(tmp);
            cases++;
        }
    }

    for(int i = 1; i < cases; i++) {
        cout << "Field #" << i << ":" << endl;
        for(int h = 0; h < results[i - 1].size(); h++) {
            for(int w = 0; w < results[i - 1][h].size(); w++) {
                cout << results[i - 1][h][w];
            }
            cout << endl;
        }
        if(i != cases - 1) cout << endl;
    }

    return 0;
}