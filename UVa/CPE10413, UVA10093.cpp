#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int toInt(char c){
    if(c>='0' && c<='9'){
        return c-'0';
    } else if(c>='A' && c<='Z'){
        return c-'A'+10;
    } else if(c>='a' && c<='z'){
        return c-'a'+36;
    } else{
        return 0;
    }
}

int main() {
    string num, temp;
    int root,tmp, mod_sum;
    bool found;
    while(cin>>num){
        root=1;
        mod_sum=0;
        for(int i=0;i<num.size();i++){
            tmp = toInt(num.substr(i, 1)[0]);
            mod_sum += tmp;

            if(tmp>root){
                root=tmp;
            }
        }
        root++;

        found=0;
        for(int r=root; r<=62; r++){
            if(mod_sum%(r-1) == 0){
                cout<<r<<'\n';
                found=1;
                break;
            }
        }
        cout << (found?"":"such number is impossible!\n");
    }

    return 0;
}
//Use Discrete--Modulus
