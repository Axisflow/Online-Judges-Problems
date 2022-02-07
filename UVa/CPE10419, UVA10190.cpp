#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m, tmp;
    vector<int> nums;
    while(cin >> n >> m){
        nums.clear();
        for(int i=0; ;i++){
            if(n==0 || m==0 || m==1 || n%m){
                cout << "Boring!";
                break;
            }
            else {
                nums.push_back(n);
                if((tmp = n/m) == 1){
                    for(int j=0; j<=i; j++){
                        cout << nums[j] << ' ';
                    }
                    cout << 1;
                    break;
                }
                n=tmp;
            }
        }
        cout << '\n';
    }
    return 0;
}
