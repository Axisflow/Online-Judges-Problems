/// Only for 2011

#include<stdio.h>

typedef struct Date{
    int month;
    int day;
    int weekday;
    int days;
} date;

int main(){
    const int days_in_months[]={31,28,31,30,31,30,31,31,30,31,30,31};
    const int initial_weekday = 5; //Friday

    int num;
    scanf("%d", &num);

    date dates[num];

    for(int i=0; i<num; i++){
        scanf("%d %d", &dates[i].month, &dates[i].day);

        dates[i].days = dates[i].day;
        for(int j=0;j<dates[i].month-1;j++){
            dates[i].days += days_in_months[j];
        }
        dates[i].weekday = (initial_weekday + dates[i].days) % 7;
    }

    for(int i=0; i<num; i++){
        switch(dates[i].weekday){
            case 0: printf("Sunday"); break;
            case 1: printf("Monday"); break;
            case 2: printf("Tuesday"); break;
            case 3: printf("Wednesday"); break;
            case 4: printf("Thursday"); break;
            case 5: printf("Friday"); break;
            case 6: printf("Saturday"); break;
            default: return printf("Error!");
        }
        printf("\n");
    }
    return 0;
}
