#include<iostream>

using namespace std;

int main() {
    int n, num, symmetric, tmp;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin.get();cin.get();cin.get();cin.get();
        cin >> num;
        symmetric = 1;
        tmp = num*num/2;

        long long int metric[num][num];

        for(int j1=0; j1<num; j1++){
            for(int j2=0; j2<num; j2++){
                cin >> metric[j1][j2];
                if(symmetric){
                    if(metric[j1][j2]<0) symmetric=0;
                    if(j1*num+j2+1>tmp){
                        if(metric[num-j1-1][num-j2-1] != metric[j1][j2]) symmetric=0;
                    }
                }
            }
        }

        cout<<"Test #"<<i<<": "<<(symmetric?"Symmetric.":"Non-symmetric.")<<'\n';
    }
    return 0;
}
