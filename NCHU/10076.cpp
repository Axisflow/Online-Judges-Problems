#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool plusplus(int *num, int digit, int max) {
    (*num)++;
    for(int i = 0; i < digit; i++) {
        if(*(num+i) >= max) {
            if(i != digit - 1) {
                *(num+i) %= max;
                *(num+i) = 0;
                (*(num+i+1))++;
            } else
                return false;
        }
    }

    return true;
}

int main() {
    short poi[15], flag;
    int N, cont;
    vector<short> nums;
    map<short, short> amount;

    while(cin >> N) {
        amount.clear();
        nums.resize(N);
        for(int i = 0; i < N; i++) {
            cin >> nums[i];
            amount[nums[i]] = 0;
        }

        cont = 0;
        for(int i[5] = {0, 0, 0, 0, 0}; ;) {
            poi[0] = nums[i[0]];
            poi[1] = nums[i[1]];
            poi[2] = nums[i[2]];
            poi[3] = nums[i[3]];
            poi[4] = nums[i[4]];

            poi[5] = poi[0] * poi[2];
            poi[6] = poi[0] * poi[3] + poi[5] / 10;
            poi[5] %= 10;
            poi[7] = poi[0] * poi[4] + poi[6] / 10;
            poi[6] %= 10;

            poi[8] = poi[1] * poi[2];
            poi[9] = poi[1] * poi[3] + poi[8] / 10;
            poi[8] %= 10;
            poi[10] = poi[1] * poi[4] + poi[9] / 10;
            poi[9] %= 10;

            poi[11] = poi[5];
            poi[12] = poi[6] + poi[8];
            poi[13] = poi[7] + poi[9] + poi[12] / 10;
            poi[12] %= 10;
            poi[14] = poi[10] + poi[13] / 10;
            poi[13] %= 10;

            flag = 0x1;
            for(int i = 0; i < 15; i++) flag &= amount.count(poi[i]);
            if(flag) cont++;

            if(!plusplus(i, 5, N)) break;
        }

        cout << cont << endl;
    }


    return 0;
}