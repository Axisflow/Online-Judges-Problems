#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

int main() {
    int x, tmp;
    long long int exp, sum;
    string s;
    vector<int> an;

    stringstream ss;

    while(cin >> x) {
        cin.get();
        getline(cin, s);
        an.clear();
        ss.clear();

        ss << s;
        while (ss >> tmp) {
            an.push_back(tmp);
        }
        
        sum = 0;
        exp = 1;
        for(int i = 1; i < an.size(); i++, exp *= x) {
            sum += exp * an[an.size() - i - 1] * i;
        }

        cout << sum << endl;
    }

    return 0;
}