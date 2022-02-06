#include<iostream>

using namespace std;

int main() {
    unsigned int num, digiSum, tmp;
    string nStr;
    while(cin >> num && num != 0) {
        digiSum = 0;
        nStr = "";
        for(unsigned int i=1, cont=0; i<=num; i<<=1, cont++){
            tmp = (i&num)>>cont;
            digiSum += tmp;
            nStr.insert(0, 1, '0'+tmp);
        }
        cout << "The parity of " << nStr << " is " << digiSum << " (mod 2)." << '\n';
    }

    return 0;
}
