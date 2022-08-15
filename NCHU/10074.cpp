#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main() {
    int N, M, Pi, Ai, amount, money, buy;
    vector<pair<int, int>> Mi;
    while(cin >> N >> M) {
        for(int i=0; i<M; i++) {
            cin >> Pi >> Ai;
            Mi.push_back(pair<int, int>(Pi, Ai)); //pair(Pi, Ai) or make_pair(Pi, Ai) or {Pi, Ai}
        }

        sort(Mi.begin(), Mi.end());

        amount = 0;
        money = 0;
        for(int i=0; i<M && amount < N; i++) {
            if(amount + Mi[i].second > N) buy = N - amount; 
            else buy = Mi[i].second;

            amount += buy;
            money += Mi[i].first*buy;
        }

        cout << money << endl;
    }
    return 0;
}