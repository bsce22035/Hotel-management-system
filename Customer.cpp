//
// Created by abc1 on 3/19/2023.
//

#include "Customer.h"


void Customer::minordetails() {
    cout<<endl;
    cout<<"\n\n____________________________________________________";
    cout<<"\nName: "<<fname<<" "<<lname;
    cout<<"\ncnic: "<<cnic;
    cout<<"\n______________________________________________________\n\n";
}





void Customer::inputdetails(){          //for inputing on terminal

    cout<<"\n____________________________________________________________________________\n";
   cout<<"\n Dear Customer, Please enter the following details\n";
    cout<<"first name";
    cin>>fname;
    cout<<"last name ";
    cin>>lname;
    cout<<"cnic";
    cin>>cnic;

    int idw;
    string fnamew;
    string lnamew;
    Date datebornw;
    Date checkindatew;
    int cnicw;
    int daysrentedw;
    int rentedroomidw;

    ifstream cus("currentcustomers.txt");
    while(!cus.eof()){

        cus>>idw>>fnamew>>lnamew>>cnicw>>datebornw>>checkindatew>>daysrentedw>>rentedroomidw;
        while(cnicw==cnic){
            cout<<"This cnic already exsist enter again ";
            cin>>cnic;

        }


    }
    cus.close();

    cout<<" data born\n";
    dateborn.inputdate();
    cout<<"\nNum of days to stay ";
    cin>>daysrented;
    while(daysrented<=0){
        cout<<"\nInvalid enter again";
        cin>>daysrented;
    }

    id=++idsetter;
    cout<<"\n please note, your customer id is "<<id<<endl<<endl;
    cout<<"\n___________________________________________________________________________________\n";
}


void Customer::printdetails(){
    cout<<endl;
    cout<<"\n\n____________________________________________________";
    cout<<"\nName: "<<fname<<" "<<lname;
    cout<<"\ncnic: "<<cnic;
    cout<<"\nDataborn: " ;dateborn.printdate();
    cout<<"Check in date :";checkindate.printdate() ;
   cout<<"\nRented Room ID: "<<rentedroomid;
    cout<<"\nDays stay: "<<daysrented;
    cout<<"\n______________________________________________________\n\n";
}

void Customer::printroomid(){
    cout<<"\nRoom Id is "<<id<<endl ;
}


