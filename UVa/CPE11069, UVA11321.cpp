#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Comparer {
    int remain;
    bool odd;
    int n;
} comparer;

bool cmp(comparer &f, comparer &l) {
    if(f.remain == l.remain) {
        if(f.odd && l.odd) return f.n > l.n;
        else if(!f.odd && !l.odd) return f.n < l.n;
        else return f.odd;
    }
    
    return f.remain < l.remain;
}

int main() {
    int N, M, tmp;
    vector<comparer> nums;
    
    while(cin >> N >> M) {
        if(N == 0 && M == 0) break;
        nums.resize(N);

        cout << N << ' ' << M << endl;

        for(int n = 0; n < N; n++){
            cin >> tmp;
            nums[n].n = tmp;
            nums[n].odd = tmp & 1;
            nums[n].remain = tmp % M;
        }

        sort(nums.begin(), nums.begin() + N, cmp);
        for(int n = 0; n < N; n++) cout << nums[n].n << endl;
    }
    cout << "0 0" << endl;

    return 0;
}