#include<iostream>
#include<vector>

using namespace std;

int main() {
    char c;
    int order;
    bool mut = false;
    vector<string> list;
    string s;

    while((c = cin.get()) != EOF) {
        if('0' <= c && c <= '9') {
            if(mut) {
                order = order * 10 + c - '0';
            } else {
                if(c == '0') break;
                mut = true;
                order = c - '0';
            }
        } else {
            if(mut) {
                mut = false;
                cout << list[list.size() - order];
                list.push_back(list[list.size() - order]);
                list.erase(list.end() - order - 1);
            }

            if(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
                s += c; 
            } else {
                cout << s << c;
                if(s != "") list.push_back(s);
                s = "";
            }
        }
    }
    

    return 0;
}