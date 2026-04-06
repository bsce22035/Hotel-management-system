//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_COMPLAIN_H
#define HOTEL_MANAGEMENTSYSTEM_COMPLAIN_H
#include<iostream>
#include "employee.h"
#include "Customer.h"
#include "Room.h"
#include <fstream>
using namespace std;
class Complain {
public:
    Employee* emp;
    Customer* cus;
    Complain(){
        emp=nullptr;
        cus=nullptr;
    }
    Complain(Employee*emp, Customer*cus){
        this->emp = emp;
        this->cus = cus;
    }
    void addComplain();
    void addempComplain();
    void addGeneralComplain();

};


#endif //HOTEL_MANAGEMENTSYSTEM_COMPLAIN_H
