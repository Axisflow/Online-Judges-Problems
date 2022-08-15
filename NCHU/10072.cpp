#include<iostream>
#include<vector>

using namespace std;

int main() {
    int B, tmp;
    bool record, print;
    vector<int> base, digits, digits_s;
    while(cin >> B) {
        base.clear();
        for(int i=1; 90000>i; i*=B){
            base.push_back(i);
        }

        for(int num=1, n; num<=300; num++) {
            digits.clear();
            record = false;
            n = num;
            for(int i = base.size() - 1; i >= 0; i--) {
                if((tmp=n/base[i]) != 0 || record) {
                    record = true;
                    if(tmp >= 10) tmp = tmp - 10 + 'A';
                    digits.push_back(tmp);
                    n%=base[i];
                }
            }

            digits_s.clear();
            record = false;
            n = num*num;
            for(int i = base.size() - 1; i >= 0; i--) {
                if((tmp=n/base[i]) != 0 || record) {
                    record = true;
                    if(tmp >= 10) tmp = tmp - 10 + 'A';
                    digits_s.push_back(tmp);
                    n%=base[i];
                }
            }

            print = true;
            for(int i = 0; i < digits_s.size()/2; i++) {
                if(digits_s[i] != digits_s[digits_s.size()-i-1]) {
                    print = false;
                    break;
                }
            }

            if(print) {
                for(int i=0; i<digits.size(); i++) {
                        if(digits[i] < 10) cout << digits[i];
                        else cout << (char)digits[i];
                }
                cout << ' ';
                for(int i=0; i<digits_s.size(); i++) {
                        if(digits_s[i] < 10) cout << digits_s[i];
                        else cout << (char)digits_s[i];
                }
                cout << endl;
            }
        }
    }

    return 0;
}