/*
給你兩個日期，問這兩個日期相差幾天。
*/

#include<iostream>

using namespace std;

typedef struct Date {
    short year;
    short month;
    short day;
} date;

short getYear_days(short year) {
    if(year%4==0 && year%100!=0 || year%400==0) return 366;
    else return 365;
}

short getMonth_days(short year, short month) {
    const short month_days[] = {0, 31, 0, 31, 30, 31, 30 ,31 , 31, 30, 31, 30, 31};
    if(month == 2) {
        if(getYear_days(year) == 366) return 29;
        else return 28;
    }
    else return month_days[month];
}

int minus_date(date& before, date& after) {
    int daysb = 0, daysa = 0;

    for(int m = 1; m < before.month; m++) daysb += getMonth_days(before.year, m);
    daysb += before.day;

    for(int y = before.year; y < after.year; y++) daysa += getYear_days(y);
    for(int m = 1; m < after.month; m++) daysa += getMonth_days(after.year, m);
    daysa += after.day;

    return daysa - daysb;
}

short compare(date x, date y) {
    if(x.year > y.year) return 1;
    else if(x.year < y.year) return -1;
    else {
        if(x.month > y.month) return 1;
        else if(x.month < y.month) return -1;
        else {
            if(x.day > y.day) return 1;
            else if(x.day < y.day) return -1;
            else return 0;
        }
    }
}

int main() {
    short y, m, d, cmp;
    date before, after;
    int diff;
    while(cin >> y >> m >> d) {
        before = {y, m, d};
        cin >> y >> m >> d;
        after = {y, m, d};

        cmp = compare(after, before);
        if(cmp == 1) diff = minus_date(before, after);
        else if(cmp == -1) diff = minus_date(after, before);
        else diff = 0;

        cout << diff << endl;
    }

    return 0;
}