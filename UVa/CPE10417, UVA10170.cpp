#include<iostream>

using namespace std;

int main(){
    unsigned long long int init_people, targ_day, targ_people, sum_day;
    while(cin >> init_people >> targ_day){
        for(targ_people = init_people, sum_day = 0; sum_day < targ_day; targ_people++){
            sum_day += targ_people;
        }

        cout << targ_people-1 << '\n';
    }

    return 0;
}
