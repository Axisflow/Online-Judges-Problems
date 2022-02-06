#include<iostream>

using namespace std;

int IntDigitoBitsum(int num) {
    switch(num) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 1;
        case 3: return 2;
        case 4: return 1;
        case 5: return 2;
        case 6: return 2;
        case 7: return 3;
        case 8: return 1;
        case 9: return 2;
        default: return 0;
    }
}

int main() {
    int times, num, b1, b2;
    cin >> times;
    for(int t=0; t<times; t++){
        cin >> num;
        b1=0; b2=0;

        for(int i=1; i<=num; i<<=1){
            b1 += (i&num?1:0);
        }

        while(num) {
            b2 += IntDigitoBitsum(num%10);
            num /= 10;
        }

        cout << b1 << ' ' << b2 << '\n';
    }


    return 0;
}
