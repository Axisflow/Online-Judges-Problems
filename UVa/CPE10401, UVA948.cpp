#include<iostream>
#include<vector>

using namespace std;

vector<int> Fibonacce={1,2};
int extInd=1; //'private' just let you know they shouldn't be used in main()
int getFib(int ind) {
    if(ind>extInd){
        for(int i=extInd+1; i<=ind; i++, extInd++) {
            Fibonacce.push_back(Fibonacce[i-1] + Fibonacce[i-2]);
        }
    }

    return Fibonacce[ind];
}

int main() {
    int times, num, digit, tmp;

    cin >> times;
    for(int i=0; i<times; i++) {
        cin >> num;

        digit = 0;
        for(; getFib(digit)<=num; digit++);

        cout << num << " = ";
        do{
            digit--;
            if((tmp=num-getFib(digit)) >= 0) {
                cout << 1;
                num = tmp;
            } else {
                cout << 0;
            }
        } while(digit > 0);
        cout << " (fib)\n";
    }

    return 0;
}
