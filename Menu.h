//
// Created by abc1 on 3/23/2023.
//

#ifndef HOTEL_MANAGEMENTSYSTEM_MENU_H
#define HOTEL_MANAGEMENTSYSTEM_MENU_H
#include "Adminmenu.h"
#include "Customer.h"
#include "Room.h"
#include "Checkin.h"
#include "Checkout.h"
#include "itemsdoer.h"
#include "Bills.h"
#include "Item.h"
#include "Date.h"
#include <fstream>
#include <iostream>
using namespace std;

class Menu {
static Menu *instance;
    Checkin ci;
    Date date;
    Checkout co;
    Room room;
    itemsdoer<Item> it;
    Customer cus;
    Employee emp;
    Adminmenu menu;
     Complain comp;
    Menu();

public:
   static Menu* getinstance();


    void addgencomplain();

    void   addempcomplain();
    void getroomidtoknow();
    void checkin();
      void changedayofstay();

    void checkout();

    void getfood();




    void Adminmenu();


    ~Menu();
};


#endif //HOTEL_MANAGEMENTSYSTEM_MENU_H
