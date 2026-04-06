//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_PEAPLE_H
#define HOTEL_MANAGEMENTSYSTEM_PEAPLE_H
#include <iostream>
#include "Date.h"
using namespace std;


class Peaple {
protected:
    long  cnic;
    Date dateborn;

public:
    string fname;
    string lname;

    void setcnic(int cnic);
    int getcnic();
    void setdateborn(Date &dateborn);
    Date  getdateborn();

};

class Complain;

#endif //HOTEL_MANAGEMENTSYSTEM_PEAPLE_H
