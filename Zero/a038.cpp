/*
輸入任意數字，並將其數字全部倒轉
*/

#include<iostream>

using namespace std;

int main() {
    string num;
    int size;
    char tmp;
    bool head;
    while(cin >> num) {
        size = num.length();
        for(int i=0; i*2 < size; i++) {
            tmp = num[i];
            num[i] = num[size - i - 1];
            num[size - i - 1] = tmp;
        }

        head = true;
        for(int i=0; i<size; i++) {
            if(head) {
                if(num[i] != '0') {
                    cout << num[i];
                    head = false;
                }
            } else {
                cout << num[i];
            }
        }
        if(head) cout << '0';
        cout << endl;
    }

    return 0;
}