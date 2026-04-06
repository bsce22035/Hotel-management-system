//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_ROOM_H
#define HOTEL_MANAGEMENTSYSTEM_ROOM_H
#include <iostream>
#include <fstream>
using namespace std;
#include "Date.h"

class Room {
public:

    int capacity;
static int idsetter;
int id;
int customerid;
Date daterented;
string type;
double dayrate;
     void printminordet();
    void printroomdetails();
    ~Room();


    friend ostream& operator<<(ostream& out,Room& cus){       //for writing to file
        out<<cus.id<<" "<<cus.capacity<<" "<<cus.type<<" "<<cus.dayrate<<" "<<cus.daterented<<" "<<cus.customerid<<endl;
        return  out;

    }


    friend istream& operator>>(istream& inp,Room& cus){     //for reading from file
        inp>>cus.id>>cus.capacity>>cus.type>>cus.dayrate>>cus.daterented>>cus.customerid;
        return inp;
    }

    void setrub(){
        id=0;
    }

};


#endif //HOTEL_MANAGEMENTSYSTEM_ROOM_H
