#include<iostream>

using namespace std;

int __gcd(int _x, int _y) {
    for(int tmp; tmp=_x%_y; _x=_y, _y=tmp);
    return _y;
}

int main() {
    int N, G;
    while(cin>>N && N>0) {
        G=0;
        for(int i=1; i<N; i++) {
            for(int j=i+1; j<=N; j++) {
                G += __gcd(i, j);
            }
        }
        cout << G << '\n';
    }
    return 0;
}
