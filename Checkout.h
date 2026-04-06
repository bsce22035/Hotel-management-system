//
// Created by abc1 on 3/19/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H
#define HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H
#include  <iostream>
using namespace std;
#include "Room.h"
#include "Bills.h"
#include "Customer.h"

class Checkout {

public:
    Room *roo;
    Customer *cus;




    void checkout(Date &date);

};


#endif //HOTEL_MANAGEMENTSYSTEM_CHECKOUT_H
