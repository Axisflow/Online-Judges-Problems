#include<iostream>

using namespace std;

int main() {
    int n;cin >> n;
    int from,to,sum;

    for(int i=1; i<=n; i++){
        sum=0;
        cin >>from>>to;

        for(int i=from + (from+1)%2; i<=to; i+=2){
            sum+=i;
        }

        cout << "Case "<< i <<": " << sum << endl;
    }

    return 0;
}
