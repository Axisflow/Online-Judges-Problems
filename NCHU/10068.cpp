#include<iostream>

using namespace std;

int month_days(int month, int year) {
    if(month == 2) {
        if(year%4==0 && year%100!=0 || year%400==0) return 29;
        else return 28;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) return 30;
    else return 31;
}

int main() {
    int years, year_final_day, month_final_day;
    while(cin >> years) {
        month_final_day = 0;
        int day_13[7] = {0, 0, 0, 0, 0, 0, 0};
        for(int year = 1900; year < years+1900; year++) {
            for(int month=1; month<=12; month++){
                ++day_13[(month_final_day + 13) % 7];
                month_final_day = (month_final_day + month_days(month, year)) % 7;
            }
        }

        for(int i = 0; i<7; i++) {
            cout << day_13[(i+6)%7] << " ";
        }
        cout << endl;
    }
    
    return 0;
}