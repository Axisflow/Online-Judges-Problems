/*
給你N個正整數, 試求哪幾個之和剛好為M, 印出所有合條件的解, 如有多組解, 請按由小到大的順序印出(格式可參考樣例輸出)
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

void dfs(multiset<vector<int>> &result ,vector<int> &nums, int &target, int loc, vector<int> &tmp, int &sum) {
    if(loc == nums.size()) return;

    int nowsum = sum + nums[loc];
    if(nowsum < target) {
        vector<int> nowtmp = tmp;
        nowtmp.push_back(nums[loc]);
        dfs(result, nums, target, loc + 1, nowtmp, nowsum);
        
        dfs(result, nums, target, loc + 1, tmp, sum);
    } else if(nowsum > target) {
        dfs(result, nums, target, loc + 1, tmp, sum);
    } else {
        vector<int> nowtmp = tmp;
        nowtmp.push_back(nums[loc]);
        result.insert(nowtmp);

        dfs(result, nums, target, loc + 1, tmp, sum);
    }

    return;
}

int main() {
    int N, M, sum;
    bool space;
    vector<int> nums, tmp;
    multiset<vector<int>, less<vector<int>>> result;
    
     while(cin >> N >> M) {
        nums.clear();
        nums.resize(N);
        for(int i=0; i<N; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());

        result.clear();
        tmp.clear();
        sum = 0;
        dfs(result, nums, M, 0, tmp, sum);

        if(result.size() == 0) cout << -1 << endl;
        for(multiset<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
            space = false;

            for(int i = 0; i < it->size(); i++) {
                if(space) cout << ' ';
                cout << (*it)[i];
                space = true;
            }
            cout << endl;
        }
    }
    return 0;
}