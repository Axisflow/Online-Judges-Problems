/*
排列數字一定很容易嗎

現在給你一堆數字

請你幫我排序 
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(string &f, string &l) {
    bool negf = (f[0] == '-')?true:false, negl = (l[0] == '-')?true:false;
    bool bigf = false;

    if(f.length() - (negf?1:0) > l.length() - (negl?1:0)) {
        bigf = true;
    } else if(f.length() - (negf?1:0) < l.length() - (negl?1:0)) {
        bigf = false;
    } else {
        for(int i = 0; i < f.length() - (negf?1:0); i++) {
            if(f[i + (negf?1:0)] > l[i + (negl?1:0)]) {
                bigf = true;
                break;
            } else if(f[i + (negf?1:0)] < l[i + (negl?1:0)]) {
                bigf = false;
                break;
            }
        }
    }

    if(bigf) {
        if(negf) return true;
        else return false;
    } else {
        if(negl) return false;
        else return true;
    }
}

int main() {
    int N;
    vector<string> nums;

    while(cin >> N) {
        nums.clear();
        nums.resize(N);
        for(int i = 0; i < N; i++) cin >> nums[i];

        sort(nums.begin(), nums.end(), cmp);

        for(int i = 0; i < N; i++) cout << nums[i] << endl;
    }

    return 0;
}