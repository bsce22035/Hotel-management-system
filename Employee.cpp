//
// Created by abc1 on 3/21/2023.
//

#include "Employee.h"

void Employee::input(){
    cout<<"Enter first name ";
    cin>>fname;
    cout<<"Enter last name";
    cin>>lname;
    cout<<"cnic";
    cin>>cnic;
    cout<<"Date born";
    dateborn.inputdate();
}


void Employee::display1(){
    cout<<endl;
    cout<<"First name is: "<<fname<<endl;
    cout<<"Last name  is: "<<lname<<endl;
    cout<<"cnic is: "<<cnic<<endl;
    cout<<"date born: "<<dateborn<<endl;
    cout<<endl;
}
