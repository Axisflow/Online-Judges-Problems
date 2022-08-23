/*
可惜，沒有下一題叫做「列排愛明明」，明明系列即將在這裡告一段落，謝謝大家這幾天來的支持！

明明喜歡把數字排成一列－－用他自己的方式！
他首先先看個位數，把個位數由小到大排。接著，如果個位數字一樣的話，他會將這些數字，由大至小排。
例如，如果數字有 38 106 98 26 13 46 51 的話，那麼 51 會排最前面，因為個位數字 1 是其中最小的一個。
而 106 26 46 這三個數字，個位數同樣都是 6，所以明明會直接將他們由大至小排，也就是 106 46 26。
所以，排好之後是：51 13 106 46 26 98 38，請你幫他輸出最終結果吧！
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

bool compare(pair<int, short> &front, pair<int, short> &back) {
    if(front.second < back.second) return true;
    else if(front.second > back.second) return false;
    else {
        if(front.first > back.first) return true;
        else return false;
    }
}

int main() {
    int n, num;
    vector<pair<int, short>> nums;
    while(cin >> n) {
        nums.clear();
        nums.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums[i] = pair<int, short>(num/10, num%10);
        }

        sort(nums.begin(), nums.end(), compare);

        for(int i = 0; i < n; i++) {
            if(nums[i].first != 0) cout << nums[i].first;
            cout << nums[i].second << ' ';
        }
        cout << endl;
    }
    
    return 0;
}