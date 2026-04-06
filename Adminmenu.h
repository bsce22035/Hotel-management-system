

#ifndef HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H
#define HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H

#include "Room.h"
#include <iostream>
#include "itemsdoer.h"

using namespace std;

#include "Complain.h"
#include "Employee.h"
#include "Customer.h"
#include "Bills.h"

#include <fstream>
#include "Item.h"


class Adminmenu {
public:
    Bill bill;
    Employee *emp;
    Room *room;
    Complain *comp;
    Customer *cus;
    itemsdoer<Item>  *fandd;
    void addemp();
void addresturentitem();
    void printallemps();

    void searchanemp();

    void printpastcustomerdetails();

    void avaroomdetails();

    void occuroomdata();

    void print_avilable_room();

    void seealloccurooms();

    void addroom();

    void emptyroom();

    void searchroomforcus();

    void printallpastcustomers();

    void searchcurrentcustomer();

    void printallcurrcus();

    void changepassword();

    void searchpastcustomer();

    void seeGeneralComplain();

    void seeEmpComplain();

    void searchEmpComplain();

    void displaypastbills();

    void displaytotalprofit();
    void removedish();
    void printalldishes();

};


#endif //HOTEL_MANAGEMENTSYSTEM_ADMINMENU_H
