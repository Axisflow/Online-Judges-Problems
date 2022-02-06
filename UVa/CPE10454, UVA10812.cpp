#include<iostream>

using namespace std;

int main(){
    int num, sum, diff;
    unsigned int tmp;
    cin >> num;

    for(int i=0; i<num; i++) {
        cin >> sum >> diff;

        tmp = sum+diff;
        if(diff > sum || tmp%2 == 1){
            cout << "impossible\n";
        }
        else{
            cout << tmp/2 << " " << (sum-diff)/2 << '\n';
        }
    }

    return 0;
}
