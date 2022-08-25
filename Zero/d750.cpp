/*
給你兩個整數 N (0<N<=10000), M (0<M<=10000)，你要依照某些規則排序N個整數。先利用每個數字除以M的餘數由小到大排，若排序中比較的兩數為一奇一偶且兩數除以M 的餘數相等，則奇數要排在偶數前面。若兩奇數除以M餘數大小相等，則原本數值較大的奇數排在前面。同樣的，若兩偶數除以M餘數大小相等，則較小的偶數排在前面。至於負數的餘數計算和 C 語言裡的定義相同，即負數的餘數絕對不會大於零。例如 -100 MOD 3 = -1, -100 MOD 4 = 0 依此類推。
*/

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