#include<iostream>

using namespace std;

int main() {
    char c;
    bool metQ = false;
    while((c = cin.get()) != EOF) {
        if(c == '"') {
            if(metQ) {
                metQ = false;
                cout << "''";
            }
            else {
                metQ = true;
                cout << "``";
            }
        } else cout << c;
    }
    
    return 0;
}