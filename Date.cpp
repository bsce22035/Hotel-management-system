//
// Created by abc1 on 3/27/2023.
//
#include "Date.h"




void Date::printdate(){
    cout<<endl<<day<<"-"<<month<<"-"<<year<<endl;
}

void Date::inputdate(){
    cout<<"enter day";
    cin>>day;
    while(day>30||day<0){
        cout<<"\nInvalid enter again ";
        cin>>day;
    }
    cout<<"month: ";
    cin>>month;
    while(month>12||month<0){
        cout<<"\nInvalid enter again ";
        cin>>month;
    }
    cout<<"year";
    cin>>year;
    while(year<1800||year>2100){
        cout<<"\nEnter valid year";
        cin>>year;
    }
}

