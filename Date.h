//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_DATE_H
#define HOTEL_MANAGEMENTSYSTEM_DATE_H
#include <iostream>
using namespace std;
struct filecar{
    int num;
    int num2;
    int num3;
};

class Date {
public:
int day;
int month;
int year;



int calculatedays(Date day2);

void printdate();
void inputdate();



   friend Date operator-(Date &one,Date &cardate){
        Date newdate;

        newdate.day=one.day-cardate.day;
        newdate.month=one.month-cardate.month;
        newdate.year=one.year-cardate.year;
        return newdate;

    }


   friend istream& operator>>(istream& inp,Date &da){
        inp>>da.day;
        inp>>da.month;
        inp>>da.year;
        return inp;
    }


   friend ostream& operator<<(ostream& out,Date &da){
        out<<da.day<<' '<<da.month<<' '<<da.year<<' ';

        return out;
    }



};




#endif //HOTEL_MANAGEMENTSYSTEM_DATE_H
