#include<iostream>
#include<algorithm>

using namespace std;

unsigned int pow(int _down_x, unsigned int _up_y){
    if(_down_x==0) return 0;
    if(_up_y==0) return 1;

    int mutliply = _down_x;
    for(unsigned int i = 2; i <= _up_y; i++){
        mutliply *= _down_x;
    }

    return mutliply;
}

int main() {
    int num;
    string bits1, bits2;
    unsigned int tens1, tens2;
    cin>>num;
    for(int i=1; i<=num;i++){
        cin >> bits1 >> bits2;
        tens1 = tens2 = 0;

        for(int j=0;j<bits1.size();j++){
            tens1 += (bits1[j]-'0')*pow(2,bits1.size()-j-1);
        }
        for(int j=0;j<bits2.size();j++){
            tens2 += (bits2[j]-'0')*pow(2,bits2.size()-j-1);
        }

        cout << "Pair #"<< i << ": " << (__gcd(tens1, tens2)==1?"Love is not all you need!":"All you need is love!") << '\n';
    }

    return 0;
}
