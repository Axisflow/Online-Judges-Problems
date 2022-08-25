#include<iostream>
#include<algorithm>

using namespace std;

int sum(int n, int lo , int &lor) {
    if(n + lo < 3) {
        lor = lo + n;
        return n;
    }
    else return n + sum((n + lo) / 3, (n + lo) % 3, lor);
}

int main() {
    int N, result, leftover, lor, solut[3];
    while(cin >> N) {
        for(int lo = 0; lo < 3; lo++) {
            result = sum(N, lo, lor);
            
            if(lor < lo) solut[lo] = 0;
            else solut[lo] = result;
        }
        
        sort(solut, solut + 3);
        cout << solut[2] << endl;
    }

    return 0;
}