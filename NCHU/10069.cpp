#include<iostream>

using namespace std;

int main() {
    int perls, max, tmp;
    char right_flag, left_flag;
    string str;
    while(cin >> perls >> str) {
        max = 0;
        for(int span = 0; span < perls; span++) {
            right_flag = 0;
            left_flag = 0;

            //Find Right
            tmp = 0;
            for(int perl = span; tmp < perls; tmp++, perl = (perl+1)%perls) {
                if(right_flag == 0) {
                    if(str[perl] == 'r') right_flag = 'r';
                    else if(str[perl] == 'b') right_flag = 'b';
                } else if(right_flag == 'r') {
                    if(str[perl] == 'r') continue;
                    else if(str[perl] == 'b') break;
                } else if(right_flag == 'b') {
                    if(str[perl] == 'r') break;
                    else if(str[perl] == 'b') continue;
                }
            }

            for(int perl = (span+perls-1)%perls; tmp < perls; tmp++, perl = (perl-1+perls)%perls) {
                if(left_flag == 0) {
                    if(right_flag == 'r') {
                        if(str[perl] == 'r') continue;
                        else if(str[perl] == 'b') left_flag = 'b';
                    } else if(right_flag == 'b') {
                        if(str[perl] == 'r') left_flag = 'r';
                        else if(str[perl] == 'b') continue;
                    }
                } else if(left_flag == 'r') {
                    if(str[perl] == 'r') continue;
                    else if(str[perl] == 'b') break;
                } else if(left_flag == 'b') {
                    if(str[perl] == 'r') break;
                    else if(str[perl] == 'b') continue;
                }
            }

            if(tmp > max) max = tmp;
        }
        
        cout << max << endl;
    }
}