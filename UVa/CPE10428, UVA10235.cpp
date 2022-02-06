#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool prime(unsigned int _num) {
    for(int i=2; i*i<=_num; i++){
        if(!(_num%i)) return false;
    }
    return true;
}

int main() {
    string num;
    int rnum, vnum;
    while(cin >> num) {
        rnum = stoi(num);
        if(!prime(rnum)) {
            cout << rnum << " is not prime.\n";
        } else {
            reverse(num.begin(), num.end());
            vnum = stoi(num);
            if(prime(vnum) && rnum!=vnum) {
                cout << rnum << " is emirp.\n";
            } else {
                cout << rnum << " is prime.\n";
            }
        }
    }

    return 0;
}
