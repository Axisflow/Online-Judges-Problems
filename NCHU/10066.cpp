#include<iostream>

using namespace std;

int main()
{
    string s1, s2;
    int i1, i2;
    while(cin >> s1 >> s2) {
        i1 = 1;
        i2 = 1;
        
        for(int i = 0; i < s1.length(); i++) {
            i1 = (s1[i] - 'A' + 1) * i1 % 47;
        }
        for(int i = 0; i < s2.length(); i++) {
            i2 = (s2[i] - 'A' + 1) * i2 % 47;
        }

        if(i1 == i2) {
            cout << "GO" << endl;
        } else {
            cout << "STAY" << endl;
        }
    }
    return 0;
}