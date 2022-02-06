#include<iostream>

using namespace std;

void nines(int num, int *cnt) {
    if(num==9) {
        (*cnt)++;
        return;
    }

    if(num%9 == 0) {
        int sum=0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        (*cnt)++;
        nines(sum, cnt);
    } else {
        return;
    }
}

int main() {
    int sum, cont,tmp;
    string num;

    while(cin >> num) {
        if(num == "0") {
            break;
        } else {
            sum=0;
            cont=0;
            for(int i=0; i<num.size(); i++){
                tmp = num[i]-'0';
                sum += tmp;
                cout << tmp;
            }

            if(sum%9 == 0) {
                nines(sum, &cont);
            }

            if(cont) cout << " is a multiple of 9 and has 9-degree " << cont << ".\n";
            else cout << " is not a multiple of 9.\n";
        }
    }

    return 0;
}
