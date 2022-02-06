#include<iostream>

using namespace std;

int main() {
    int num, case_num=0, minnum;

    start:
    while(cin >> num){
        case_num++;

        int que[num];
        for(int i=0; i<num; i++){
            cin >> que[i];
        }

        minnum = 0;
        for(int i=0; i<num; minnum=que[i], i++){
            if(que[i] <= minnum){
                cout<<"Case #"<<case_num<<": It is not a B2-Sequence."<<"\n\n";
                goto start;
            }
        }

        int sum[num*(num+1)/2];
        for(int i=0, cont=0; i<num; i++){
            for(int j=0; j<=i; j++, cont++){
                sum[cont] = que[i] + que[j];
                for(int k=0;k<cont;k++){
                    if(sum[k] == sum[cont]) {
                        cout<<"Case #"<<case_num<<": It is not a B2-Sequence."<<"\n\n";
                        goto start;
                    }
                }
            }
        }
        cout<<"Case #"<<case_num<<": It is a B2-Sequence."<<"\n\n";
    }

    return 0;
}
