#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<vector<int>> expon;
int getExp(int base, int digit) {
    if(base == 0) return 0;
    else if(base == 1) return 1;

    if(digit == 0) return 1;
    else if(digit == 1) return base;
    
    if(base > expon.size()+1) expon.resize(base-1);
    int size = expon[base-2].size();
    if(digit > expon[base-2].size()+1) expon[base-2].resize(digit-1);
    for(int i=size; i<digit-1; i++) {
        expon[base-2][i] = getExp(base, i+1)*base;
    }
    return expon[base-2][digit-2];
}

int main() {
    int N, S, max_digit, tmp;
    vector<int> P, digits;
    bool printout;
    while(cin >> N >> S) {
        P.clear();

        for(int l=S+1, n=0, cont; n<N; l++) {
            cont = 0;
            for(int b=2; b<=10; b++) {
                tmp = l;
                for(int i=0; ; i++) {
                    if(getExp(b, i) > l) {
                        max_digit = i-1;
                        break;
                    }
                }

                digits.clear();
                for(int i=max_digit; i>=0; i--) {
                    digits.push_back(tmp/getExp(b, i));
                    tmp %= getExp(b, i);
                }

                printout = true;
                for(int i=max_digit; i>max_digit/2; i--) {
                    if(digits[i] != digits[max_digit-i]) {
                        printout = false;
                        break;
                    }
                }

                if(printout) cont++;
            }
            
            if(cont >= 2) {
                n++;
                P.push_back(l);
            }
        }

        for(vector<int>::iterator it = P.begin(); it != P.end(); it++) {
            cout << *it << endl;
        }
    }

    return 0;
}