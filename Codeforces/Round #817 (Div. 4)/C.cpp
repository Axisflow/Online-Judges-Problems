#include<iostream>
#include<map>

using namespace std;

int main() {
    int t, n, score[3];
    string s;
    map<string, bool> players[3];

    cin >> t;
    for(int T = 0; T < t; T++) {
        players[0].clear();
        players[1].clear();
        players[2].clear();
        score[0] = 0;
        score[1] = 0;
        score[2] = 0;

        cin >> n;
        for(int N = 0; N < n; N++) {
            cin >> s;

            players[0][s] = true;
            if(!players[1].count(s)) players[1][s] = false;
            if(!players[2].count(s)) players[2][s] = false;
        }
        for(int N = 0; N < n; N++) {
            cin >> s;

            players[1][s] = true;
            if(!players[0].count(s)) players[0][s] = false;
            if(!players[2].count(s)) players[2][s] = false;
        }
        for(int N = 0; N < n; N++) {
            cin >> s;

            players[2][s] = true;
            if(!players[1].count(s)) players[1][s] = false;
            if(!players[0].count(s)) players[0][s] = false;
        }

        for(map<string, bool>:: iterator it1 = players[0].begin(), it2 = players[1].begin(), it3 = players[2].begin(); it1 != players[0].end(); it1++, it2++, it3++) {
            if(it1->second && !it2->second && !it3->second) {
                score[0] += 3;
            } else if(!it1->second && it2->second && !it3->second) {
                score[1] += 3;
            } else if(!it1->second && !it2->second && it3->second) {
                score[2] += 3;
            } else if(it1->second && it2->second && !it3->second) {
                score[0]++;
                score[1]++;
            } else if(it1->second && !it2->second && it3->second) {
                score[0]++;
                score[2]++;
            } else if(!it1->second && it2->second && it3->second) {
                score[1]++;
                score[2]++;
            }
        }

        cout << score[0] << ' ' << score[1] << ' ' << score[2] << endl;
    }

    return 0;
}