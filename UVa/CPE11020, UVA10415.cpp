#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map<char, const vector<bool>> notes = {
        {'c', {false, true, true, true, false, false, true, true, true, true}},
        {'d', {false, true, true, true, false, false, true, true, true, false}},
        {'e', {false, true, true, true, false, false, true, true, false, false}},
        {'f', {false, true, true, true, false, false, true, false, false, false}},
        {'g', {false, true, true, true, false, false, false, false, false, false}},
        {'a', {false, true, true, false, false, false, false, false, false, false}},
        {'b', {false, true, false, false, false, false, false, false, false, false}},
        {'C', {false, false, true, false, false, false, false, false, false, false}},
        {'D', {true, true, true, true, false, false, true, true, true, false}},
        {'E', {true, true, true, true, false, false, true, true, false, false}},
        {'F', {true, true, true, true, false, false, true, false, false, false}},
        {'G', {true, true, true, true, false, false, false, false, false, false}},
        {'A', {true, true, true, false, false, false, false, false, false, false}},
        {'B', {true, true, false, false, false, false, false, false, false, false}}
    };
    int need_presses[10], cases;
    bool now_presses[10];
    char ch;

    cin >> cases;
    cin.get();
    while(cases > 0) {
        for(int i = 0; i < 10; i++) {
            need_presses[i] = 0;
            now_presses[i] = false;
        }

        while((ch = cin.get()) != '\n' && ch != EOF) {
            for(int i = 0; i < 10; i++) {
                if(now_presses[i] && !notes[ch][i]) now_presses[i] = false;
                else if(!now_presses[i] && notes[ch][i]) {
                    now_presses[i] = true;
                    need_presses[i]++;
                }
            }
        }
        
        for(int i = 0; i < 10; i++) {
            cout << need_presses[i];
            if(i < 9) cout << ' ';
        }
        cout << endl;

        cases--;
    }

    return 0;
}