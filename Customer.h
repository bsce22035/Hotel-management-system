//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H
#define HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H
#include "Peaple.h"
#include <fstream>
#include "Date.h"

class Customer:public Peaple {
public:

    Date checkindate;
    int daysrented;
int rentedroomid;



  static   int idsetter;
    int id;




    void inputdetails();
     void minordetails();
    void printdetails();

    void printroomid();

    friend ostream& operator<<(ostream& out,Customer& cus){   //for writing to file
        out<<cus.id<<" "<<cus.fname<<" "<<cus.lname<<" "<<cus.cnic<<" "<<cus.dateborn<<" "<<cus.checkindate<<" ";
        out<<cus.daysrented<<" "<<cus.rentedroomid<<endl;
        return  out;

    }

    friend  istream& operator>>(istream& out,Customer& cus){     //for reading from file
        out>>cus.id>>cus.fname>>cus.lname>>cus.cnic>>cus.dateborn>>cus.checkindate>>cus.daysrented>>cus.rentedroomid;
        return  out;

    }



friend class Complain;
void setrub(){
    id=0;
}

};





#endif //HOTEL_MANAGEMENTSYSTEM_CUSTOMER_H
