#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int f, l, tmp, sum;
    while(cin >> f >> l){
        if(f==0 && l==0){
            break;
        }
        else{
            sum = 0;
            for(int i=f; i<=l; i++){
                tmp = (int)sqrt(i);
                if(i == tmp*tmp) sum++;
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
